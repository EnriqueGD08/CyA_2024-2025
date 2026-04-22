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
 * @brief implementación de las funciones que se utilizan en el programa
*/

#include "funciones.h"

/**
 * @brief Método que muestra el uso del programa
 * @param argc Número de argumentos
 * @param argv Argumentos
*/
void usage(const int argc, char* argv[]) {
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--help") {
      std::cout << "Este programa necesita dos parámetros" << std::endl;
      std::cout << "Forma de uso: ./gramaticaFNC <archivo1.gra> <archivo2.gra>" << std::endl;
      std::cout << "El primer parámetro es un archivo con una gramática independiente del contexto.";
      std::cout << std::endl << "Formato:" << std::endl;
      std::cout << "Número de símbolos terminales" << std::endl;
      std::cout << "Símbolos terminales (solo uno por línea)" << std::endl;
      std::cout << "Número de símbolos no terminales" << std::endl;
      std::cout << "Símbolos no terminales (solo uno por línea)" << std::endl;
      std::cout << "Número de producciones" << std::endl;
      std::cout << "Producciones (las dos partes se separan por un único espacio)" << std::endl << std::endl;
      std::cout << "El segundo parámetro es el archivo en el que se quiere que se guarde la gramática en ";
      std::cout << "forma normal de Chomsky resultante" << std::endl;
      exit(0);
    }
  } 
  if (argc != 3) {
    std::cerr << "No están todos los parámetros necesarios" << std::endl;
    std::cout << "Forma de uso: ./gramaticaFNC <archivo1.gra> <archivo2.gra>" << std::endl;
    std::cerr << "Ejecute con --help para más información" << std::endl;
    exit(1);
  }
}