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
 * @brief Implementación de la clase gramatica
*/

#include "gramatica.h"

/**
 * @brief Constructor por defecto de la clase Gramatica
*/
Gramatica::Gramatica() {}

/**
 * @brief Constructor parametrizado de la clase Gramatica
 * @param alfabeto Alfabeto de la gramática
 * @param no_terminales Conjunto de símbolos no terminales
 * @param producciones Conjunto de producciones
*/
Gramatica::Gramatica(Alfabeto& alfabeto, std::set<Noterminal> no_terminales, std::vector<Produccion> producciones) {
  alfabeto_ = alfabeto;
  no_terminales_ = no_terminales;
  producciones_ = producciones;
}

/**
 * @brief Constructor parametrizado de la clase Gramatica
 * @param fichero Fichero de entrada
*/
Gramatica::Gramatica(std::ifstream& fichero) {
  std::string linea;
  std::getline(fichero, linea);
  int num_terminales = std::stoi(linea);
  if (num_terminales == 0) {
    std::cerr << "No hay símbolos terminales" << std::endl;
    exit(1);
  }
  for (int i = 0; i < num_terminales; i++) {
    std::getline(fichero, linea);
    if (linea.size() != 1) {
      std::cerr << "El símbolo terminal " << linea << " tiene longitud mayor que 1" << std::endl;
      exit(1);
    }
    alfabeto_.InsertarAlfabeto(linea[0]);
  }

  std::getline(fichero, linea);
  int num_no_terminales = std::stoi(linea);
  if (num_no_terminales == 0) {
    std::cerr << "No hay símbolos no terminales" << std::endl;
    exit(1);
  }
  for (int i = 0; i < num_no_terminales; i++) {
    std::getline(fichero, linea);
    ComprobarNoTerminales(linea);
    no_terminales_.insert(Noterminal(linea));
  }

  std::getline(fichero, linea);
  int num_producciones = std::stoi(linea);
  if (num_producciones == 0) {
    std::cerr << "No hay producciones" << std::endl;
    exit(1);
  }
  for (int i = 0; i < num_producciones; i++) {
    std::getline(fichero, linea);
    std::string parte1 = "";
    std::string parte2 = "";
    for (int j = 0; j < linea.size(); j++) {
      if (linea[j] == ' ') {
        parte1 = linea.substr(0, j);
        parte2 = linea.substr(j + 1, linea.size());
        break;
      }
    }
    ComprobarProducciones(parte1, parte2);
    producciones_.push_back(Produccion(parte1, parte2));
  }
}

/**
 * @brief Método que devuelve el alfabeto
 * @return Alfabeto de la gramática
*/
const Alfabeto& Gramatica::GetAlfabeto() const {
  return alfabeto_;
}

/**
 * @brief Método que devuelve el conjunto de símbolos no terminales
 * @return Conjunto de símbolos no terminales
*/
const std::set<Noterminal>& Gramatica::GetNoTerminales() const {
  return no_terminales_;
}

/**
 * @brief Método que devuelve el conjunto de producciones
 * @return Conjunto de producciones
*/
const std::vector<Produccion>& Gramatica::GetProducciones() const {
  return producciones_;
}

/**
 * @brief Método que establece el alfabeto
 * @param alfabeto Alfabeto de la gramática
*/
void Gramatica::SetAlfabeto(const Alfabeto& alfabeto) {
  alfabeto_ = alfabeto;
}

/**
 * @brief Método que establece el conjunto de símbolos no terminales
 * @param no_terminales Conjunto de símbolos no terminales
*/
void Gramatica::SetNoTerminales(const std::set<Noterminal>& no_terminales) {
  no_terminales_ = no_terminales;
}

/**
 * @brief Método que establece el conjunto de producciones
 * @param producciones Conjunto de producciones
*/
void Gramatica::SetProducciones(const std::vector<Produccion>& producciones) {
  producciones_ = producciones;
}

/**
 * @brief Método que pasa una gramática a forma normal de Chomsky
 * @return Gramática en forma normal de Chomsky
*/
Gramatica Gramatica::PasarFNC() {
  std::set<Noterminal> no_terminales_fnc = no_terminales_;
  std::vector<Produccion> producciones_fnc;
  std::vector<Produccion> producciones_alfabeto_fnc;

  //Paso 1 del algoritmo
  std::set<Simbolo>::iterator it = alfabeto_.GetAlfabeto().begin();
  for (int i = 0; i < alfabeto_.GetAlfabeto().size(); i++) {
    std::string parte1 = "A";
    for (int k = 49; k < 126; k++) {
      std::string no_terminal = parte1 + char(k);
      std::set<Noterminal>::iterator it2 = no_terminales_fnc.find(Noterminal(no_terminal));
      std::set<Simbolo>::iterator it3 = alfabeto_.GetAlfabeto().find(Simbolo(char(k)));
      if (it2 == no_terminales_fnc.end() && it3 == alfabeto_.GetAlfabeto().end()) {
        no_terminales_fnc.insert(Noterminal(no_terminal));
        std::string parte2(1, *it);
        producciones_alfabeto_fnc.push_back(Produccion(no_terminal, parte2));
        break;
      }
    }
    it++;
  }
  std::vector<bool> nuevos_no_terminales(producciones_alfabeto_fnc.size(), false);
  for (int i = 0; i < producciones_.size(); i++) {
    std::string parte1 = producciones_[i].GetParte1();
    std::string parte2 = producciones_[i].GetParte2();
    if (parte2.size() == 1) {
      producciones_fnc.push_back(Produccion(parte1, parte2));
    }
  }
  for (int i = 0; i < producciones_.size(); i++) {
    if (producciones_[i].GetParte2().size() == 1) {
      continue;
    }
    std::string parte2 = producciones_[i].GetParte2();
    std::string parte2_aux = "";
    for (int j = 0; j < parte2.size(); j++) {
      if (alfabeto_.GetAlfabeto().find(parte2[j]) != alfabeto_.GetAlfabeto().end()) {
        for (int k = 0; k < producciones_alfabeto_fnc.size(); k++) {
          if (producciones_alfabeto_fnc[k].GetParte2() == std::string(1, parte2[j])) {
            nuevos_no_terminales[k] = true;
            parte2_aux += producciones_alfabeto_fnc[k].GetParte1();
            break;
          }
        }
      } else {
        parte2_aux += parte2[j];
      }
    }
    producciones_fnc.push_back(Produccion(producciones_[i].GetParte1(), parte2_aux));
  }
  for (int i = 0; i < producciones_alfabeto_fnc.size(); i++) {
    if (nuevos_no_terminales[i] == true) {
      producciones_fnc.push_back(producciones_alfabeto_fnc[i]);
    }
  }

  //Paso 2 del algoritmo
  std::vector<Produccion> producciones_aux;
  for (int i = 0; i < producciones_fnc.size(); i++) {
    std::string parte1 = producciones_fnc[i].GetParte1();
    std::string parte2 = producciones_fnc[i].GetParte2();
    if (parte2.size() > 2) {
    int contador = 0;
    std::string aux = "";
    for (int j = 0; j < parte2.size(); j++) {
      aux += parte2[j];
      std::set<Noterminal>::iterator it = no_terminales_fnc.find(Noterminal(aux));
      if (it != no_terminales_fnc.end()) {
        contador++;
        aux = "";
      }
    }
    int guardar = parte2.size() - 1;
    int k = guardar;
    for (int j = 0; j < contador - 2; j++) {
      parte2 = producciones_fnc[i].GetParte2();
      std::string aux1 = "";
      std::string aux2 = "B";
      for (k; k >= 0; k--) {
        aux1 = parte2[k] + aux1;
        for (int l = 0; l < producciones_fnc.size(); l++) {
          if (producciones_fnc[l].GetParte2() == aux1) {
            break;
          }
        }
      }
      guardar = k;
      for (; k >= 0; k--) {
        aux1 = parte2[k] + aux1;
        for (int l = 0; l < producciones_fnc.size(); l++) {
          if (producciones_fnc[l].GetParte2() == aux1) {
            break;
          }
        }
      }
      k = guardar;
      for (int l = 49; l < 126; l++) {
        std::string no_terminal = aux2 + char(l);
        std::set<Noterminal>::iterator it = no_terminales_fnc.find(Noterminal(no_terminal));
        std::set<Simbolo>::iterator it2 = alfabeto_.GetAlfabeto().find(Simbolo(char(l)));
        bool comprobar = false;
        for (int m = 0; m < producciones_aux.size(); m++) {
          if (producciones_aux[m].GetParte2() == aux1) {
            comprobar = true;
            break;
          }
        }
        if (it == no_terminales_fnc.end() && it2 == alfabeto_.GetAlfabeto().end() && aux1.size() != 0 && comprobar == false) {
          no_terminales_fnc.insert(Noterminal(no_terminal));
          producciones_fnc.push_back(Produccion(no_terminal, aux1));
          producciones_aux.push_back(Produccion(no_terminal, aux1));
          producciones_fnc[i].SetParte2(parte2.substr(0, k + 1) + no_terminal);
          break;
        }
      }
    }
    }
  }
  return Gramatica(alfabeto_, no_terminales_fnc, producciones_fnc);
}

/**
 * @brief Método que comprueba si los símbolos no terminales son correctos
 * @return True si los símbolos no terminales son correctos, false en caso contrario
*/
void Gramatica::ComprobarNoTerminales(const std::string& no_terminal) {
  if (no_terminal.size() == 0) {
    std::cerr << "El símbolo no terminal " << no_terminal << " no es correcto" << std::endl;
    exit(1);
  }
  for (int i = 0; i < no_terminal.size(); i++) {
    if (alfabeto_.GetAlfabeto().find(no_terminal[i]) != alfabeto_.GetAlfabeto().end()) {
      std::cerr << "El símbolo no terminal " << no_terminal << " tiene un símbolo " << no_terminal[i] << " que se encuentra en el alfabeto de terminales" << std::endl;
      exit(1);
    }
  }

  return;
}

/**
 * @brief Método que comprueba si las producciones son correctas
 * @return True si las producciones son correctas, false en caso contrario
*/
void Gramatica::ComprobarProducciones(std::string& parte1, std::string& parte2) {
  if (parte2 == "&" && parte1 != "S") {
    std::cerr << "La producción " << parte1 << " -> " << parte2 << " no es correcta (produccion vacía)" << std::endl;
    exit(1);
  }

  for (int i = 0; i < parte2.size(); i++) {
    if (parte2[i] == ' ' || parte2[i] == '&') {
      std::string parte2_aux = parte2;
      parte2_aux = parte2.substr(0, i);
      parte2_aux += parte2.substr(i + 1, parte2.size());
      parte2 = parte2_aux;
      i--;
    }
  }

  if (parte1.size() == 0) {
    std::cerr << "La parte izquierda de la producción " << parte2 << " no es correcta" << std::endl;
    exit(1);
  }

  if (parte2.size() == 0) {
    std::cerr << "La parte derecha de la producción " << parte1 << " no es correcta" << std::endl;
    exit(1);
  }

  std::set<Noterminal>::iterator it = no_terminales_.find(Noterminal(parte1));
  if (it == no_terminales_.end()) {
    std::cerr << "El símbolo no terminal " << parte1 << " no se encuentra en el conjunto de símbolos no terminales" << std::endl;
    exit(1);
  }
  std::set<Noterminal>::iterator it2 = no_terminales_.find(Noterminal(parte2));
  if (it2 != no_terminales_.end()) {
    std::cerr << "La producción " << parte1 << " -> " << parte2 << " no es correcta" << std::endl;
    std::cerr << "El símbolo no terminal " << parte2 << " se encuentra en el conjunto de símbolos no terminales, por lo que es una produccion unitaria" << std::endl;
    exit(1);
  }

  return;
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Flujo de salida
 * @param gramatica Gramática a mostrar
 * @return Flujo de salida
*/
std::ostream& operator<<(std::ostream& os, const Gramatica& gramatica) {
  os << gramatica.GetAlfabeto().GetAlfabeto().size() << std::endl;
  std::set<Simbolo>::iterator it = gramatica.GetAlfabeto().GetAlfabeto().begin();
  for (int i = 0; i < gramatica.GetAlfabeto().GetAlfabeto().size(); i++) {
    os << *it << std::endl;
    it++;
  }

  os << gramatica.GetNoTerminales().size() << std::endl;
  std::set<Noterminal>::iterator it2 = gramatica.GetNoTerminales().begin();
  for (int i = 0; i < gramatica.GetNoTerminales().size(); i++) {
    os << *it2 << std::endl;
    it2++;
  }

  os << gramatica.GetProducciones().size() << std::endl;
  for (int i = 0; i < gramatica.GetProducciones().size(); i++) {
    os << gramatica.GetProducciones()[i] << std::endl;
  }

  return os;
}