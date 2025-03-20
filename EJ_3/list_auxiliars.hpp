#pragma once

#include <iostream>
#include <memory>
#define LOG_FUNCTION_NAME() \
    cout << " in function: " << __func__ << endl;
using namespace std;

struct node;
typedef struct node node_t;

struct list;
typedef struct list list_t;

struct node {
    int value;
    shared_ptr<node_t> next;
};

struct list {
    shared_ptr<node_t> head;
    shared_ptr<node_t> tail;
    int size;
};

shared_ptr<node_t> create_node(int value);
shared_ptr<list_t> create_list();
void push_front(shared_ptr<list_t> list, shared_ptr<node_t> node);
void push_back(shared_ptr<list_t> list, shared_ptr<node_t> node);
void insert(shared_ptr<list_t> list, shared_ptr<node_t> node, int position);
void erase(shared_ptr<list_t> list, int position);
void print_list(shared_ptr<list_t> list);
void delete_list(shared_ptr<list_t> list);