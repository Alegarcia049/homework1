#include <iostream>
#include <vector>
#include "matrix_auxiliars.hpp"

using namespace std;

int main(){
    vector<vector<int>> matrix;
    try {
        int n;
        cout << "Enter a positive natural number: ";
        while (!(cin >> n) || n <= 0) { //ensures n is an (int) greater than 0 and requests new entry
            cin.clear();
            cout << "Invalid entry, try again: ";
        }
        matrix = matrix_gen(n);
    }
    catch (const bad_alloc& e) { //if memory allocation for the matrix fails
        cerr << "Error: Could not assign memory for the matrix " << e.what() << endl;
        return 1;
    }
    matrix_print(matrix);
}