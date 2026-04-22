/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source main del programa de cadenas y alfabetos
 */

#include "funciones.h"
#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

int main(int argc, char *argv[]) {
  ussage(argc, argv);

  std::ifstream entrada_file(argv[1]);
  if (!entrada_file) {
    std::cerr << "No se pudo abrir el archivo de entrada" << std::endl;
    exit(1);
  }
  
  std::ofstream salida_file(argv[2]);
  if (!salida_file) {
    std::cout << "No se pudo abrir el archivo de salida" << std::endl;
    std::cout << "Creando uno nuevo..." << std::endl;
  }
  int opcion = std::stoi(argv[3]);
  
  std::string line;

  switch(opcion) {
    case 1:
      while (std::getline(entrada_file, line)) {
        int contador = 0;
        Cadena Cadena(obtenerCadena(line, contador));
        Alfabeto alfabeto(obtenerAlfabeto(line, contador));
        comprobarAlfabeto(Cadena, alfabeto);
        salida_file << Cadena.get_alfabeto() << std::endl;
      }
      break;

    case 2:
      while (std::getline(entrada_file, line)) {
        int contador = 0;
        Cadena Cadena(obtenerCadena(line, contador));
        Alfabeto alfabeto(obtenerAlfabeto(line, contador));
        comprobarAlfabeto(Cadena, alfabeto);
        salida_file << Cadena.longitud() << std::endl;
      }
      break;
    case 3:
      while (std::getline(entrada_file, line)) {
        int contador = 0;
        Cadena cadena(obtenerCadena(line, contador));
        Alfabeto alfabeto(obtenerAlfabeto(line, contador));
        comprobarAlfabeto(cadena, alfabeto);
        salida_file << cadena.inversa() << std::endl;
      }
      break;
    case 4:
      while (std::getline(entrada_file, line)) {
        int contador = 0;
        Cadena cadena(obtenerCadena(line, contador));
        Alfabeto alfabeto(obtenerAlfabeto(line, contador));
        comprobarAlfabeto(cadena, alfabeto);
        std::set<Cadena> prefijos;
        cadena.prefijos(prefijos);
        Lenguaje lenguaje(prefijos);
        std::set<Cadena>::iterator it = lenguaje.get_lenguaje().begin();
        salida_file << lenguaje << std::endl;
      }
      break;
    case 5:
      while (std::getline(entrada_file, line)) {
        int contador = 0;
        Cadena cadena(obtenerCadena(line, contador));
        Alfabeto alfabeto(obtenerAlfabeto(line, contador));
        comprobarAlfabeto(cadena, alfabeto);
        std::set<Cadena> sufijos;
        cadena.sufijos(sufijos);
        Lenguaje lenguaje(sufijos);
        std::set<Cadena>::iterator it = lenguaje.get_lenguaje().begin();
        salida_file << lenguaje << std::endl;
      }
      break;
    default:
      std::cerr << "Opción no válida" << std::endl;
      exit(1);
  }

  return 0;
}