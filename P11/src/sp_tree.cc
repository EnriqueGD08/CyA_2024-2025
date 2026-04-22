/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11
 * @autor: Enrique Gómez Díaz
 * @mail: alu0101550329@ull.edu.es
 * @date: 10/12/2024
 * @brief archivo principal
 * uso: ./MinimumSpanningTree <archivo_entrada> <archivo_salida> [-d <archivo_dot>]
*/

#include "point_set.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Imprime el uso del programa
 * @param nombre_programa nombre del programa
*/
void print_usage(const char* nombre_programa) {
    std::cerr << "Uso: " << nombre_programa << " <archivo_entrada> <archivo_salida> [-d <archivo_dot>]" << std::endl;
    std::cerr << "  <archivo_entrada>  Archivo de entrada con los puntos" << std::endl;
    std::cerr << "  <archivo_salida>   Archivo de salida con el árbol generador mínimo" << std::endl;
    std::cerr << "  -d <archivo_dot>   Generar archivo DOT con el árbol generador mínimo" << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    print_usage(argv[0]);
    return 1;
  }

  // Archivos de entrada y salida
  std::string archivo_entrada = argv[1];
  std::string archivo_salida = argv[2];
  std::string archivo_dot;
  bool opcion_dot = false;

  // Revisar si se incluye la opción -d
  if (argc == 5 && std::string(argv[3]) == "-d") {
    opcion_dot = true;
    archivo_dot = argv[4];
  } else if (argc > 3) {
    print_usage(argv[0]);
    return 1;
  }

  // Leer puntos desde el archivo de entrada
  CyA::point_vector points;
  std::ifstream entrada(archivo_entrada);
  if (!entrada.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo de entrada: " << archivo_entrada << "\n";
    return 1;
  }
  entrada >> points;
  entrada.close();

  // Calcular el EMST
  point_set ps(points);
  ps.EMST();

  // Escribir el resultado en el archivo de salida
  std::ofstream salida(archivo_salida);
  if (!salida.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo de salida: " << archivo_salida << "\n";
    return 1;
  }
  ps.write_tree(salida);
  salida.close();

  // Generar archivo DOT si se especifica la opción -d
  if (opcion_dot) {
    std::ofstream dot_salida(archivo_dot);
    if (!dot_salida.is_open()) {
      std::cerr << "Error: no se pudo abrir el archivo DOT: " << archivo_dot << "\n";
      return 1;
    }
    dot_salida << "graph EMST {\n";
    for (const auto& arc : ps.get_tree()) {
      dot_salida << "    \"" << arc.first.first << "," << arc.first.second
                 << "\" -- \"" << arc.second.first << "," << arc.second.second << "\";\n";
    }
    dot_salida << "}\n";
    dot_salida.close();
  }

  return 0;
}