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
 * @brief main del programa de analizador código c++
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "funciones.h"
#include "comentario.h"
#include "variable.h"
#include "bucle.h"

int main(int argc, char* argv[]) {
  ussage(argc, argv);

  std::ifstream entrada(argv[1]);
  ComprobarFichero(entrada);
  std::ofstream salida(argv[2]);

  std::vector<Variable> variables;
  std::vector<Bucle> bucles;
  bool main = false;
  std::vector<Comentario> comentarios;

  BuscarVariables(entrada, variables);
  BuscarBucles(entrada, bucles);
  BuscarMain(entrada, main);
  BuscarComentarios(entrada, comentarios);

  salida << "PROGRAMA: " << argv[1] << std::endl;
  ImprimirDescripcion(salida, comentarios, entrada);
  ImprimirVariables(salida, variables);
  ImprimirBucles(salida, bucles);
  ImprimirMain(salida, main);
  ImprimirComentarios(salida, comentarios);

  return 0;
}