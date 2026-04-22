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

#pragma once

#include <iostream>
#include <fstream>
#include "alfabeto.h"
#include "cadena.h"

void ussage(const int argc, char* argv[]);
std::string obtenerCadena(const std::string& line, int& contador);
std::string obtenerAlfabeto(const std::string& line, int& contador);
void comprobarAlfabeto(Cadena& cadena, Alfabeto& alfabeto);