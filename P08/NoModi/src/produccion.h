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
 * @brief Declaración de la clase produccion
*/

#pragma once

#include <iostream>

class Produccion {
 public:
  Produccion();
  Produccion(const std::string& parte1, const std::string& parte2);

  const std::string& GetParte1() const;
  const std::string& GetParte2() const;
  void SetParte1(const std::string& parte1);
  void SetParte2(const std::string& parte2);

 private:
  std::string parte1_;
  std::string parte2_;
};

std::ostream& operator<<(std::ostream& os, const Produccion& produccion);