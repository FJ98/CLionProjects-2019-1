// Created by ruben on 4/5/19.
#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Nodo {
        Location *data;
        Nodo* right;
        Nodo* left;
        Nodo(Location *data);
    };

    class BinarySearchTree {
        Nodo* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Location *data);
        void clear();
        bool is_empty();
        Nodo* get_root();
        Nodo* search(std::string position_id);
        void print();
    };

    //void load_locations(BinarySearchTree* linked_list, std::string file_name);
    void print_node(Nodo* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
