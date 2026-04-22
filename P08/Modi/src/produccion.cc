/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 05/11/2024
 * @brief Implementacion de la clase produccion
*/

#include "produccion.h"

Produccion::Produccion() {}

Produccion::Produccion(const std::string& parte1, const std::string& parte2) {
  parte1_ = parte1;
  parte2_ = parte2;
}

const std::string& Produccion::GetParte1() const {
  return parte1_;
}

const std::string& Produccion::GetParte2() const {
  return parte2_;
}

void Produccion::SetParte1(const std::string& parte1) {
  parte1_ = parte1;
}

void Produccion::SetParte2(const std::string& parte2) {
  parte2_ = parte2;
}

std::ostream& operator<<(std::ostream& os, const Produccion& produccion) {
  os << produccion.GetParte1() << " -> " << produccion.GetParte2();
  return os;
}