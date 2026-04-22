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
 * @brief Implementación de clase bucle
*/

#include "bucle.h"

const std::regex kFor("for\\s*?(.+)");
const std::regex kWhile("while\\s*?(.+)");

/**
 * @brief Constructor de la clase Bucle
 * @param line Número de línea
 * @param tipo Tipo de bucle
*/
Bucle::Bucle(const int line, const std::string& tipo) {
  linea_ = line;
  if (std::regex_search(tipo, kFor)) { tipo_ = "for"; }
  else if (std::regex_search(tipo, kWhile)) { tipo_ = "while"; }
}

/**
 * @brief Método que devuelve el número de línea
 * @return Número de línea
*/
int Bucle::GetLine() const {
  return linea_;
}

/**
 * @brief Método que devuelve el tipo de bucle
 * @return Tipo de bucle
*/
std::string Bucle::GetTipo() const {
  return tipo_;
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Stream de salida
 * @param bucle Bucle a imprimir
 * @return Stream de salida
*/
std::ostream& operator<<(std::ostream& os, const Bucle& bucle) {
  os << bucle.GetLine();
  return os;
}