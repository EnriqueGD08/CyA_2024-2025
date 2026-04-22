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
 * @brief Definición de la clase noterminales
*/

#pragma once

#include <iostream>

class Noterminal {
 public:
  Noterminal();
  Noterminal(const std::string& noTerminal);

  const std::string& GetNoTerminal() const;
  void SetNoTerminal(const std::string& noTerminal);

 private:
  std::string no_terminal;
};

std::ostream& operator<<(std::ostream& os, const Noterminal& noTerminal);
bool operator==(const Noterminal& no_terminal_1, const Noterminal& no_terminal_2);
bool operator<(const Noterminal& no_terminal_1, const Noterminal& no_terminal_2);