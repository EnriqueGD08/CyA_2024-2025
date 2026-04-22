  
#include "transicion.h"

/**
 * @brief Constructor por defecto de la clase Transicion
*/
Transicion::Transicion() {}

/**
 * @brief Constructor parametrizado de la clase Transicion
 * @param simbolo Símbolo de la transición
 * @param estado_destino Estado destino de la transición
*/
Transicion::Transicion(const Simbolo simbolo, const int estado_destino) {
  simbolo_ = simbolo;
  estado_destino_ = estado_destino;
}

/**
 * @brief Destructor de la clase Transicion
*/
Transicion::~Transicion() {}

/**
 * @brief Método que devuelve el símbolo de la transición
 * @return Símbolo de la transición
*/
Simbolo Transicion::GetSimbolo() const {
  return simbolo_;
}

/**
 * @brief Método que devuelve el estado destino de la transición
 * @return Estado destino de la transición
*/
int Transicion::GetEstadoDestino() const {
  return estado_destino_;
}

/**
 * @brief Método que modifica el símbolo de la transición
 * @param simbolo Símbolo de la transición
*/
void Transicion::SetSimbolo(const Simbolo simbolo) {
  simbolo_ = simbolo;
}

/**
 * @brief Método que modifica el estado destino de la transición
 * @param estado_destino Identificador del estado destino de la transición
*/
void Transicion::SetEstadoDestino(const int estado_destino) {
  estado_destino_ = estado_destino;
}