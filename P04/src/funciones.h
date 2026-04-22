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
 * @brief Declaración de las funciones del programa
*/

#pragma once

#include <iostream>
#include <fstream>
#include <regex>

#include "variable.h"
#include "bucle.h"
#include "comentario.h"


void ussage(const int argc, char* argv[]);

bool ComprobarFichero(std::ifstream& entrada);

void BuscarVariables(std::ifstream& entrada, std::vector<Variable>& variables);
void BuscarBucles(std::ifstream& entrada, std::vector<Bucle>& bucles);
void BuscarMain(std::ifstream& entrada, bool& main);
void BuscarComentarios(std::ifstream& entrada, std::vector<Comentario>& comentarios);

void ImprimirDescripcion(std::ofstream& salida, std::vector<Comentario>& comentarios, std::ifstream& entrada);
void ImprimirVariables(std::ofstream& salida, std::vector<Variable>& variables);
void ImprimirBucles(std::ofstream& salida, std::vector<Bucle>& bucles);
void ImprimirMain(std::ofstream& salida, bool main);
void ImprimirComentarios(std::ofstream& salida, std::vector<Comentario>& comentarios);