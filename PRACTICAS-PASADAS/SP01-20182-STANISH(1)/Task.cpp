// Created by felix on 5/5/2019.
#include "Task.h"
#include <iostream>
#include <random>
Task::Task(std::string name) : name{name},runtime{0} {}
SingleTask::SingleTask(std::string name) : Task(name) {}
FaultToleranceTask::FaultToleranceTask(std::string name, int maxAttempts) : Task{name}, maxAttempts{maxAttempts} {}

bool SingleTask::execute() {
    runtime=rand()%61;
    if(runtime%2==0){
        std::cout<<"Nombre de la tarea "<<name<<std::endl;
        std::cout<<"\tTipo: Simple"<<std::endl;
        std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
        std::cout<<"\tResultado de ejecucion: exitosa\n"<<std::endl;
        return true;
    }else{
        std::cout<<"Nombre de la tarea "<<name<<std::endl;
        std::cout<<"\tTipo: Simple"<<std::endl;
        std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
        std::cout<<"\tResultado de ejecucion: fallida\n"<<std::endl;
        return false;
    }
}


bool FaultToleranceTask::execute() {
    std::cout<<"Nombre de la tarea "<<name<<std::endl;
    std::cout<<"\tTipo: Tolerante a fallos"<<std::endl;
    std::cout<<"\tMaximo de intentos: "<<maxAttempts<<std::endl;

    for (int i = 1; i <= maxAttempts; ++i) {
        runtime=(rand()%61)+60;
        std::cout<<"\tIntento No: "<<i<<std::endl;
        std::cout<<"\tTiempo de ejecucion: "<<runtime<<std::endl;
        if(runtime%2!=0){
            std::cout<<"\tResultado de ejecucion: exitosa\n"<<std::endl;
            return true;
        }else{
            std::cout<<"\tResultado de ejecucion: fallida\n"<<std::endl;
        }
    }
    return false;
}



