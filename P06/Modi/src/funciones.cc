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
 * @brief Implementación de las funciones del programa
*/

#include "funciones.h"

/**
 * @brief Método que muestra el uso del programa
 * @param argc Número de argumentos
 * @param argv Argumentos
*/
void usage(const int argc, char* argv[]) {
  if (std::string(argv [1]) == "--help") {
    std::cout << "Este programa necesita dos parámetros" << std::endl;
    std::cout << "El primer parámetro es el nombre del fichero que contiene la descripción del FA" << std::endl;
    std::cout << "El segundo parámetro es el nombre del fichero que contiene las cadenas que se quieren probar" << std::endl;
    exit(0);
  } else if (argc != 3) {
    std::cerr << "No están todos los parámetros necesarios" << std::endl;
    std::cerr << "Ejecute con --help para más información" << std::endl;
    exit(1);
  }
}

/**
 * @brief Método que lee un fichero y guarda la información en un objeto FA
 * @param fichero Fichero que contiene la descripción del FA
 * @param fa Objeto FA donde se guardará la información
*/
void LeerFicheroFA(std::ifstream& fichero, FA& fa) {
  std::string aux;
  std::getline(fichero, aux);
  Alfabeto alfabeto_FA(aux);
  fa.SetAlfabeto(alfabeto_FA);
  int num_estados;
  std::getline(fichero, aux);
  if (aux.size() == 0) {
    std::cout << "No se ha podido leer el numero de estados" << std::endl;
    exit(1);
  }
  num_estados = std::stoi(aux);
  fa.SetNumEstados(num_estados);
  int estado_inicial;
  std::getline(fichero, aux);
  if (aux.size() == 0) {
    std::cout << "No se ha podido leer el estado inicial" << std::endl;
    exit(1);
  }
  estado_inicial = std::stoi(aux);
  std::vector<Estado> estados;
  CrearEstados(fichero, estados);
  fa.SetEstadoInicial(estados[estado_inicial]);
  fa.SetEstados(estados);
}

/**
 * @brief Método que crea los estados de un FA
 * @param fichero Fichero que contiene la descripción del FA
 * @param estados Vector de estados donde se guardarán los estados
*/
void CrearEstados(std::ifstream& fichero, std::vector<Estado>& estados) {
  std::string linea;
  while (std::getline(fichero, linea)) {
    if (linea.size()%2 != 1) {
      std::cout << "En la fila: " << linea << " no se pasan todos los argumentos necesarios" << std::endl;
      exit(1);
    }
    int identificador;
    identificador = CogerIdentificador(linea); 
    bool aceptacion;
    aceptacion = CogerAceptacion(linea);
    int num_transiciones;
    num_transiciones = CogerNumTrancisiones(linea);
    std::vector<Transicion> transiciones;
    int posicion1 = 3;
    int posicion2 = 4;
    for (int i = 0; i < num_transiciones; i++) {
      Simbolo simbolo;
      simbolo = CogerSimbolo(linea, posicion1);
      int estado_destino;
      estado_destino = CogerDestino(linea, posicion2);
      Transicion transicion(simbolo, estado_destino);
      transiciones.push_back(transicion);
      posicion1 += 2;
      posicion2 += 2;
    }
    std::cout << std::endl;
    Estado estado(identificador, aceptacion, transiciones);
    estados.push_back(estado);
  }
}

/**
 * @brief Método que lee un fichero y guarda las cadenas en un vector
 * @param fichero Fichero que contiene las cadenas
 * @param cadenas Vector donde se guardarán las cadenas
*/
void LeerCadenas(std::ifstream& fichero, std::vector<Cadena>& cadenas) {
  std::string linea;
  while (std::getline(fichero, linea)) {
    Cadena cadena(linea);
    cadenas.push_back(cadena);
  }
}

/**
 * @brief Método que coge el identificador de un estado
 * @param linea Línea que contiene la información del estado
 * @return Identificador del estado
*/
int CogerIdentificador(const std::string& linea) {
  std::string identificador;
  for (int i = 0; i < linea.size(); i++) {
    if (linea[i] == ' ') {break;} 
    else {identificador += linea[i];}
  }
  if (identificador.size() == 0) {
    std::cout << "En la linea " << linea << " no se pudo leer el identidicador del estado" << std::endl;
    exit(1);
  }
  return std::stoi(identificador);
}

/**
 * @brief Método que coge la aceptación de un estado
 * @param linea Línea que contiene la información del estado
 * @return Aceptación del estado
*/
bool CogerAceptacion(const std::string& linea) {
  std::string aceptacion;
  int i = 0;
  for (i; i < linea.size(); i++) {
    if (linea[i] == ' ') {i++; break;} 
    else {continue;}
  }

  for (i; i < linea.size(); i++) {
    if (linea[i] == ' ') {break;} 
    else {aceptacion += linea[i];}
  }
  if (aceptacion.size() == 0) {
    std::cout << "En la linea " << linea << " no se pudo leer si el estado es de aceptacion o no" << std::endl;
    exit(1);
  }
  return std::stoi(aceptacion);
}

/**
 * @brief Método que coge el número de transiciones de un estado
 * @param linea Línea que contiene la información del estado
 * @return Número de transiciones del estado
*/
int CogerNumTrancisiones(const std::string& linea) {
  std::string NumTrancisiones;
  int i = 0;
  for (i; i < linea.size(); i++) {
    if (linea[i] == ' ') {i++; break;} 
    else {continue;}
  }

  for (i; i < linea.size(); i++) {
    if (linea[i] == ' ') {i++; break;} 
    else {continue;}
  }

  for (i; i < linea.size(); i++) {
    if (linea[i] == ' ') {break;} 
    else {NumTrancisiones += linea[i];}
  }

  if (NumTrancisiones.size() == 0) {
    std::cout << "En la linea " << linea << " no se pudo leer el numero de transiciones del estado" << std::endl;
    exit(1);
  }
  return std::stoi(NumTrancisiones);
}

/**
 * @brief Método que coge el símbolo de una transición
 * @param linea Línea que contiene la información de la transición
 * @param posicion Posición del símbolo en la línea
 * @return Símbolo de la transición
*/
Simbolo CogerSimbolo(const std::string& linea, const int posicion) {
  Simbolo simbolo;
  int j = 0;
  for (int i = 0; i < posicion; i++) {
    for (j; i < linea.size(); j++) {
      if (linea[j] == ' ') {j++; break;} 
      else {continue;}
    }
  }
  if (j < linea.size()) {
    simbolo = linea[j];
  }
  if (simbolo == ' ') {
    std::cout << "En la linea " << linea << " no se pudo leer el simbolo de una transicion" << std::endl;
    exit(1);
  }
  return simbolo;
}

/**
 * @brief Método que coge el destino de una transición
 * @param linea Línea que contiene la información de la transición
 * @param posicion Posición del destino en la línea
 * @return Destino de la transición
*/
int CogerDestino(const std::string& linea, const int posicion) {
  std::string destino;
  int j = 0;
  for (int i = 0; i < posicion; i++) {
    for (j; i < linea.size(); j++) {
      if (linea[j] == ' ') {j++; break;} 
      else {continue;}
    }
  }
  for (j; j < linea.size(); j++) {
    if (linea[j] == ' ') {break;} 
    else {destino += linea[j];}
  }
  if (destino.size() == 0) {
    std::cout << "En la linea " << linea << " no se pudo leer el destino de una transicion" << std::endl;
    exit(1);
  }
  return std::stoi(destino);
}

/**
 * @brief Método que imprime los resultados de las cadenas
 * @param fa Objeto FA
 * @param cadenas Vector de cadenas
*/
void ImprimirResultados(FA& fa, std::vector<Cadena>& cadenas) {
  for (int i = 0; i < cadenas.size(); i++) {
    std::cout << cadenas[i].GetCadena() << "\t--- ";
    if (fa.CadenaLenguaje(cadenas[i])) {
      std::cout << "Aceptada" << std::endl;
    } else {
      std::cout << "No aceptada" << std::endl;
    }
  }
}
