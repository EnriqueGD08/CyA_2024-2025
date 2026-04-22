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
 * @brief declaración de la clase variable
*/

#pragma once

#include <iostream>
#include <regex>

class Variable {
 public:
  Variable(const int linea, const std::string& tipo);
  int GetLine() const;
  std::string GetTipo() const;
  std::string GetNombre() const;
  bool GetAsignarValor() const;
  std::string GetValor() const;

 private:
  int linea_;
  std::string tipo_;
  std::string nombre_;
  bool asignar_valor_;
  std::string valor_;
};

std::ostream& operator<<(std::ostream& os, const Variable& variable);