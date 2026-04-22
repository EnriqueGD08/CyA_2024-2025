/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Declaración Clase Cadena
 */

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "alfabeto.h"

class Lenguaje;

class Cadena {
 public:
  Cadena();
  Cadena(const std::string& cadena);
  Cadena(const std::string& cadena, const Alfabeto& alfabeto);
  Cadena(std::istream& is);
  std::string get_cadena() const;
  void set_cadena(const std::string& cadena);
  Alfabeto get_alfabeto() const;
  void set_alfabeto(const Alfabeto& alfabeto);
  Alfabeto alfabeto();
  int longitud();
  Cadena inversa();
  Lenguaje prefijos(std::set<Cadena>& prefijos);
  Lenguaje sufijos(std::set<Cadena>& sufijos);

  void operator=(const Cadena& cadena2);

 private:
  std::string cadena_;
  Alfabeto alfabeto_;
};

bool operator<(const Cadena& cadena1, const Cadena& cadena2);
std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
std::istream& operator>>(std::istream& is, Cadena& cadena);