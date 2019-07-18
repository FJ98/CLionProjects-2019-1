struct Nodo{
    Nodo* prev;
    Nodo* next;
    int dato;

    Nodo(int dato);
    Nodo();
};

class Pila {
    Nodo* top;
    int size;
public:
    Pila();
    void push(int value);
    Nodo pop();
    bool IsEmpty();
    int Size();
    Nodo* Peek();
    Nodo* GetTop();
    void print();
};

