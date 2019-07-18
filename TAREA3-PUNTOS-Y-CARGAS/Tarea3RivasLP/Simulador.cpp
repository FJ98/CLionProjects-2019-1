// Created by felix on 4/30/2019.
#include "Simulador.h"

Simulador::Simulador(int h, int w) {m_inter = h; n_inter = w;}
void Simulador::SetPuntos(int h, int w){m_inter = h; n_inter = w;}

void Simulador::LlenarPuntos() {
    Punto *nuevo;
    for (int i = 0; i < m_inter; i++) {
        for (int j = 0; j < n_inter; j++) {
            nuevo = new Punto(i,j);
            Punt.push_back(nuevo);
        }
    }
}
void Simulador::LlenarCargas(std::string link) {
    std::ifstream in(link);
    bool bandera = false;
    Carga *nuevo;
    std::vector<std::string> datos;
    if(in){
        std::string line;
        while(getline(in, line)){
            std::stringstream sep(line);
            std::string field;
            while(getline(sep,field,';')){
                datos.push_back(field);
            }
            if(bandera){
                if( (std::stoi(datos[0])<m_inter) and (std::stoi(datos[1])<n_inter) ){
                    nuevo = new Carga( std::stoi(datos[0]), std::stoi(datos[1]), std::stof(datos[2]) );
                    Carg.push_back(nuevo);
                }
            }
            bandera=true;
            datos.clear();
        }
    }
}
void Simulador::Calcular() {
    float distancia;
    for(auto it_punt=Punt.begin(); it_punt != Punt.end(); it_punt++){
        for(auto it_carg=Carg.begin(); it_carg != Carg.end(); it_carg++){
            distancia = sqrt( ( pow ( ( ( (*it_punt)->PosY)  - ( (*it_carg)->PosX) ), 2 )  +  (pow ( ( ( (*it_punt)->PosY) - ( (*it_carg)->PosY) ),2 ) )  ) );
            if(distancia>0){
                (*it_punt)->Potencial+=(((*it_carg)->k)*((*it_carg)->q)/distancia);
            }
        }
        std::cout<<"Potencia en el punto: ("<<(*it_punt)->PosX<<", "<<(*it_punt)->PosY<<") -> V: " <<(*it_punt)->Potencial<<"*(10^9)"<<std::endl;
    }

}
void Simulador::Imprimir() {
    std::cout<<std::endl;
    for (std::vector<Carga*>::iterator it=Carg.end(); it != Carg.end(); it++) {
        std::cout<<(*it)->PosX<<" "<<(*it)->PosY<<" "<<(*it)->q<<" "<<(*it)->k<<std::endl;
    }
}
Simulador::~Simulador() {Punt.clear();Carg.clear();}