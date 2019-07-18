// Created by felix on 3/31/2019.
#include "FaultToleranceTask.h"

FaultToleranceTask::FaultToleranceTask(std::string name, int maxAttempts) : Task(name) {
    this->maxAttempts=maxAttempts;
}

bool FaultToleranceTask::execute () {
    std::cout<<"Nombre de la Tarea: "<<name<<std::endl;
    std::cout<<"\tTipo: Tolerante a Fallos"<<std::endl;
    std::cout<<"\tMaximo de Intentos: "<<maxAttempts<<std::endl;
    for (int i = 1; i <= maxAttempts; ++i) {
        runtime=(rand()%61)+60;
        std::cout<<"\t\tIntento No "<< i <<std::endl;
        std::cout<<"\t\t\tTiempo ejecucion: "<<runtime<<std::endl;
        if (runtime%2!=0)
        {
            std::cout<<"\t\t\tResultado de la ejecucion: Exitosa"<<std::endl;
            return true;
        } else{
            std::cout<<"\t\t\tResultado de la ejecucion: Fallida"<<std::endl;
        }
    }
    return false;
}