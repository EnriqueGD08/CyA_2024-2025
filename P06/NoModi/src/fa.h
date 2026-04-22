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
 * @brief Declaración de clase FA
*/

#pragma once

#include "cadena.h"
#include "estado.h"

class FA {
 public:    
  FA();
  FA(const Alfabeto& alfabeto, const int num_estados, const int estado_inicial,
     const std::vector<Estado>& estados);
  ~FA();

  Alfabeto GetAlfabeto() const;
  int GetNumEstados() const;
  Estado GetEstadoInicial() const;
  std::vector<Estado> GetEstados() const;

  void SetAlfabeto(const Alfabeto& alfabeto);
  void SetNumEstados(const int num_estados);
  void SetEstadoInicial(Estado& estado_inicial);
  void SetEstados(const std::vector<Estado>& estados);

  void InsertEstado(const Estado& estado);
  bool ComprobarCadena(Cadena& cadena);
  bool CadenaLenguaje(Cadena& cadena);
  bool FuncionTransicion(Estado& estado_actual, Cadena& cadena);
  std::vector<Estado> EpsilonClausura(Estado& estado_actual);
  bool EstadoAceptacion(std::vector<Estado>& estados);

 private:
  Alfabeto alfabeto_;
  int num_estados_;
  Estado estado_inicial_;
  std::vector<Estado> estados_;

};