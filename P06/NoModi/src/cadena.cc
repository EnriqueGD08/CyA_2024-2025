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

/**
 * @brief Constructor por defecto de la clase Cadena
*/
Cadena::Cadena() {}

/**
 * @brief Constructor parametrizado de la clase Cadena
 * @param cadena Cadena de símbolos
*/
Cadena::Cadena(const std::string cadena) {
  for (int i = 0; i < cadena.size(); i++) {
    cadena_.push_back(cadena[i]);
  }
}

/**
 * @brief Constructor parametrizado de la clase Cadena
 * @param cadena Cadena de símbolos
*/
Cadena::Cadena(const std::vector<Simbolo> cadena) {
  cadena_ = cadena;
}

/**
 * @brief Destructor de la clase Cadena
*/
Cadena::~Cadena() {}

/**
 * @brief Método que devuelve la cadena de símbolos
 * @return Vector de símbolos
*/
std::vector<Simbolo> Cadena::GetCadena() const {
  return cadena_;
}

/**
 * @brief Método que establece la cadena de símbolos
 * @param cadena Cadena de símbolos
*/
void Cadena::SetCadena(const std::string cadena) {
  cadena_.clear();
  for (int i = 0; i < cadena.size(); i++) {
    cadena_.push_back(cadena[i]);
  }
}

void Cadena::SetCadena(const std::vector<Simbolo> cadena) {
  cadena_ = cadena;
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param cadena Cadena a mostrar
 * @return Flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  for (int i = 0; i < cadena.GetCadena().size(); i++) {
    os << cadena.GetCadena()[i];
  }
  return os;
}
