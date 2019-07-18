// Created by ruben on 4/5/19.
#include "BinarySearchTree.h"

UTEC::BinarySearchTree::BinarySearchTree() {
    //Completar
    root = nullptr;
}

UTEC::BinarySearchTree::~BinarySearchTree() {
    //Completar
}

void UTEC::BinarySearchTree::insert(Location *data) {
    //Completar
    Nodo *llenar = new Nodo(data);

}

void UTEC::BinarySearchTree::clear() {
    //Completar
}

bool UTEC::BinarySearchTree::is_empty() {
    //Completar
    return false;
}

UTEC::Nodo *UTEC::BinarySearchTree::get_root() {
    //Completar
    return nullptr;
}

UTEC::Nodo *UTEC::BinarySearchTree::search(std::string position_id) {
    //Completar
    return nullptr;
}

void UTEC::BinarySearchTree::print() {
    //Completar
}

/*void UTEC::load_locations(BinarySearchTree* linked_list, std::string file_name){
    //Completar
}
*/
void UTEC::print_node(Nodo* node){
    //Completar
}

UTEC::Nodo::Nodo(Location *data): data(data), right(nullptr), left(nullptr){}