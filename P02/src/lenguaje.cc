/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Implementación Clase Lenguaje
 */

#include "lenguaje.h"
#include "cadena.h"

/** 
 * @brief Constructor por defecto de la clase Lenguaje 
 */
Lenguaje::Lenguaje() {}

/**  
 * @brief Constructor parametrizado de la clase Lenguaje
 * @param lenguaje Conjunto de cadenas que forman el lenguaje
 * @return Objeto de la clase Lenguaje
 */
Lenguaje::Lenguaje(std::set<Cadena>& lenguaje) {
  lenguaje_ = lenguaje;
}

/**
 * @brief Método que devuelve el lenguaje
 * @return Conjunto de cadenas que forman el lenguaje
 */
std::set<Cadena>& Lenguaje::get_lenguaje() {
  return lenguaje_;
}

/**
 * @brief Método que establece el lenguaje
 * @param lenguaje Conjunto de cadenas que forman el lenguaje
 */
void Lenguaje::set_lenguaje(const std::set<Cadena>& lenguaje) {
  lenguaje_ = lenguaje;
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param lenguaje Objeto de la clase Lenguaje
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& os, Lenguaje& lenguaje) {
  std::set<Cadena>::iterator it = lenguaje.get_lenguaje().begin();
  os << "{ ";
  for (int i = 0; i < lenguaje.get_lenguaje().size() - 1; i++) {
    os << *it << ", ";
    it++;
  }
  os << *it << " }";
  return os;
}