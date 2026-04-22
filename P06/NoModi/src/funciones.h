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

#pragma once

#include <iostream>
#include "fa.h"

void usage(const int argc, char* argv[]);
void LeerFicheroFA(std::ifstream& fichero, FA& fa);
void CrearEstados(std::ifstream& fichero, std::vector<Estado>& estados);
void LeerCadenas(std::ifstream& fichero, std::vector<Cadena>& cadenas);
int CogerIdentificador(const std::string& linea);
bool CogerAceptacion(const std::string& linea);
int CogerNumTrancisiones(const std::string& linea);
Simbolo CogerSimbolo(const std::string& linea, const int posicion); 
int CogerDestino(const std::string& linea, const int posicion);
void ImprimirResultados(FA& fa, std::vector<Cadena>& cadenas);