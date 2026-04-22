/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2
 * Autor: Enrique Gómez Díaz
 * Correo: alu0101550329@ull.edu.es
 * Fecha: 24/09/2024
 * source Declaración Clase Lenguaje
 */

#include "funciones.h"

/**
 * @brief Método que muestra el mensaje de ayuda
 * @param argc Número de argumentos
 * @param argv Argumentos
 */
void ussage(const int argc, char* argv[]) {
  if (argc == 2 && std::string(argv [1]) == "--help") {
    std::cerr << "Ussage:" << argv[0] << " <archivo_alfabeto> <archivo_cadena> <opcion>" << std::endl;
    std::cerr << "Opciones: " << std::endl;
    std::cerr << "1. Escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada." << std::endl;
    std::cerr << "2. Escribir en el fichero de salida la longitud de cada cadena de entrada." << std::endl;
    std::cerr << "3. Escribir en el fichero de salida la inversa de cada cadena de entrada." << std::endl;
    std::cerr << "4. Escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente." << std::endl;
    std::cerr << "5. Escribir en el fichero de salida el conjunto de cadenas que son sufijos de cada cadena de entrada correspondiente." << std::endl;
    exit(1);
  }
  if (argc != 4) {
    std::cerr << "Ussage:" << argv[0] << " <archivo_alfabeto> <archivo_cadena> <opcion>" << std::endl;
    exit(1);
  }
}

/**
 * @brief Método que obtiene la cadena de la línea
 * @param line Línea de la que se obtiene la cadena
 * @param contador Contador de la línea
 * @return Cadena de la línea
 */
std::string obtenerCadena(const std::string& line, int& contador) {
  std::string cadena;
  for (contador = 0; contador < line.size(); contador++) {
    if (line[contador] == ' ' && contador < line.size() - 1) {
        contador++;
        break;
    } else {
      cadena += line[contador];
      }
  }
  return cadena;
}

/**
 * @brief Método que obtiene el alfabeto de la línea
 * @param line Línea de la que se obtiene el alfabeto
 * @param contador Contador de la línea
 * @return Alfabeto de la línea
 */
std::string obtenerAlfabeto(const std::string& line, int& contador) {
  std::string alfabeto;
  for (contador; contador < line.size(); contador++) {
    alfabeto += line[contador];
  }
  return alfabeto;
}

/**
 * @brief Método que comprueba que la cadena pertenece al alfabeto
 * @param cadena Cadena a comprobar
 * @param alfabeto Alfabeto asociado a la cadena
 * @return True si la cadena pertenece al alfabeto, false en caso contrario
 */
bool comprobarPertenencia(Cadena& cadena, Alfabeto& alfabeto) {
  for (int i = 0; i < cadena.get_cadena().size(); i++) {
    if (alfabeto.get_alfabeto().find(cadena.get_cadena()[i]) == alfabeto.get_alfabeto().end()) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Método que comprueba si el alfabeto es vacío o si la cadena no pertenece al alfabeto
 * @param cadena Cadena a comprobar
 * @param alfabeto Alfabeto asociado a comprobar
 */
void comprobarAlfabeto(Cadena& Cadena, Alfabeto& alfabeto) {
  if (alfabeto.get_alfabeto().size() == 0 ||  comprobarPertenencia(Cadena, alfabeto) == false) {
    Cadena.set_alfabeto(Cadena.get_cadena());
  } else {
     Cadena.set_alfabeto(alfabeto);
    }
}