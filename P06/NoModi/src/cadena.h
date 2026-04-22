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
 * @brief Declaración de la clase estado
*/

#pragma once

#include <vector>
#include "alfabeto.h"

class Cadena {
 public:
  Cadena();
  Cadena(const std::string cadena);
  Cadena(const std::vector<Simbolo> cadena);
  ~Cadena();

  std::vector<Simbolo> GetCadena() const;
  void SetCadena(const std::string cadena);
  void SetCadena(const std::vector<Simbolo> cadena);

 private:
  std::vector<Simbolo> cadena_;
};

std::ostream& operator<<(std::ostream& os, const Cadena& cadena);