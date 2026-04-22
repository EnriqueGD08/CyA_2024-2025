/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 08/10/2024
 * @brief implementación de la clase variable
*/

#include "variable.h"

const std::regex kInt("\\s*int.*");
const std::regex kDouble("\\s*double.*");
const std::regex kName("[*a-zA-Z0-9_-]+");
const std::regex kValue("-?[0-9.]+");
const std::string kSpace(" ");

/**
 * @brief Constructor de la clase Variable
 * @param linea Número de línea
 * @param tipo Tipo de variable
*/
Variable::Variable(const int linea, const std::string& tipo) {
  linea_ = linea;
  std::string aux = tipo;
  if (std::regex_search(tipo, kInt)) { 
    tipo_ = "int"; 
    int pos = tipo.find("int");
    aux = tipo.substr(pos + 3);
  }
  else if (std::regex_search(tipo, kDouble)) { 
    tipo_ = "double"; 
    int pos = tipo.find("double" + 6);
    aux = tipo.substr(pos);
    }

  if(aux.find(kSpace) < aux.size()) {
    std::smatch nombre;
    std::regex_search(aux, nombre, kName);
    nombre_ = nombre.str();

    if(aux.find("=") < aux.size() && std::regex_search(aux, kValue) == true) {
      asignar_valor_ = true;
      std::smatch valor;
      std::regex_search(aux, valor, kValue);
      valor_ = valor.str();
    } else {
      asignar_valor_ = false;
    }
  }
}

/**
 * @brief Método que devuelve el número de línea
 * @return Número de línea
*/
int Variable::GetLine() const {
  return linea_;
}

/**
 * @brief Método que devuelve el tipo de variable
 * @return Tipo de variable
*/
std::string Variable::GetTipo() const {
  return tipo_;
}

/**
 * @brief Método que devuelve el nombre de la variable
 * @return Nombre de la variable
*/
std::string Variable::GetNombre() const {
  return nombre_;
}

/**
 * @brief Método que devuelve si se le asigna un valor a la variable
 * @return Booleano que indica si se le asigna un valor a la variable
*/
bool Variable::GetAsignarValor() const {
  return asignar_valor_;
}

/**
 * @brief Método que devuelve el valor de la variable
 * @return Valor de la variable
*/
std::string Variable::GetValor() const {
  if (asignar_valor_ == true) {
    return valor_;
  }
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Stream de salida
 * @param variable Variable a imprimir
 * @return Stream de salida
*/
std::ostream& operator<<(std::ostream& os, const Variable& variable) {
  return os << variable.GetNombre();
}