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
 * @brief Declaración de la clase gramatica
*/

#pragma once

#include <iostream>
#include "alfabeto.h"
#include "noterminales.h"
#include "produccion.h"

class Gramatica {
 public:
  Gramatica();
  Gramatica(Alfabeto& alfabeto, std::set<Noterminal> no_terminales, std::vector<Produccion> producciones);
  Gramatica(std::ifstream& fichero);

  const Alfabeto& GetAlfabeto() const;
  const std::set<Noterminal>& GetNoTerminales() const;
  const std::vector<Produccion>& GetProducciones() const;

  void SetAlfabeto(const Alfabeto& alfabeto);
  void SetNoTerminales(const std::set<Noterminal>& no_terminales);
  void SetProducciones(const std::vector<Produccion>& producciones);

  Gramatica PasarFNC();

 private:
  Alfabeto alfabeto_;
  std::set<Noterminal> no_terminales_;
  std::vector<Produccion> producciones_;
  void ComprobarNoTerminales(const std::string& no_terminal);
  void ComprobarProducciones(std::string& parte1, std::string& parte2);
};

std::ostream& operator<<(std::ostream& os, const Gramatica& gramatica);