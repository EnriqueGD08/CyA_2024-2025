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
 * @brief Declaracion de la clase point_set
*/

#pragma once

#include "datos.h"
#include "sub_tree.h"
#include <vector>

class point_set : public CyA::point_vector {
 public:
  point_set(const CyA::point_vector& points);
  ~point_set();

  const CyA::tree& get_tree(void) const { return emst_; }
  const CyA::point_vector& get_points(void) const { return *this; }
  const double get_cost(void) const { return compute_cost(); }

  void EMST();
  void write_tree(std::ostream& os) const;

 private:
  void compute_arc_vector(CyA::arc_vector& av) const;
  void find_incident_subtrees(const EMST::sub_tree_vector& st, const CyA::arc& a, int& i, int& j) const;
  void merge_subtrees(EMST::sub_tree_vector& st, const CyA::arc& a, int i, int j) const;
  double compute_cost() const;
  double euclidean_distance(const CyA::arc& a) const;
  CyA::tree emst_;
};