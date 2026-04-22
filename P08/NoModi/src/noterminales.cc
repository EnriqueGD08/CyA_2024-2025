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
 * @brief Implementación de la clase noterminales
*/

#include "noterminales.h"

/**
 * @brief Constructor por defecto de la clase Noterminal
 * @return Objeto de la clase Noterminal
*/
Noterminal::Noterminal() {
  no_terminal = "";
}

/**
 * @brief Constructor parametrizado de la clase Noterminal
 * @param noTerminal Símbolo no terminal
 * @return Objeto de la clase Noterminal
*/
Noterminal::Noterminal(const std::string& noTerminal) {
  no_terminal = noTerminal;
}

/**
 * @brief Método que devuelve el símbolo no terminal
 * @return Símbolo no terminal
*/
const std::string& Noterminal::GetNoTerminal() const {
  return no_terminal;
}

/**
 * @brief Método que establece el símbolo no terminal
 * @param noTerminal Símbolo no terminal
*/
void Noterminal::SetNoTerminal(const std::string& noTerminal) {
  no_terminal = noTerminal;
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Flujo de salida
 * @param noTerminal Símbolo no terminal
 * @return Flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const Noterminal& noTerminal) {
  os << noTerminal.GetNoTerminal();
  return os;
}

/**
 * @brief Sobrecarga del operador de comparación
 * @param no_terminal_1 Símbolo no terminal 1
 * @param no_terminal_2 Símbolo no terminal 2
 * @return True si los símbolos no terminales son iguales, false en caso contrario
*/
bool operator==(const Noterminal& no_terminal_1, const Noterminal& no_terminal_2) {
  return no_terminal_1.GetNoTerminal() == no_terminal_2.GetNoTerminal();
}

bool operator<(const Noterminal& no_terminal_1, const Noterminal& no_terminal_2) {
  return no_terminal_1.GetNoTerminal() < no_terminal_2.GetNoTerminal();
}