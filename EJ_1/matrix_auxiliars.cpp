#include <vector>
#include <iostream>
#include "matrix_auxiliars.hpp"

using namespace std;

vector<vector<int>> matrix_gen(int n){
    vector<vector<int>> matrix(n, vector<int>(n));
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = val++;
        }
    }
    return matrix;
}

void matrix_print(vector<vector<int>> matrix) {
    const char* subindices[] = {"₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉"};
    int size = matrix.size() - 1; //me quedo con el size para controlar los indices luego
    int i = size;
    for (int x = size; i >= 0; x--) { //iterador para ver fila(i) y columna (x) de la matriz
        if (x < 0) { //si x < 0 quiere decir que se termino de imprimir esa fila
            x = size;
            i--; //entonces subimos a la fila de arriba (valores menores)
        }
        if (i < 0) return; //ahora si i < 0 quiere decir que se termino con la columna indice 0, osea que se imprimió toda la matriz
        cout << "M" << subindices[size] << "[" << i << "]";
        cout << "[" << x << "] = " << matrix[i][x] << "\n";
    }
}