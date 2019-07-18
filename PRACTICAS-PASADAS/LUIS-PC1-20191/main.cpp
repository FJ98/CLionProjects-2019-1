#include <iostream>

struct node{
    int data;
    node *next;
    node(int data):data(data),next(nullptr){};
};

class list{
    node *head;
    node *tail;
    int tam;
public:
    list(int tam) : tam(tam),head(nullptr),tail(nullptr){};
    void push_back(int data){
        node *temporal = new node(data);
        if(tam>0){
            tail->next=temporal;
            tail = temporal;
        }
        else{
            head = temporal;
            tail = temporal;
        }
        tam++;
    }

    void push_front(int data){
        node *temporal = new node(data);
        if(tam>0){
            temporal->next = head;
            head = temporal;
        }
        else{
            head = temporal;
            tail = temporal;
        }
        tam++;
    }

    void pop_front(){
        node *remover = head;
        head = head->next;
        //head = remover->next;
        delete remover;
        tam--;
    }

    void pop_back(){
        node *remover = head;
        while(remover->next!=tail){
            remover = remover->next;
        }
        tail = remover;
        delete remover->next;
        tail->next = nullptr;
        tam--;
    }

    void print(){
        node *buscar = head;
        int actual = 0;
        do{
            std::cout<<buscar->data<<" - ";
            buscar=buscar->next;
            actual++;
        }
        while(actual!=tam);

        std::cout<<"\n\n";
    }
    void printInversa(){
        node* actSiguiente;
        node* previous = nullptr;
        node* actual = head;
        while(actual!= nullptr){
            std::cout<<actual->data<<" - ";
            actSiguiente=actual->next;
            actual->next=previous;
            previous=actual;
            actual=actSiguiente;
        }
        head=previous;
        std::cout<<"\n";
    }

    int tamanio(){return tam;}

    bool empty(){
        return tam<=0;
    }

    bool lazo(){
            return (tail->next != nullptr);
    }

    void circular(int posicion, int data){
        node *buscar =  head;
        node *temporal = new node(data);
        tail->next=temporal;
        tail = temporal;
        int pos_actual = 0;
        while(pos_actual != posicion){
            pos_actual++;
            buscar = buscar->next;
        }
        tail->next = buscar;
        tam++;
    }

    void insert(int posicion,int data){
        int pos_actual = 0;

        if(posicion==0){
            push_front(data);
        }
        else if(posicion==tam){
            push_back(data);
        }
        else{
            pos_actual++;
            node *buscar = head;
            while(pos_actual!=posicion){
                buscar = buscar->next;
                pos_actual++;
            }
            node *nuevo = new node(data);
            nuevo->next = buscar -> next;
            buscar->next = nuevo;
            tam++;
        }

    }



};

int main() {

    list *lista = new list(0);

    std::cout<<lista->empty()<<std::endl;

    for(int i=0;i<10;i++){
        lista->push_back(i);
    }

    lista->print();
    //lista->printInversa();

    for(int i=5;i>0;i--){
        lista->push_front(i);
    }

    lista->print();

    lista->pop_front();

    lista->print();

    lista->pop_back();

    lista->print();

    std::cout<<lista->empty()<<std::endl;
    lista->insert(3,500);
    lista->insert(0,1000);
    lista->insert(15,-123);

    lista->print();

    std::cout<<lista->tamanio()<<std::endl;
    std::cout<<lista->lazo()<<std::endl;
    lista->circular(4,40000);

    lista->print();

    std::cout<<lista->tamanio()<<std::endl;
    std::cout<<lista->lazo()<<std::endl;
    delete lista;

    return 0;
}
