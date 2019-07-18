#include <iostream>
#include <exception>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
using namespace std;
mutex mtx;
/*
double div(double a, double b, int& error){
    if (b == 0){
        throw std::string("Division de Cero");
    }
    //std::except{//catch("sofas");};

}
*/
void saludo(int i){
    mtx.lock();
    std::cout << "Hilo #: " << i << std::endl;
    mtx.unlock();
}

void acumular(int &total){
    this_thread::sleep_for(chrono::seconds(6));
    mtx.lock();
    total += 2;
    mtx.unlock();
}

void producer(promise<std::string> p ){
    p.set_value("Valor obtenido del thread");
}

void acumulador(std::vector<int>& v, int start, int stop, promise<int> p){
    int total = 0;
    for (int i = start; i < stop; ++i) {
        total += v[i];
    }
    p.set_value(total);
}


void f1(){
    std::cout << "Mi primer thread" << std::endl;
}
void f2(){
    std::cout << "Mi segundo thread" << std::endl;

}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    //int error = 0; auto res = div(10,0,error);
    //if (error != 0){std::cout << "Division de Cero";}
    //else{std::cout << "La division es: " << res;}
    //std::thread t1(f1);std::thread t2(f2);
    //t1.join();t2.join();std::cout<<std::endl;
    /*
    std::vector<thread> h2;
    int n = 4;
    h2.reserve(n);
    for (int i = 0; i < n; ++i) {
        //h2.push_back(thread(saludo, i));
        h2.emplace_back(saludo, i);
    }
    for (int j = 0; j < n; ++j) {
        h2[j].join();
    }
    */
    /*
    std::vector<thread> h2;
    int n = 100, total = 0;
    h2.reserve(n);
    for (int i = 0; i < n; ++i) {
        //h2.push_back(thread(acumular, i));
        h2.emplace_back(acumular, std::ref(total));
    }
    for (int j = 0; j < n; ++j) {
        h2[j].join();
    }
    std::cout << total << std::endl;
    */
    std::vector<thread> h1;
    std::vector<thread> h2;

    std::vector<int> v1 = {4,5,6,7,8,9,10};
    promise<int> prm;
    future<int> ftr = prm.get_future();
    std::thread t3(producer, std::move(prm));
    std::cout << ftr.get();
    t3.join();
    return 0;
}