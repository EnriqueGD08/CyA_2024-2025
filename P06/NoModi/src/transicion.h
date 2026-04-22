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
 * @brief Declaración de la clase transicion
*/

#pragma once

typedef char Simbolo;

class Estado;

class Transicion {
 public:
  Transicion();
  Transicion(const Simbolo simbolo, const int estado_destino);
  ~Transicion();

  Simbolo GetSimbolo() const;
  int GetEstadoDestino() const;

  void SetSimbolo(const Simbolo simbolo);
  void SetEstadoDestino(const int estado_destino);

 private:
  Simbolo simbolo_;
  int estado_destino_;
};