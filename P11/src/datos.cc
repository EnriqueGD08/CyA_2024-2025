/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 10/12/2024
 * @brief Implementación de la sobrecarga de operadores de los datos
*/

#include "datos.h"

#include <iomanip>

/**
 * @brief Sobrecarga del operador de salida para un vector de puntos
 * @param os flujo de salida
 * @param ps vector de puntos
 * @return flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << std::endl;
  for (const CyA::point &p : ps) {
    os << p << std::endl;
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de salida para un punto
 * @param os flujo de salida
 * @param p punto
 * @return flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;
  return os;
}

/**
 * @brief Sobrecarga del operador de entrada para un vector de puntos
 * @param is flujo de entrada
 * @param ps vector de puntos
 * @return flujo de entrada
*/
std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
  int n;
  is >> n;
  ps.clear();

  for (int i = 0; i < n; ++i)
  {
    CyA::point p;
    is >> p;

    ps.push_back(p);
  }

  return is;
}

/**
 * @brief Sobrecarga del operador de entrada para un punto
 * @param is flujo de entrada
 * @param p punto
 * @return flujo de entrada
*/
std::istream& operator>>(std::istream& is, CyA::point& p) {
  is >> p.first >> p.second;

  return is;
}