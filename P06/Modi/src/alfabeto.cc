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
 * @brief Implementación de la clase Alfabeto
*/

#include "alfabeto.h"

/**
 * @brief Constructor por defecto de la clase Alfabeto
 * @return Objeto de la clase Alfabeto
 */
Alfabeto::Alfabeto() {}

/**
 * @brief Constructor parametrizado de la clase Alfabeto
 * @param alfabeto Conjunto de símbolos que forman el alfabeto
 * @return Objeto de la clase Alfabeto
 */
Alfabeto::Alfabeto(const char alfabeto) {
  alfabeto_.insert(alfabeto);
}

/**
 * @brief Constructor parametrizado de la clase Alfabeto
 * @param alfabeto Conjunto de símbolos que forman el alfabeto
 * @return Objeto de la clase Alfabeto
*/
Alfabeto::Alfabeto(const std::string& alfabeto) {
  alfabeto_.clear();
  for (int i = 0; i < alfabeto.size(); i++) {
    if (alfabeto[i] == ' ') {
      continue;
    }
    if (alfabeto[i] == '&') {
      std::cout << "El simbolo & no es un simbolo válido. No formará parte del alfabeto" << std::endl;
      continue;
    }
    alfabeto_.insert(alfabeto[i]);
  }
  if (alfabeto_.size() == 0) {
    std::cout << "No se a pasado un alfabeto" << std::endl;
    exit(1);
  }
}

/**
 * @brief Destructor de la clase Alfabeto
*/
Alfabeto::~Alfabeto() {}

/**
 * @brief Método que devuelve el alfabeto
 * @return Conjunto de símbolos que forman el alfabeto
 */
const std::set<char>& Alfabeto::GetAlfabeto() const {
  return alfabeto_;
}

/**
 * @brief Método que establece el alfabeto
 * @param alfabeto Conjunto de símbolos que forman el alfabeto
 */
void Alfabeto::InsertAlfabeto(const char alfabeto) {
  alfabeto_.insert(alfabeto);
}

/**
 * @brief Sobrecarga del operador de inserción
 * @param os Flujo de salida
 * @param alfabeto Alfabeto a mostrar
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  std::set<Simbolo>::iterator it = alfabeto.GetAlfabeto().begin();
  for (int i = 0; i < (alfabeto.GetAlfabeto().size() - 1); i++) {
    os << Simbolo(*it) << ", ";
    it++;
  }
  os << Simbolo(*it);
  os << "}";
  return os;
}

/**
 * @brief Sobrecarga del operador de extracción
 * @param is Flujo de entrada
 * @param alfabeto Alfabeto a leer
 * @return Flujo de entrada
 */
std::istream& operator>>(std::istream& is, Alfabeto& alfabeto) {
  std::string auxiliar;
  is >> auxiliar;
  for (int i = 0; i < alfabeto.GetAlfabeto().size(); i++) {
    if (auxiliar[i] == ' ') {
      continue;
    } else {
      alfabeto.InsertAlfabeto(auxiliar[i]);
    }
  } 
  return is;
}