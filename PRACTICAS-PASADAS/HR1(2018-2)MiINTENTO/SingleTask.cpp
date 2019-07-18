// Created by felix on 3/31/2019.
#include "SingleTask.h"

SingleTask::SingleTask(std::string name) : Task(name) {}

bool SingleTask::execute() {
    runtime=rand()%61;
    if (runtime%2==0)
    {
        std::cout<<"Nombre de la Tarea: " << name<< std::endl;
        std::cout<<"\tTipo: Simple"<<std::endl;
        std::cout<<"\tTiempo ejecucion: "<<runtime<<std::endl;
        std::cout<<"\tResultado de la ejecucion: Exitosa"<<std::endl;
    } else{
        std::cout<<"Nombre de la Tarea: "<< name << std::endl;
        std::cout<<"\tTipo: Simple"<<std::endl;
        std::cout<<"\tTiempo ejecucion: "<<runtime<<std::endl;
        std::cout<<"\tResultado de la ejecucion: Fallida"<<std::endl;
    }
}
