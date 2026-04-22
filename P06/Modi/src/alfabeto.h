/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 22/10/2024
 * @brief Declaración de la clase Alfabeto
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
  Alfabeto(const char alfabeto);
  Alfabeto(const std::string& alfabeto);
  ~Alfabeto();

  const std::set<Simbolo>& GetAlfabeto() const;
  void InsertAlfabeto(const char alfabeto);

 private:
  std::set<Simbolo> alfabeto_;

};

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);
std::istream& operator>>(std::istream& is, Alfabeto& alfabeto);