// Created by felix on 5/25/2019.
#ifndef SMARTPOINTERS_SMARTPOINT_H
#define SMARTPOINTERS_SMARTPOINT_H

#include <utility>
#include <functional>
//---porque usar smart pointer? Porque cuando destruimos muchos Objetos B de manera dinamica
//---no tenemos manera como destruir todos,
/*
class B{
public:
    B(){std::cout << "Construccion del ojeto B" << std::endl;}
    ~B(){std::cout << "Destruccion del ojeto B" << std::endl;}
};
class A{
    B* b;
    int n;
public:
    A() : b{nullptr} {std::cout << "Construccion del ojeto A" << std::endl;}
    A(int n) : n{n} {b = new B[n];}
    ~A(){
        delete [] b;
        std::cout << "Destruccion del ojeto A" << std::endl;
    }
};*/
//---Intro a smart pointers--------------------
/*
template <typename T>
class punteroInteligente{
    T* t;
public:
    punteroInteligente() : t{nullptr} {
        std::cout << "Construccion del ojeto A" << std::endl;
        t = new T();
    }
    punteroInteligente(T value) : t{nullptr} {
        std::cout << "Construccion del ojeto A" << std::endl;
        t = new T();
    }

    ~punteroInteligente(){
        delete t;
        std::cout << "Destruccion del ojeto A" << std::endl;
    }
    T& operator*() {return *t;}
}; */
//-------------------------------------------------------

//--Implementacion de unique_ptr
/*
template <typename T>
class ptr_unico{
    T* data;
public:
    ptr_unico(T *t) : data{t} {std::cout << "Construccion del puntero unico" << std::endl;}
    ptr_unico(ptr_unico& ptrUnico) = delete;
    ~ptr_unico(){ delete data; std::cout << "Destruccion del puntero unico" << std::endl;}
    T& operator*() {return *data;}
};
template <typename T, typename... Types>
ptr_unico<T> make_unico(Types &&... args){
    return( ptr_unico<T>(new T ( std::forward<Types>(args)... ) ) );
}*/
//-----------------------------

//--Implementacion de shared_ptr [FALTA COMPLETAR]
/*
template <typename T, typename... Types>
ptr_compartido<T> make_compartido(Types &&... args){
    return( ptr_compartido<T>(new T ( std::forward<Types>(args)... ) ) );
}
template <typename T>
class ptr_compartido{
    T* data;
    size_t* sz;
public:
    ptr_compartido(T *t) : data{t} {std::cout << "Construccion del puntero unico" << std::endl;}
    ptr_compartido(ptr_compartido& ptrUnico) = delete;
    ~ptr_compartido(){ delete data; std::cout << "Destruccion del puntero unico" << std::endl;}
    T& operator*() {return *data;}
}; */
//-----------------------



#endif //SMARTPOINTERS_SMARTPOINT_H
