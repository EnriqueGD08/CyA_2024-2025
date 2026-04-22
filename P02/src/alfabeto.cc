/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Implementación Clase Alfabeto
 */

#include "alfabeto.h"

/**
 * @brief Constructor por defecto de la clase Alfabeto
 * @return Objeto de la clase Alfabeto
 */
Alfabeto::Alfabeto() {}

/**
 * @brief Constructor parametrizado de la clase Alfabeto
 * @param alfabeto Conjunto de símbolos que forman el alfabeto
 * @return Objeto de la clase Alfabeto
 */
Alfabeto::Alfabeto(const std::string& alfabeto) {
  for (int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.insert(alfabeto[i]);
  }
}

/**
 * @brief Método que devuelve el alfabeto
 * @return Conjunto de símbolos que forman el alfabeto
 */
const std::set<char>& Alfabeto::get_alfabeto() const {
  return alfabeto_;
}

/**
 * @brief Método que establece el alfabeto
 * @param alfabeto Conjunto de símbolos que forman el alfabeto
 */
void Alfabeto::set_alfabeto(const std::string& alfabeto) {
  for (int i = 0; i < alfabeto.size(); i++) {
    alfabeto_.insert(alfabeto[i]);
  }
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param alfabeto Alfabeto a mostrar
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  std::set<Simbolo>::iterator it = alfabeto.get_alfabeto().begin();
  for (int i = 0; i < (alfabeto.get_alfabeto().size() - 1); i++) {
    os << Simbolo(*it) << ", ";
    it++;
  }
  os << Simbolo(*it);
  os << "}";
  return os;
}

/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param alfabeto Alfabeto a leer
 * @return Flujo de entrada
 */
std::istream& operator>>(std::istream& is, const std::string& alfabeto) {
  is >> alfabeto;
  return is;
}