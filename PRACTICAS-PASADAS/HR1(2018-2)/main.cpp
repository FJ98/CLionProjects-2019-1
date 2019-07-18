#include <iostream>
#include <random>

class Task{
protected: //Tiene que ser protected si va a haber herencia
    std::string name{}; // Nombre de la tarea
    int runtime{}; // Tiempo de la tarea
public:
    explicit Task(std::string &p_name);// Constructor que recibe el nombre de la tarea
    virtual bool execute()=0; // Funcion virtual execute que cada clase hija heredara(Herencia) y utilizara la funcion de diferente manera(Polimorfismo)
};

Task::Task(std::string &p_name) : name(p_name), runtime(0) {} // Member Initialization del constructor de la clase Task
//Task::Task(std::string &p_name){this->name=p_name;} <- Tambien se puede escribir asi creo

class SingleTask:public Task{
public:
    explicit SingleTask(std::string name):Task(name) {}
    bool execute() override {
        runtime=rand()%60; // Dando al tiempo de ejecucion(runtime) un numero aleatorio de 0 a 60.
        if(runtime % 2 == 0) // Si runtime es par la tarea fue exitosa
        {
            std::cout<<"Nombre de la Tarea: "<<name<<std::endl;
            std::cout<<"\tTipo: "<<"Simple"<<std::endl;
            std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
            std::cout<<"\tResultado de ejecucuion: "<<"exitosa\n"<<std::endl;
            return true;
        }else{ // Si runtime es impar la tarea fue fallida
            std::cout<<"Nombre de la Tarea: "<<name<<std::endl;
            std::cout<<"\tTipo: "<<"Simple"<<std::endl;
            std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
            std::cout<<"\tResultado de ejecucuion: "<<"fallida\n"<<std::endl;
            return false;
        }
    }
};
class FaultToleranceTask:public Task{
private:
    int maxAttempt; // Numero de intentos para la tarea tolerante a fallos
public:
    FaultToleranceTask(std::string name, int maxAttempt) : Task(name), maxAttempt(maxAttempt) {};
    bool execute() override {
        std::cout<<"Nombre de la Tarea: "<<name<<std::endl;
        std::cout<<"\tTipo: "<<"Tolerante a fallos"<<std::endl;
        std::cout<<"\tMaximo de intentos: "<<maxAttempt<<std::endl;
        for (int i = 0; i < maxAttempt; ++i)
        {
            runtime=rand()%61+60; // Dando al tiempo de ejecucion(runtime) un numero aleatorio de 60 a 120.
            if(runtime % 2 == 0) // Si runtime es par la tarea fue fallida
            {
                std::cout<<"\tIntento numero: "<<i+1<<std::endl;
                std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
                std::cout<<"\tResultado de ejecucuion: "<<"fallida\n"<<std::endl;
            }
            else{ // Si runtime es impar la tarea fue exitosa
                std::cout<<"\tIntento numero: "<<i+1<<std::endl;
                std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
                std::cout<<"\tResultado de ejecucion: "<<"exitosa\n"<<std::endl;
                break;
            }
        }
    }
};
struct Node{
    Node* next; //Puntero que apunta a Node
    Task* task; // Puntero que apunta a task
    Node(Task* p_task, Node* p_next):task(p_task), next(p_next){} // Inicializando el constructor con los parametros y los atributos
    //Node(Task* p_task, Node* p_next){this->task=p_task; this->next=p_next;} <- Tambien se puede escribir asi
};
class Queue{
private:
    Node* first; // Puntero que apunta a un Nodo
    Node* last; // Puntero que apunta a un Nodo
public:
    Queue()= default; // Constructor vacio, constructor por defecto, es igual a poner -> Queue(){first=nullptr;last=nullptr;}
    void enqueue(Task* task) //Anadir tareas, recibe como parametro un puntero que apunta a un Task.
    {
        if(last == nullptr) // Si last no apunta a nada entonces solo hay una sola tarea
        {
            Node* p = new Node(task , nullptr);// P es una puntero que apunta a un Nodo que tiene una primera tarea pero que NO tiene una siguiente Nodo
            first = p; // First ahora apunta a un Nodo
            last = p; // Last ahora apunta a un Nodo que es el mismo Nodo al cual apunta First
        }
        else{ // Si last apunta a algo entonces hay mas de una tarea
            Node* p = new Node(task , nullptr);// P es una puntero que apunta a un Nodo que tiene una primera tarea pero que NO tiene una siguiente Nodo
            last -> next = p; // El atributo Last de la clase Queue accede al atributo next de la estructura Node y este atributo next toma el valor de un Nodo con una tarea.
            last = p; // Last ahora toma el valor de p que es un Nodo ahora
        }
    }
    Task* dequeue() // Borrar tareas
    {
        if(first!= nullptr) // Si first apunta a un Nodo entonces debe apuntar al siguiente Nodo y asi se borraria al que dejo de apuntar
        {
            first=first->next; // First entonces apunta a la siguiente tarea
            return first->task; // Se retorna la tarea que fue borrada
        }else{
            return nullptr;// Si first == nullptr entonces retornar nullptr
        }
    }
    bool isEmpty(){
        return first == nullptr;// La cola (Queue) esta vacia cuando el first no apunta a nada
    }
    ~Queue() = default; // Destructor de la cola
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // srand(time(0)); Random seed
    auto hello = new Queue(); //Queue* hello = new Queue();
    Task* ft1 = new FaultToleranceTask("ols" , 10);
    Task* ft2 = new FaultToleranceTask("oli" , 8);
    Task* ft3 = new FaultToleranceTask("uwu" , 6);
    Task* ft4 = new FaultToleranceTask("dis" , 15);
    Task* ft5 = new FaultToleranceTask("per" , 8);
    Task* st1 = new SingleTask("aja");
    Task* st2 = new SingleTask("dsl");
    Task* st3 = new SingleTask("acm");
    Task* st4 = new SingleTask("cpc");
    Task* st5 = new SingleTask("her");
    hello->enqueue(ft1);
    hello->enqueue(st1);
    hello->enqueue(ft2);
    hello->enqueue(st2);
    hello->enqueue(ft3);
    hello->enqueue(st3);
    hello->enqueue(ft4);
    hello->enqueue(st4);
    hello->enqueue(ft5);
    hello->enqueue(st5);
    for(int i = 0 ; i < 10 ; i++){
        hello->dequeue()->execute();
    }
    delete hello;
    return 0;
}