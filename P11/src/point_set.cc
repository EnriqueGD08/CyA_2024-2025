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
 * @brief Implementación de la clase point_set
*/

#include "point_set.h"
#include <cmath>
#include <algorithm>

/**
 * @brief Constructor de la clase point_set
 * @param points vector de puntos
*/
point_set::point_set(const CyA::point_vector& points) : CyA::point_vector(points) {}

/**
 * @brief Destructor de la clase point_set
*/
point_set::~point_set() {}

/**
 * @brief Calcula el vector de arcos
 * @param av vector de arcos
*/
void point_set::compute_arc_vector(CyA::arc_vector& av) const {
  av.clear();
  const int n = size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double distancia = euclidean_distance(std::make_pair((*this)[i], (*this)[j]));
      av.emplace_back(distancia, std::make_pair((*this)[i], (*this)[j]));
    }
  }
  std::sort(av.begin(), av.end());
}

/**
 * @brief Calcula la distancia euclidea entre dos puntos
 * @param a arco
 * @return distancia euclidea
*/
double point_set::euclidean_distance(const CyA::arc& a) const {
  double dx = a.first.first - a.second.first;
  double dy = a.first.second - a.second.second;
  return std::sqrt(dx * dx + dy * dy);
}

/**
 * @brief Calcula el árbol generador mínimo
*/
void point_set::EMST() {
  CyA::arc_vector av;
  compute_arc_vector(av);

  EMST::sub_tree_vector st;
  for (const auto& p : *this) {
    EMST::sub_tree s;
    s.add_point(p);
    st.push_back(s);
  }

  for (const auto& a : av) {
    int i, j;
    find_incident_subtrees(st, a.second, i, j);
    if (i != j) {
      merge_subtrees(st, a.second, i, j);
    }
  }

  emst_ = st[0].get_arcs();
}

/**
 * @brief Busca los subárboles incidentes
 * @param st vector de subárboles
 * @param a arco
 * @param i índice del primer subárbol
 * @param j índice del segundo subárbol
*/
void point_set::find_incident_subtrees(const EMST::sub_tree_vector& st, const CyA::arc& a, int& i, int& j) const {
  i = j = -1;
  for (size_t k = 0; k < st.size(); ++k) {
    if (st[k].contains(a.first)) i = k;
    if (st[k].contains(a.second)) j = k;
    if (i != -1 && j != -1) break;
  }
}

/**
 * @brief Fusiona dos subárboles
 * @param st vector de subárboles
 * @param a arco
 * @param i índice del primer subárbol
 * @param j índice del segundo subárbol
*/
void point_set::merge_subtrees(EMST::sub_tree_vector& st, const CyA::arc& a, int i, int j) const {
  st[i].merge(st[j], std::make_pair(euclidean_distance(a), a));
  st.erase(st.begin() + j);
}

/**
 * @brief Calcula el coste del árbol generador mínimo
 * @return coste
*/
double point_set::compute_cost() const {
  double cost = 0;
  for (const auto& arc : emst_) {
    cost += euclidean_distance(arc);
  }
  return cost;
}

/**
 * @brief Escribe el árbol generador mínimo en un flujo de salida
 * @param os flujo de salida
*/
void point_set::write_tree(std::ostream& os) const {
  for (const auto& arc : emst_) {
    os << "(" << arc.first.first << ", " << arc.first.second << ") - " << "(" << arc.second.first << ", " << arc.second.second << ')' << std::endl;
  }
    os << std::endl << compute_cost() << std::endl;
}