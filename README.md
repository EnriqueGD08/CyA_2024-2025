# CyA_2024-2025

Prácticas de programación de Computabilidad y Algoritmia (CyA) en el curso 2024-2025, Grado en Ingeniería Informática, Universidad de La Laguna.

**Autor:** Enrique Gómez Díaz  
**Correo:** alu0101550329@ull.edu.es

## Descripción General

Este repositorio contiene las prácticas realizadas en la asignatura de Computabilidad y Algoritmia del segundo curso del Grado en Ingeniería Informática. Las prácticas cubren temas fundamentales como teoría de autómatas, gramáticas formales, análisis de código, y algoritmos sobre grafos.

## Prácticas

### Práctica 2: Alfabetos, Cadenas y Lenguajes

**Ubicación:** `P02/`

**Descripción:**
Implementación de clases para manipular alfabetos, cadenas y lenguajes formales. El programa permite realizar operaciones básicas sobre cadenas y validar que pertenezcan a un alfabeto específico.

**Funcionalidades principales:**
- Creación y gestión de alfabetos (conjuntos de símbolos)
- Manipulación de cadenas de caracteres
- Cálculo de la longitud de una cadena
- Inversión de cadenas
- Generación de prefijos de una cadena
- Generación de sufijos de una cadena
- Validación de pertenencia de una cadena a un alfabeto

**Uso:**
```bash
cd P02/build
./Pr2 <archivo_entrada> <archivo_salida> <opción>
```

Donde `<opción>` puede ser:
- `1`: Obtener alfabeto de la cadena
- `2`: Obtener longitud de la cadena
- `3`: Obtener inversa de la cadena
- `4`: Obtener prefijos de la cadena
- `5`: Obtener sufijos de la cadena

---

### Práctica 4: Analizador de Código C++

**Ubicación:** `P04/`

**Descripción:**
Desarrolla un analizador léxico y sintáctico de código C++ que identifica componentes del programa como variables, bucles, función principal y comentarios.

**Funcionalidades principales:**
- Buscar y extraer declaraciones de variables del código C++
- Identificar bucles (for, while, do-while)
- Detectar presencia de la función `main()`
- Extraer y procesar comentarios (simples y de bloque)
- Generar un reporte detallado con toda la información extraída

**Uso:**
```bash
cd P04
make
./build/programa <archivo_entrada> <archivo_salida>
```

**Ejemplo:**
```bash
./build/programa entrada.cc salida.txt
```

---

### Práctica 6: Autómatas Finitos (FA)

**Ubicación:** `P06/` (con versiones `Modi/` y `NoModi/`)

**Descripción:**
Implementación de autómatas finitos deterministas y no deterministas. El programa lee la definición de un autómata finito desde un archivo y valida si un conjunto de cadenas pertenecen al lenguaje reconocido por dicho autómata.

**Funcionalidades principales:**
- Definición de autómatas finitos (estados, alfabeto, transiciones, estados de aceptación)
- Lectura de definiciones de autómatas desde archivos
- Implementación de la función de transición
- Cálculo de la clausura épsilon (epsilon-closure) para AFN
- Validación de cadenas contra el autómata
- Clasificación de cadenas como aceptadas o rechazadas

**Uso:**
```bash
cd P06/Modi  # o P06/NoModi
make
./build/automata <archivo_definicion> <archivo_cadenas>
```

**Formato de entrada:**
- Archivo de definición del autómata con estados, transiciones y configuración
- Archivo con cadenas a validar

---

### Práctica 8: Gramáticas en Forma Normal de Chomsky (FNC)

**Ubicación:** `P08/` (con versiones `Modi/` y `NoModi/`)

**Descripción:**
Implementa la transformación de gramáticas libres de contexto a Forma Normal de Chomsky. Una gramática en FNC es útil para muchos algoritmos de análisis sintáctico como el algoritmo CYK.

**Funcionalidades principales:**
- Lectura de definiciones de gramáticas libres de contexto
- Eliminación de producciones epsilon (vacías)
- Eliminación de producciones unitarias
- Conversión a forma normal de Chomsky donde:
  - Cada producción es de la forma `A → BC` (dos no terminales) o `A → a` (un terminal)
- Generación de la gramática equivalente en FNC
- Salida de la gramática transformada

**Uso:**
```bash
cd P08/Modi  # o P08/NoModi
make
./build/gramaticaFNC <archivo_entrada.gra> <archivo_salida.gra>
```

**Ejemplo:**
```
Entrada: Gramática con producciones arbitrarias
Salida: Gramática equivalente en Forma Normal de Chomsky
```

---

### Práctica 11: Árbol Generador Mínimo (MST)

**Ubicación:** `P11/`

**Descripción:**
Implementación del algoritmo de Prim para encontrar el Árbol Generador Mínimo (Minimum Spanning Tree) de un conjunto de puntos en el plano. Calcula el conjunto de aristas que conectan todos los puntos con costo total mínimo utilizando distancias euclidianas.

**Funcionalidades principales:**
- Lectura de conjuntos de puntos desde archivos
- Cálculo de distancias euclidianas entre puntos
- Implementación del algoritmo de Prim para MST
- Generación del árbol generador mínimo
- Cálculo del costo total del árbol
- Exportación del árbol en formato DOT (Graphviz) para visualización
- Generación de reportes con resultados

**Uso:**
```bash
cd P11
make
./build/MinimumSpanningTree <archivo_entrada> <archivo_salida> [-d <archivo_dot>]
```

**Opciones:**
- `<archivo_entrada>`: Archivo con coordenadas de puntos
- `<archivo_salida>`: Archivo de salida con el resultado del MST
- `-d <archivo_dot>`: (Opcional) Generar archivo DOT para visualizar el árbol

**Ejemplo:**
```bash
./build/MinimumSpanningTree input1.txt salida.txt -d resultado.dot
```

---

## Estructura del Repositorio

```
CyA_2024-2025/
├── P02/                 # Alfabetos y cadenas
│   ├── src/
│   │   ├── alfabeto.cc/.h
│   │   ├── cadena.cc/.h
│   │   ├── lenguaje.cc/.h
│   │   ├── funciones.cc/.h
│   │   └── main.cc
│   ├── CMakeLists.txt
│   └── build/
├── P04/                 # Analizador de C++
│   ├── src/
│   │   ├── variable.cc/.h
│   │   ├── bucle.cc/.h
│   │   ├── comentario.cc/.h
│   │   ├── funciones.cc/.h
│   │   └── analizador.cc
│   ├── Makefile
│   └── build/
├── P06/                 # Autómatas Finitos
│   ├── Modi/           # Versión modificada
│   │   ├── src/
│   │   │   ├── fa.cc/.h
│   │   │   ├── estado.cc/.h
│   │   │   ├── transicion.cc/.h
│   │   │   ├── cadena.cc/.h
│   │   │   ├── alfabeto.cc/.h
│   │   │   ├── funciones.cc/.h
│   │   │   └── fa_main.cc
│   │   ├── Makefile
│   │   └── build/
│   └── NoModi/         # Versión original
│       └── ...
├── P08/                 # Gramáticas FNC
│   ├── Modi/
│   │   ├── src/
│   │   │   ├── gramatica.cc/.h
│   │   │   ├── produccion.cc/.h
│   │   │   ├── noterminales.cc/.h
│   │   │   ├── alfabeto.cc/.h
│   │   │   ├── funciones.cc/.h
│   │   │   └── cnf_main.cc
│   │   ├── Makefile
│   │   └── build/
│   └── NoModi/
│       └── ...
├── P11/                 # Árbol Generador Mínimo
│   ├── src/
│   │   ├── point_set.cc/.h
│   │   ├── sub_tree.cc/.h
│   │   ├── datos.cc/.h
│   │   └── sp_tree.cc
│   ├── Makefile
│   └── build/
├── README.md
└── LICENSE
```

## Compilación

Cada práctica puede compilarse individualmente:

**P02 (CMake):**
```bash
cd P02
cmake -B build
cd build && make
```

**P04, P06, P08, P11 (Makefile):**
```bash
cd P0X
make
```

Para limpiar los archivos compilados:
```bash
make clean
```

## Requisitos

- Compilador C++ (g++ 11 o superior)
- CMake (para P02)
- Make (para P04, P06, P08, P11)
- Estándares C++11 o superior

## Licencia

Este proyecto está bajo licencia según se especifica en el archivo `LICENSE`.
