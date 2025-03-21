#include <iostream>
#include <memory>
#include "list_auxiliars.hpp"
#define LOG_FUNCTION_NAME() \
    cout << " in function: " << __func__ << endl;
using namespace std;

shared_ptr<node_t> create_node(int value){
    auto node = make_shared<node_t>();
    node->next = nullptr;
    node->value = value;
    return node;
}

/* Lista con cabeza y cola*/
shared_ptr<list_t> create_list(){
    auto list = make_shared<list_t>();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
    return list;
}

void push_front(shared_ptr<list_t> list, shared_ptr<node_t> node){
    if (!(list && node)) {  //Chequeo  de punteros nulo
        cout << "nullptr entered"; 
        LOG_FUNCTION_NAME();
        return;
    }
    node->next = list->head;
    list->head = node;
    if (list->size == 0) list->tail = list->head; //si el size es 0 es porque estoy insertnado el primer nodo (head = tail)
    list->size++;
}

void push_back(shared_ptr<list_t> list, shared_ptr<node_t> node){
    if (!(list && node)) { //Chequeo  de punteros nulo
        cout << "nullptr entered"; 
        LOG_FUNCTION_NAME(); 
        return;
    }
    if (list->size == 0) { //con lista vacia el push iguala punteros como en front
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void insert(shared_ptr<list_t> list, shared_ptr<node_t> node, int position){
    if (!(list && node)) { //Chequeo  de punteros nulo
        cout << "nullptr entered";
        LOG_FUNCTION_NAME();
        return;
    }
    if (position > list->size-1) { //caso de out of range
        cout << "Position index is greater than list size, pushing node backwards..." << endl;
        push_back(list, node);
    }
    else if (position == 0 || list->size == 0) push_front(list, node); //si quiero insertar al inicio es como hacer push front
    else { //sino busco el nodo a insertar recorriendo toda la lista/complejidad O(n)
        auto current = list->head;
        for (int i = 1; i < position; i++){
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        list->size++;
    }
}

void erase(shared_ptr<list_t> list, int position){
    if (!list) { //Chequeo  de puntero nulo
        cout << "nullptr entered" ; 
        LOG_FUNCTION_NAME(); 
        return;
    }
    if (list->size == 0) {
        cout << "Cant erase from empty list";
        LOG_FUNCTION_NAME();
        return;
    }
    if (position == 0) {
        list->head = list->head->next;
        if (list->size == 1) list->tail = nullptr; // si queda la lista vacía, la cola sera nullptr
        list->size--;
    }
    if (position > list->size-2) { //caso de out of range, borro el tail
        cout << "Position index is greater than list size, cuting list tail..." << endl;
        auto current = list->head;
        while(current->next != list->tail) {
            current = current->next;
        }
        list->tail = current;
        list->tail->next = nullptr;
        list->size--;
    }
    else {
        auto current = list->head;
        for (int i = 0; i < position-1; i++){
            current = current->next;
        }
        current->next = current->next->next;
        if (position == list->size - 1) list->tail = current;
        list->size--;
    }
}

void print_list(shared_ptr<list_t> list){
    if (!list) { //Chequeo  de puntero nulo
        cout << "nullptr entered" ; 
        LOG_FUNCTION_NAME(); 
        return;
    }
    if (list->size == 0) { //Evita printear una lista vacia
        cout << "Cant print an empty list";
        LOG_FUNCTION_NAME();
        return;
    }
    auto current = list->head;
    while (current) {
        cout << current->value;
        if (current->next) {  // Si hay un siguiente nodo, imprimir "->"
            cout << "->";
        }
        current = current->next; //imprimo el ultimo
    }
    cout << endl;
}

void delete_list(shared_ptr<list_t> list) {
    if (!list) { //Chequeo  de puntero nulo
        cout << "nullptr entered"; 
        LOG_FUNCTION_NAME(); 
        return;
    }
    while (list->size != 0) erase(list, 0); //Borro de la cabeza hasta que quede vacia
}