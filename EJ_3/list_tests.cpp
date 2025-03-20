#include <iostream>
#include "list_auxiliars.hpp"

using namespace std;

void run_tests() {
    auto list = create_list();
    
    cout << "Test 1: Imprimir lista vacía" << endl;
    print_list(list); // Debe mostrar "Lista vacía"

    cout << "Test 2: Agregar elementos con push_back y verificar head y tail" << endl;
    push_back(list, create_node(1));
    print_list(list); // Debe mostrar "1 -> null"
    push_back(list, create_node(2));
    push_back(list, create_node(3));
    print_list(list); // Debe mostrar "1 -> 2 -> 3 -> null"
    
    cout << "Test 3: Agregar elementos con push_front" << endl;
    push_front(list, create_node(4));
    print_list(list); // Debe mostrar "0 -> 1 -> 2 -> 3 -> null"

    cout << "Test 4: Insertar en posición intermedia" << endl;
    insert(list, create_node(99), 2);
    print_list(list); // Debe mostrar "0 -> 1 -> 99 -> 2 -> 3 -> null"

    cout << "Test 5: Insertar en índice fuera de rango" << endl;
    insert(list, create_node(100), 10);
    print_list(list); // Debe agregar al final: "0 -> 1 -> 99 -> 2 -> 3 -> 100 -> null"

    cout << "Test 6: Eliminar primer elemento" << endl;
    erase(list, 0);
    print_list(list); // Debe mostrar "1 -> 99 -> 2 -> 3 -> 100 -> null"

    cout << "Test 7: Eliminar último elemento" << endl;
    erase(list, list->size - 1);
    print_list(list); // Debe mostrar "1 -> 99 -> 2 -> 3 -> null"

    cout << "Test 8: Eliminar en posición intermedia" << endl;
    erase(list, 1);
    print_list(list); // Debe mostrar "1 -> 2 -> 3 -> null"

    cout << "Test 9: Intentar eliminar índice fuera de rango" << endl;
    erase(list, 10);
    print_list(list); // No debe cambiar la lista

    cout << "Test 10: Manejo de lista vacía" << endl;
    auto empty_list = create_list();
    erase(empty_list, 0); // No debe crashear
    print_list(empty_list);
    
    cout << "Todos los tests ejecutados." << endl;
}

int main() {
    run_tests();
    return 0;
}
