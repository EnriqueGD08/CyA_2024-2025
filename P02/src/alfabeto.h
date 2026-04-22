/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Declaración Clase Alfabeto
 */

#pragma once

#include <iostream>
#include <set>
#include <string>
#include <fstream>

typedef char Simbolo;

class Alfabeto {
 public:
  Alfabeto();
  Alfabeto(const std::string& alfabeto);
  const std::set<Simbolo>& get_alfabeto() const;
  void set_alfabeto(const std::string& alfabeto);

 private:
  std::set<Simbolo> alfabeto_;

};

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);
std::istream& operator>>(std::istream& is, const std::string& alfabeto);