/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 08/10/2024
 * @brief Declaración de la clase comentario
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Comentario {
 public:
  Comentario(const int principio, const int final);
  Comentario(const int linea, const std::string& comentario);
  Comentario(){};

  std::string GetContenido() const;
  int GetPrincipio() const;
  int GetFinal() const;
  std::string GetComentario() const;

 private:
  int principio_;
  int final_;
  std::string contenido_;
};

std::ostream& operator<<(std::ostream& os, const Comentario& comentario);