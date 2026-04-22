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
 * @brief Implementación de las funciones del programa
*/

#include "funciones.h"

const std::regex entero(R"(\s*int\s\D\w*(\s?=\s?-?\d+)?;\s*$)");
const std::regex doble(R"(\s*double\s\D\w*(\s?=\s?-?\d+(\.\d+)?)?;\s*$)");
const std::regex bucle(R"(\s*(for|while)\s*\(.+\)\s?\{)");
const std::regex principal("\\s*int\\s*main\\s*\\(.*\\)\\s*\\{");
const std::regex comentario1(R"(.*\/\/.*)");
const std::regex comentario2(R"(\/\*.*)");
const std::regex finales(R"(.*\*\/)");

/**
 * @brief Método que muestra el mensaje de ayuda
 * @param argc Número de argumentos
 * @param argv Argumentos
 */
void ussage(const int argc, char* argv[]) {
  if (argc == 2 && std::string(argv [1]) == "--help") {
    std::cerr << "Ussage:" << argv[0] << " <fichero de entrada> <fichero de salida>" << std::endl;
    std::cerr << "Fichero de entrada: fichero de código C++ sintácticamente correcto" << std::endl;
    std::cerr << "Fichero de salida: fichero en el que se almacenará la estructura general del codigo" << std::endl;
    exit(1);
  }
  if (argc != 3) {
    std::cerr << "Ussage:" << argv[0] << " <fichero de entrada> <fichero de salida>" << std::endl;
    exit(1);
  }
}

/**
 * @brief Método que comprueba si se ha podido abrir el fichero de entrada
 * @param entrada Fichero de entrada
 * @return true si se ha podido abrir el fichero, false en caso contrario
 */
bool ComprobarFichero(std::ifstream& entrada) {
  if (!entrada) {
    std::cerr << "No se pudo abrir el archivo de entrada" << std::endl;
    exit(1);
  } else {
    return true;
  }
}

/**
 * @brief Método que busca las variables en el fichero de entrada
 * @param entrada Fichero de entrada
 * @param variables Vector de variables
 */
void BuscarVariables(std::ifstream& entrada, std::vector<Variable>& variables) {
  std::string linea;
  entrada.clear();
  entrada.seekg(0);
  int i = 1;
  while (std::getline(entrada, linea)) {
    if (std::regex_match(linea, entero) == true || std::regex_match(linea, doble) == true) {
      Variable variable(i, linea);
      variables.push_back(variable);
    }
    i++;
  }
}

/**
 * @brief Método que busca los bucles en el fichero de entrada
 * @param entrada Fichero de entrada
 * @param bucles Vector de bucles
 */
void BuscarBucles(std::ifstream& entrada, std::vector<Bucle>& bucles) {
  std::string linea;
  entrada.clear();
  entrada.seekg(0);
  int i =  1;
  while (std::getline(entrada, linea)) {
    std::smatch match;
    if (std::regex_search(linea, match, bucle) == true) {
      Bucle bucle(i, match.str());
      bucles.push_back(bucle);
    }
    i++;
  }
}

/**
 * @brief Método que busca la función main en el fichero de entrada
 * @param entrada Fichero de entrada
 * @param main Booleano que indica si se ha encontrado la función main
 */
void BuscarMain(std::ifstream& entrada, bool& main) {
  std::string linea;
  entrada.clear();
  entrada.seekg(0);
  while (std::getline(entrada, linea)) {
    std::smatch match;
    if (std::regex_search(linea, match, principal) == true) {
      main = true;
    }
  }
}

/**
 * @brief Método que busca los comentarios en el fichero de entrada
 * @param entrada Fichero de entrada
 * @param comentarios Vector de comentarios
 */
void BuscarComentarios(std::ifstream& entrada, std::vector<Comentario>& comentarios) {
  std::string linea;
  entrada.clear();
  entrada.seekg(0);
  int i = 1;
  while (std::getline(entrada, linea)) {
    std::smatch match;
    if (std::regex_search(linea, match, comentario1) == true) {
      Comentario comentario(i, match.str());
      comentarios.push_back(comentario);
    } else if (std::regex_search(linea, match, comentario2) == true) {
      int final = i;
      while (std::getline(entrada, linea)) {
        final++;
        if (std::regex_search(linea, match, finales) == true) {
          break;
        }
      }
      Comentario comentario(i, final);
      comentarios.push_back(comentario);
      i = final;
    }
    i++;
  }
}

/**
 * @brief Método que imprime la descripción del programa
 * @param salida Fichero de salida
 * @param comentarios Vector de comentarios
 * @param entrada Fichero de entrada
 */
void ImprimirDescripcion(std::ofstream& salida, std::vector<Comentario>& comentarios, std::ifstream& entrada) {
  for (int i = 0; i < comentarios.size(); i++) {
    if (comentarios[i].GetPrincipio() == 1 && comentarios[i].GetContenido() == "Comentario de cabecera") {
      salida << "DESCRIPCION:" << std::endl;
      entrada.clear();
      entrada.seekg(0);
      std::string linea;
      for (int j = 0; j < comentarios[i].GetFinal() ; j++) {
        std::getline(entrada, linea);
        salida << linea << std::endl;
      }
    }
  }
}

/**
 * @brief Método que imprime las variables del programa
 * @param salida Fichero de salida
 * @param variables Vector de variables
 */
void ImprimirVariables(std::ofstream& salida, std::vector<Variable>& variables) {
  if (variables.size() > 0) {
    salida << std::endl << "VARIABLES:" << std::endl;
    for (int i = 0; i < variables.size(); i++) {
      salida << "[Linea " << variables[i].GetLine() << "] " << variables[i].GetTipo() << ": " << variables[i].GetNombre();
      if (variables[i].GetAsignarValor() == true) {
        salida << " = " << variables[i].GetValor() << std::endl;
      } else {
        salida << std::endl;
      }
    }
  }
}

/**
 * @brief Método que imprime los bucles del programa
 * @param salida Fichero de salida
 * @param bucles Vector de bucles
 */
void ImprimirBucles(std::ofstream& salida, std::vector<Bucle>& bucles) {
  if (bucles.size() > 0) {
    salida << std::endl << "BUCLES:" << std::endl;
    for (int i = 0; i < bucles.size(); i++) {
      salida << "[Linea " << bucles[i].GetLine() << "]: " << bucles[i].GetTipo() << std::endl;
    }
  }
}

/**
 * @brief Método que imprime si se ha encontrado la función main
 * @param salida Fichero de salida
 * @param main Booleano que indica si se ha encontrado la función main
 */
void ImprimirMain(std::ofstream& salida, bool main) {
  salida << std::endl << "MAIN:" << std::endl;
  if (main == true) {
    salida << "Verdadero" << std::endl;
  } else {
    salida << "Falso" << std::endl;
  }
}

/**
 * @brief Método que imprime los comentarios del programa
 * @param salida Fichero de salida
 * @param comentarios Vector de comentarios
 */
void ImprimirComentarios(std::ofstream& salida, std::vector<Comentario>& comentarios) {
  salida << std::endl << "COMENTARIOS:" << std::endl;
  for (int i = 0; i < comentarios.size(); i++) {
    if (comentarios[i].GetFinal() != comentarios[i].GetPrincipio()) {
      salida << "[Lineas " << comentarios[i].GetPrincipio() << " - " << comentarios[i].GetFinal() << "] " << comentarios[i].GetContenido() << std::endl;
    } else {
      salida << "[Linea " << comentarios[i].GetPrincipio() << "] " << comentarios[i].GetContenido() << std::endl;
    }
  }
}