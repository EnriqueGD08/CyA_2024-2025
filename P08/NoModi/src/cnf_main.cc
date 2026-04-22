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
 * @brief main del programa para pasar gramáticas a forma normal de Chomsky
*/

#include "funciones.h"
#include "gramatica.h"

int main(int argc, char* argv[]) {
  usage(argc, argv);
  std::ifstream fichero(argv[1]);
  Gramatica gramatica(fichero);
  Gramatica gramatica_fnc = gramatica.PasarFNC();
  std::ofstream fichero_salida(argv[2]);
  //std::cout << gramatica << std::endl;
  std::cout << gramatica_fnc << std::endl;
  return 0;
}