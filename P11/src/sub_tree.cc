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
 * @brief Implementacion de la clase sub_tree
*/

#include <iomanip>
#include <cmath>

#include <algorithm>
#include <utility>

#include "sub_tree.h"

namespace EMST
{
  /**
   * @brief Constructor de la clase sub_tree
  */
  sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {}

  /**
   * @brief Destructor de la clase sub_tree
  */
  sub_tree::~sub_tree(void) {}

  /**
   * @brief Añade un arco al subárbol
   * @param a arco
  */
  void sub_tree::add_arc(const CyA::arc &a) {
    arcs_.push_back(a);

    points_.insert(a.first);
    points_.insert(a.second);
  }

  /**
   * @brief Añade un punto al subárbol
   * @param p punto
  */
  void sub_tree::add_point(const CyA::point &p) {
    points_.insert(p);
  }

  /**
   * @brief Comprueba si un punto está en el subárbol
   * @param p punto
   * @return true si el punto está en el subárbol, false en caso contrario
  */
  bool sub_tree::contains(const CyA::point &p) const {
    return points_.find(p) != points_.end();
  }

  /**
   * @brief Fusiona dos subárboles
   * @param st subárbol a fusionar
   * @param a arco
  */
  void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
    arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
    arcs_.push_back(a.second);

    points_.insert(st.points_.begin(), st.points_.end());

    cost_ += a.first + st.get_cost();
  }
}