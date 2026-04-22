/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 22/10/2024
 * @brief implementación de clase FA
*/

#include "fa.h"

/**
 * @brief Constructor por defecto de la clase FA
 * @return Objeto de la clase FA
*/
FA::FA() {}

/**
 * @brief Constructor parametrizado de la clase FA
 * @param alfabeto Alfabeto del autómata
 * @param num_estados Número de estados del autómata
 * @param estado_inicial Estado inicial del autómata
 * @param estados Vector de estados del autómata
 * @return Objeto de la clase FA
*/
FA::FA(const Alfabeto& alfabeto, const int num_estados, const int estado_inicial,
       const std::vector<Estado>& estados) {
  alfabeto_ = alfabeto;
  num_estados_ = num_estados;
  estado_inicial_ = estados[estado_inicial];
  estados_ = estados;
}

/**
 * @brief Destructor de la clase FA
*/
FA::~FA() {}

/**
 * @brief Método que devuelve el alfabeto del autómata
 * @return Alfabeto del autómata
*/
Alfabeto FA::GetAlfabeto() const {
  return alfabeto_;
}

/**
 * @brief Método que devuelve el número de estados del autómata
 * @return Número de estados del autómata
*/
int FA::GetNumEstados() const {
  return num_estados_;
}

/**
 * @brief Método que devuelve el estado inicial del autómata
 * @return Estado inicial del autómata
*/
Estado FA::GetEstadoInicial() const {
  return estado_inicial_;
}

/**
 * @brief Método que devuelve el vector de estados del autómata
 * @return Vector de estados del autómata
*/
std::vector<Estado> FA::GetEstados() const {
  return estados_;
}

/**
 * @brief Método que establece el alfabeto del autómata
 * @param alfabeto Alfabeto del autómata
*/
void FA::SetAlfabeto(const Alfabeto& alfabeto) {
  alfabeto_ = alfabeto;
}

/**
 * @brief Método que establece el número de estados del autómata
 * @param num_estados Número de estados del autómata
*/
void FA::SetNumEstados(const int num_estados) {
  num_estados_ = num_estados;
}

/**
 * @brief Método que establece el estado inicial del autómata
 * @param estado_inicial Estado inicial del autómata
*/
void FA::SetEstadoInicial(Estado& estado_inicial) {
  estado_inicial_ = estado_inicial;
}

/**
 * @brief Método que establece el vector de estados del autómata
 * @param estados Vector de estados del autómata
*/
void FA::SetEstados(const std::vector<Estado>& estados) {
  estados_ = estados;
}

/**
 * @brief Método que inserta un estado en el vector de estados del autómata
 * @param estado Estado a insertar
*/
void FA::InsertEstado(const Estado& estado) {
  for (int i = 0; i < estados_.size(); i++) {
    if (estados_[i].GetIdentificador() == estado.GetIdentificador()) {
      return;
    }
  }
  estados_.push_back(estado);
}

/**
 * @brief Método que comprueba si una cadena pertenece al lenguaje del autómata
 * @param cadena Cadena a comprobar
 * @return True si la cadena pertenece al lenguaje, false en caso contrario
*/
bool FA::ComprobarCadena(Cadena& cadena) {
  if (cadena.GetCadena()[0] == '&') {
    return true;
  }
  for (int i = 0; i < cadena.GetCadena().size(); i++) {
    if (alfabeto_.GetAlfabeto().find(cadena.GetCadena()[i]) == alfabeto_.GetAlfabeto().end()) {
      std::cout << "La cadena " << cadena.GetCadena() << " contiene el simbolo "<< cadena.GetCadena()[i] << " que no pertenece al alfabeto    ";
      return false;
    }
  }
  return true;
}

/**
 * @brief Método que comprueba si una cadena pertenece al lenguaje del autómata
 * @param cadena Cadena a comprobar
 * @return True si la cadena pertenece al lenguaje, false en caso contrario
*/
bool FA::CadenaLenguaje(Cadena& cadena) {
  if (ComprobarCadena(cadena)) {
    Estado estado_actual = estado_inicial_;
    if (cadena.GetCadena()[0] == '&') {
      std::vector<Estado> epsilon_clausura = EpsilonClausura(estado_actual);
      return EstadoAceptacion(epsilon_clausura);
    } else {
      return FuncionTransicion(estado_actual, cadena);
    }
  } else {
    return false;
  }
}

/**
 * @brief Método que realiza la función de transición del autómata
 * @param estado_actual Estado actual del autómata
 * @param cadena Cadena a comprobar
 * @return True si la cadena pertenece al lenguaje, false en caso contrario
*/
bool FA::FuncionTransicion(Estado& estado_actual, Cadena& cadena) {
  if (cadena.GetCadena().size() == 0) {
    std::vector<Estado> epsilon_clausura = EpsilonClausura(estado_actual);
    return EstadoAceptacion(epsilon_clausura);
  }
  bool aceptacion = false;
  for (int i = 0; i < estado_actual.GetTransiciones().size(); i++) {
    if (estado_actual.GetTransiciones()[i].GetSimbolo() == cadena.GetCadena()[0] || estado_actual.GetTransiciones()[i].GetSimbolo() == '&') {
      Cadena auxiliar = cadena;
      std::vector<Simbolo> cadena_auxiliar = auxiliar.GetCadena();
      cadena_auxiliar.erase(cadena_auxiliar.begin());
      auxiliar.SetCadena(cadena_auxiliar);
      aceptacion = FuncionTransicion(estados_[estado_actual.GetTransiciones()[i].GetEstadoDestino()], auxiliar);
      if (aceptacion) {return aceptacion;}
    }
  }
  return aceptacion;
}

/**
 * @brief Método que realiza la epsilon clausura de un estado
 * @param estado_actual Estado actual del autómata
 * @return Vector de estados que forman la epsilon clausura
*/
std::vector<Estado> FA::EpsilonClausura(Estado& estado_actual) {
  std::vector<Estado> epsilon_clausura;
  epsilon_clausura.push_back(estado_actual);
  for (int i = 0; i < estado_actual.GetTransiciones().size(); i++) {
    if (estado_actual.GetTransiciones()[i].GetSimbolo() == '&') {
      epsilon_clausura.push_back(estados_[estado_actual.GetTransiciones()[i].GetEstadoDestino()]);
    }
  }
  return epsilon_clausura;
}

/**
 * @brief Método que comprueba si un estado es de aceptación
 * @param estados Vector de estados a comprobar
 * @return True si alguno de los estados es de aceptación, false en caso contrario
*/
bool FA::EstadoAceptacion(std::vector<Estado>& estados) {
  for (int i = 0; i < estados.size(); i++) {
    if (estados[i].GetAceptacion()) {
      return true;
    }
  }
  return false;
}
