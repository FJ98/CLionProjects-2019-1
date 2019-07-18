// Created by felix on 5/8/2019.
#ifndef INC_1_SESION_ARREGLO_H
#define INC_1_SESION_ARREGLO_H

template <typename T>
class Arreglo {
    T * arr;
    int n;
public:
    Arreglo():arr{nullptr}, n{0} {std::cout<<"Template de clase generica "<<std::endl;}
    int size() {return 0;}
    int get_item(int index) {return arr[index];}
    void add_item(T value) {
        T* nuevo = new T[n+1];
        //mover al vacio
        for (int i = 0; i < n; ++i) {
            nuevo[i]=arr[i];
        }
        nuevo[n]=value;
        n++;
        delete [] arr;
        arr=nuevo;
    }
};
template <>
class Arreglo<int>{
public:
    Arreglo(){std::cout<<"Template de clase especifica "<<std::endl;}
};


#endif //INC_1_SESION_ARREGLO_H
