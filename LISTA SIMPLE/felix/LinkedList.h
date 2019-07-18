#include "Location.h"


#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

namespace UTEC {

    struct Node{
        Location *data;
        Node *next;
        Node (Location *data);
    };

    class LinkedList {
        Node *head = nullptr;
        Node *tail = nullptr;
    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool is_empty();
        Node* get_head();
        Node* get_tail();
        void add_head(Location *data);
        void add_tail(Location *data);
        void print();
        void insert(int position, Location *data);
        Node *search(int position_id);
  
    };

    void load_locations_link(LinkedList *linkedList, std::string file_name);

}


#endif //LINKED_LIST_LINKEDLIST_H
