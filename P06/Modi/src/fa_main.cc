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
 * @brief main del programa de FA
*/

#include <iostream>
#include "funciones.h"
#include "fa.h"

int main(int argc, char *argv[]) {
  system("clear");
  usage(argc, argv);
  std::ifstream fichero(argv[1]);
  FA fa;
  LeerFicheroFA(fichero, fa);
  std::ifstream fichero_cadenas(argv[2]);
  std::vector<Cadena> cadenas;
  LeerCadenas(fichero_cadenas, cadenas);
  ImprimirResultados(fa, cadenas);

  return 0;
}