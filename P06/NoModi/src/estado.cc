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
 * @brief Implementación de la clase estado
*/

#include "estado.h"

/**
* @brief Constructor por defecto de la clase Estado
*/
Estado::Estado() {
  identificador_ = 0;
  aceptacion_ = false;
  num_transiciones_ = 0;
}

/**
 * @brief Constructor parametrizado de la clase Estado
 * @param identificador: identificador del estado
 * @param aceptacion: booleano que indica si el estado es de acept
 * @param num_transiciones: número de transiciones del estado
*/
Estado::Estado(const int identificador, const bool aceptacion, std::vector<Transicion>& transiciones) {
  identificador_ = identificador;
  aceptacion_ = aceptacion;
  num_transiciones_ = transiciones.size();
  transiciones_ = transiciones;
}

/**
 * @brief Destructor de la clase Estado
*/
Estado::~Estado() {}

/**
 * @brief Devuelve el identificador del estado
 * @return int identificador del estado
*/
int Estado::GetIdentificador() const {
  return identificador_;
}

/**
 * @brief Devuelve si el estado es de aceptación
 * @return bool true si es de aceptación, false en caso contrario
*/
bool Estado::GetAceptacion() const {
  return aceptacion_;
}

/**
 * @brief Devuelve el número de transiciones del estado
 * @return int número de transiciones del estado
*/
int Estado::GetNumTransiciones() const {
  return num_transiciones_;
}

/**
 * @brief Devuelve las transiciones del estado
 * @return std::vector<Transicion> transiciones del estado
*/
std::vector<Transicion> Estado::GetTransiciones() const {
  return transiciones_;
}

/**
 * @brief Establece el identificador del estado
 * @param identificador: identificador del estado
*/
void Estado::SetIdentificador(const int identificador) {
  identificador_ = identificador;
}

/**
 * @brief Establece si el estado es de aceptación
 * @param aceptacion: booleano que indica si el estado es de aceptación
*/
void Estado::SetAceptacion(const bool aceptacion) {
  aceptacion_ = aceptacion;
}

/**
 * @brief Establece el número de transiciones del estado
 * @param num
*/
void Estado::SetNumTransiciones(const int num_transiciones) {
  num_transiciones_ = num_transiciones;
}

/**
 * @brief Establece las transiciones del estado
 * @param transiciones: transiciones del estado
*/
void Estado::SetTransiciones(const std::vector<Transicion>& transiciones) {
  transiciones_ = transiciones;
}