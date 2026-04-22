/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Implementación Clase Cadena
 */

#include "cadena.h"
#include "alfabeto.h"
#include "lenguaje.h"

/**
 * @brief Constructor por defecto de la clase Cadena
 * @return Objeto de la clase Cadena
 */
Cadena::Cadena() {}

/**
 * @brief Constructor parametrizado de la clase Cadena
 * @param cadena Cadena de caracteres
 * @return Objeto de la clase Cadena
 */
Cadena::Cadena(const std::string& cadena) {
  cadena_ = cadena;
}

/**
 * @brief Constructor parametrizado de la clase Cadena
 * @param is Flujo de entrada
 * @return Objeto de la clase Cadena
 */
Cadena::Cadena(std::istream& is) {
  is >> cadena_;
}

/**
 * @brief Constructor parametrizado de la clase Cadena
 * @param cadena Cadena de caracteres
 * @param alfabeto Alfabeto asociado a la cadena
 * @return Objeto de la clase Cadena
 */
Cadena::Cadena(const std::string& cadena, const Alfabeto& alfabeto) {
  cadena_ = cadena;
  if (alfabeto.get_alfabeto().size() == 0) {
    alfabeto_.set_alfabeto(cadena);
  } else {
    alfabeto_ = alfabeto;
  }
}

/**
 * @brief Método que devuelve la cadena
 * @return Cadena de caracteres
 */
std::string Cadena::get_cadena() const {
  return cadena_;
}

/**
 * @brief Método que establece la cadena
 * @param cadena Cadena de caracteres
 */
void Cadena::set_cadena(const std::string& cadena) {
  cadena_ = cadena;
}

/**
 * @brief Método que devuelve el alfabeto asociado a la cadena
 * @return Alfabeto asociado a la cadena
 */
Alfabeto Cadena::get_alfabeto() const {
  return alfabeto_;
}

/**
 * @brief Método que establece el alfabeto asociado a la cadena
 * @param alfabeto Alfabeto asociado a la cadena
 */
void Cadena::set_alfabeto(const Alfabeto& alfabeto) {
  alfabeto_ = alfabeto;
}

/**
 * @brief Método que devuelve el alfabeto asociado a la cadena
 * @return Alfabeto asociado a la cadena
 */
Alfabeto Cadena::alfabeto() {
  Alfabeto alfabeto;
  alfabeto.set_alfabeto(cadena_);
  return alfabeto;
}

/**
 * @brief Método que devuelve la longitud de la cadena
 * @return Longitud de la cadena
 */
int Cadena::longitud() {
  return cadena_.size();
}

/**
 * @brief Método que devuelve la cadena inversa
 * @return Cadena inversa
 */
Cadena Cadena::inversa() {
  std::string inversa;
  for (int i = cadena_.size() - 1; i >= 0; i--) {
    inversa += cadena_[i];
  }
  return Cadena(inversa);
}

/**
 * @brief Método que devuelve los prefijos de la cadena
 * @param prefijos Conjunto de prefijos de la cadena
 */
Lenguaje Cadena::prefijos(std::set<Cadena>& prefijos) {
  std::string prefijo;
  prefijos.insert(Cadena("&"));
  for (int i = 0; i < cadena_.size(); i++) {
    prefijo += cadena_[i];
    prefijos.insert(Cadena(prefijo));
  }
  return Lenguaje(prefijos);
}

/**
 * @brief Método que devuelve los sufijos de la cadena
 * @param sufijos Conjunto de sufijos de la cadena
 */
Lenguaje Cadena::sufijos(std::set<Cadena>& sufijos) {
  std::string sufijo;
  sufijos.insert(Cadena("&"));
  for (int i = cadena_.size() - 1; i >= 0; i--) {
    sufijo = cadena_[i] + sufijo;
    sufijos.insert(Cadena(sufijo));
  }
  return Lenguaje(sufijos);
}

/**
 * @brief Sobrecarga del operador =
 * @param cadena2 Cadena a igualar
 */
void Cadena::operator=(const Cadena& cadena2) {
  cadena_ = cadena2.get_cadena();
}

/**
 * @brief Sobrecarga del operador <
 * @param cadena1 Cadena a comparar
 * @param cadena2 Cadena a comparar
 * @return true si cadena1 es menor que cadena2, false en caso contrario
 */
bool operator<(const Cadena& cadena1, const Cadena& cadena2) {
  return cadena1.get_cadena() < cadena2.get_cadena();
}

/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param cadena Cadena a imprimir
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.get_cadena();
  return os;
}

/**
 * @brief Sobrecarga del operador >>
 * @param is Flujo de entrada
 * @param cadena Cadena a leer
 * @return Flujo de entrada
 */
std::istream& operator>>(std::istream& is, Cadena& cadena) {
  std::string cadena_str;
  is >> cadena_str;
  cadena.set_cadena(cadena_str);
  return is;
}