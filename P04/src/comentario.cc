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
 * @brief Implementación de la clase comentario
*/

#include "comentario.h"

/**
 * @brief Constructor de la clase Comentario
 * @param principio Número de línea de inicio
 * @param final Número de línea de fin
*/
Comentario::Comentario(const int principio, const int final) {
  principio_ = principio;
  final_ = final;
  if (principio == 1) {
    contenido_ = "Comentario de cabecera";
  } else {
    contenido_ = "Comentario";
  }
}

/**
 * @brief Constructor de la clase Comentario
 * @param linea Número de línea
 * @param comentario Contenido del comentario
*/
Comentario::Comentario(const int linea, const std::string& comentario) {
  principio_ = linea;
  final_ = linea;
  contenido_ = comentario;
}

/**
 * @brief Método que devuelve el contenido del comentario
 * @return Contenido del comentario
*/
std::string Comentario::GetContenido() const {
  return contenido_;
}

/**
 * @brief Método que devuelve el número de línea de inicio
 * @return Número de línea de inicio
*/
int Comentario::GetPrincipio() const {
  return principio_;
}

/**
 * @brief Método que devuelve el número de línea de fin
 * @return Número de línea de fin
*/
int Comentario::GetFinal() const {
  return final_;
}

/**
 * @brief Método que devuelve el contenido del comentario
 * @return Contenido del comentario
*/
std::string Comentario::GetComentario() const {
  return contenido_;
}

/**
 * @brief Sobrecarga del operador <<
 * @param os Flujo de salida
 * @param comentario Comentario a imprimir
 * @return Flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const Comentario& comentario) {
  os << comentario.GetContenido();
  return os;
}