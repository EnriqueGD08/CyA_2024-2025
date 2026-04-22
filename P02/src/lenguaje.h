/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Declaración Clase Lenguaje
 */

#pragma once

#include <iostream>
#include <set>

class Cadena;

class Lenguaje {
 public:
  Lenguaje();
  Lenguaje(std::set<Cadena>& lenguaje);
  std::set<Cadena>& get_lenguaje();
  void set_lenguaje(const std::set<Cadena>& lenguaje);

 private:
  std::set<Cadena> lenguaje_;
};

std::ostream& operator<<(std::ostream& os, Lenguaje& lenguaje);