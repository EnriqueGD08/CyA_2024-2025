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
#include "transicion.h"
typedef char Simbolo;

class Estado {
 public:
  Estado();
  Estado(const int identificador, const bool aceptacion, std::vector<Transicion>& transiciones);
  ~Estado();

  int GetIdentificador() const;
  bool GetAceptacion() const;
  int GetNumTransiciones() const;
  std::vector<Transicion> GetTransiciones() const;

  void SetIdentificador(const int identificador);
  void SetAceptacion(const bool aceptacion);
  void SetNumTransiciones(const int num_transiciones);
  void SetTransiciones(const std::vector<Transicion>& transiciones);

 private:
  int identificador_;
  bool aceptacion_;
  int num_transiciones_;
  std::vector<Transicion> transiciones_;

};