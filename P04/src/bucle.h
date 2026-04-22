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
 * @brief Declareción de clase bucle
*/

#pragma once

#include <iostream>
#include <regex>

class Bucle {
 public:
  Bucle(const int line, const std::string& tipo);
  Bucle() {}

  int GetLine() const;
  std::string GetTipo() const;

 private:
  std::string tipo_;
  int linea_;
};

std::ostream& operator<<(std::ostream& os, const Bucle& bucle);