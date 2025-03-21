# HOMEWORK 1

## Descripción

Introducción a C++, librería estándar, punteros, funciones y manejo de memoria.

## Requisitos

- **Compilador:** g++ (compatible con C++20)
- **Sistema Operativo:** Windows / Linux / MacOS  
- **Flags de compilación:** `-std=c++20 -Wall -g`  

Cada carpeta contiene los archivos fuente (`.cpp`) y de cabecera (`.hpp`) necesarios para compilar y ejecutar los ejercicios.

---

## EJ_1

Las funciones utilizadas se encuentran en el archivo `matrix_auxiliars.cpp`.  
El archivo `matrix_generator.cpp` contiene el `main` con su uso.  

### **Compilación y ejecución:**

```sh
g++ -std=c++20 matrix_auxiliars.cpp matrix_generator.cpp -Wall -g -o matrix
./matrix
```

---

## EJ_2

Las funciones auxiliares se encuentran en `log_auxiliars.cpp`, mientras que `log_tests.cpp` contiene los tests y ejemplos de uso.

### **Compilación y ejecución:**

```sh
g++ -std=c++20 log_auxiliars.cpp log_tests.cpp -Wall -g -o logger
./logger
```

---

## EJ_3

Las funciones auxiliares se encuentran en `list_auxiliars.cpp`, mientras que `list_tests.cpp` contiene los tests y ejemplos de uso.

### **Compilación y ejecución:**

```sh
g++ -std=c++20 list_auxiliars.cpp list_tests.cpp -Wall -g -o tests
./tests
```

---

## EJ_4

Este ejercicio implementa y compara dos enfoques de procesamiento:

Compilación estática: `compare_compiled.cpp`
Ejecución en tiempo de ejecución: `compare_runtime.cpp`

### **Compilación y ejecución:**

```sh 
g++ -std=c++20 compare_compiled.cpp -Wall -g -o compare_test //Para compilador
g++ -std=c++20 compare_runtime.cpp -Wall -g -o compare_test //Para runtime.
./compare_test
```

## Notas Finales

- Se recomienda utilizar -Wall y -g en la compilación para habilitar todas las advertencias y facilitar la depuración.
- Si encuentras algún problema o bug, revisa los comentarios en el código y verifica los asserts en los tests.