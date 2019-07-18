//
// Created by luis0 on 9/04/2019.
//
#include "LinkedList.h"
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>


using std::cout;
using std::cin;
using std::endl;
UTEC::Node::Node(Location *data) : data(data), next(nullptr) {}
UTEC::LinkedList::LinkedList() {}

UTEC::LinkedList::~LinkedList() {
    Node *recorrer = head;
    Node *eliminar = head;
    while(recorrer!=nullptr){
       // std::cout<<"Elimino "<<recorrer->data->get_id()<<std::endl;
        delete recorrer->data;
        recorrer = recorrer->next;
        delete eliminar;
        eliminar = recorrer;
    }
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {return head == nullptr;}
UTEC::Node *UTEC::LinkedList::get_head() {return head;}
UTEC::Node *UTEC::LinkedList::get_tail() {return tail;}

void UTEC::LinkedList::add_tail(Location *data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    //data->imprimir();
}
void UTEC::LinkedList::add_head(Location *data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    //data.imprimir();
}

void UTEC::LinkedList::print() {
    Node *buscar = head;
    while(buscar!= nullptr){
        buscar->data->imprimir();
        buscar = buscar->next;
    }
}

void UTEC::LinkedList::insert(int position, Location *data){
    Node *buscar = head;
    int actual_position = 0;
    if(position == 0){
        this->add_head(data);
    }
    else{
        actual_position++;
        while(position!=actual_position){
            buscar = buscar->next;
            actual_position++;
        }
        
        Node *nuevo = new Node(data);
        nuevo->next = buscar->next;
        buscar->next =nuevo;
    }
}

UTEC::Node *UTEC::LinkedList::search(int position_id) {
    Node *buscar = head;
    do{
        if(buscar->data->get_id() == position_id){
            return buscar;
        }
        buscar = buscar->next;
    }while(buscar!=nullptr);

    return nullptr;
}
void UTEC::load_locations_link(UTEC::LinkedList *linked_list, std::string file_name) {
    std::ifstream in(file_name);
    Location *local;
    //std::vector<std::vector<std::string>> fields;
    bool bandera=false;
    //int contador = 0;
    std::vector<std::string> datos;
    if (in) {
        std::string line;
        while (getline(in, line)) {
            std::stringstream sep(line);
            std::string field;
            //fields.push_back(std::vector<std::string>());
            while (getline(sep, field, ',')) {
                // cout<<i<<endl;
                datos.push_back(field);
                
            }
            if(bandera){
                local = new Location(std::stoi(datos[0]),datos[1],datos[2],std::stod(datos[3]),
                                      std::stod(datos[4]),datos[5],datos[6]);
                linked_list->add_tail(local);
            }
            bandera=true;
            datos.clear();
        }
    }
}