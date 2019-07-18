#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include <list>
#include "Funciones.h"
#include "LinkedListLock.h"
#include "TBT.h"

using namespace std;
mutex mtx;

void saludo(int i) {
    lock_guard<mutex> lock(mtx);
    cout << "Hilo #:" << i << endl;
}
void acumular(int& total) {
    lock_guard<mutex> lock(mtx);
    total += 2;
}
void producer(promise<string> p) {
    p.set_value("Valor Obtenido del thread");
}
void acumulador(vector<int>& v, int start, int stop, promise<int> p) {
    int total = 0;
    try {
        for (int i = start; i < stop; i++)
            total += v[i];
        p.set_value(total);
        }
    catch (...) {
        p.set_exception(current_exception());
    }
}
int main() {
    std::vector<int> v2 = {1,2,3,4,5};
    try {
        vector<int> v1 = {4, 5, 6, 7, 8, 9, 10};
        promise<int> prm;
        future<int> ftr = prm.get_future();
        thread t3(acumulador, std::ref(v1), 2, 5,  std::move(prm));
        std::cout << "0) Ejemplo de future y promise: " << ftr.get() << endl;
        t3.join();
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

//--EJERCICIO 1 PPT-------------------------------------
    std::cout << "1) Suma de elementos del vector v2 (usando hilos): " << sumar(v2) << std::endl;
    std::vector<int> v = {10,20,30,30,20,10,10,20};
    std::vector<int> vresult = eliminar(v, 20);
//------------------------------------------------------

//--EJERCICIO 2 PPT-------------------------------------
    std::cout << "2) Vector con el 20 eliminado (usando hilos): ";
    for (auto item: vresult){
        std::cout << item << " ";
    } std::cout << std::endl;
//------------------------------------------------------

//--EJERCICIO 4 PPT-------------------------------------
    std::vector<int> z = {2,7,6,0,5,1,3,4};
    std::vector<int> vOrdenado = mergeSort(z);
    std::cout << "4) MergeSort Con hilos: ";
    for (auto item: vOrdenado){
        std::cout << item << " ";
    } std::cout << std::endl << std::endl;
//------------------------------------------------------

//--EJERCICIO 3 PPT-------------------------------------
    LinkedListLock list;
    list.pushBack(3); list.pushBack(10);
    list.pushBack(1); list.pushBack(7);
    list.pushBack(9); list.pushBack(12);
    std::cout << "3) Lista Original: "; list.print();
    //list.insert(200, 2); list.print();
    int ins1 = 20, pos1 = 2, ins2 = 40, pos2 = 4;
    std::cout << "\tInsert con hilos: ";
    //LinkedListLock lbc = list.testInsertConHilos(ins1, pos1);
    LinkedListLock lbc = list.testInsert2ConHilos(ins1, pos1, ins2, pos2);
    lbc.print(); std::cout << std::endl;
//------------------------------------------------------

//--EJERCICIO 5 PPT-------------------------------------
    // SIN HILOS
    /*ThreadedBinaryTree tbt;
    tbt.insert(4); tbt.insert(20); tbt.insert(3); tbt.insert(5);
    tbt.print();*/
    ThreadedBinaryTree tbtConHilos;
    tbtConHilos.testInsertConHilos(4);
    tbtConHilos.testInsertConHilos2(2, 10);
    std::cout << "5) TBT con insert con hilos: "; tbtConHilos.print();

//------------------------------------------------------

//    int n = 100;
//    int total = 0;
//    for(int i = 0; i < n; i++) {
//        h2.emplace_back(acumular, ref(total));
//    }
//    for(int i = 0; i < n; i++) {
//        h2[i].join();
//    }
//
//    cout << total;

//    for(int i = 0; i < n; i++) {
//        //hilos.push_back(thread(saludo, i));
//        h1.emplace_back(saludo, i);
//    }
//
//
//    for(int i = 0; i < n; i++) {
//        h1[i].join();
//    }

    //thread t1(saludo);
    //std::cout << "Hello, World!" << std::endl;
    //t1.detach();
    return 0;
}