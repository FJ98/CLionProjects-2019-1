#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

void llenar_vector(std::vector<int> *llenar, std::string);

int main() {
    // Declarando variables
    LinkedList *ll = new LinkedList();
    Node *prueba;

    std::vector<int> vsearch;

    llenar_vector(&vsearch,SEARCH_FILE);

   // std::string filename = "C:\\Users\\luis0\\CLionProjects\\linked_list\\Locations.csv";
    Location *actual = new Location(11111,"FL","CLAY COUNTY",30.109537,-81.741661,"Residential","Wood");



    // Grabar Datos del archivo "Locations.csv" en ll
    // Grabar Datos del archivo "Locations.csv" en bst

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    // std::cout<<"\n\n\n"<<"este es el head"<<"\n\n";
    double avgtime_ll = 0;
    double avgtime_bst = 0;

    UTEC::load_locations_link(ll,LOCATION_FILE);
    
    //ll->add_tail(actual);

    std::cout<<ll->size()<<std::endl;

    //ll->print_last();
    

    //ll->get_head()->data->imprimir();


    //ll->insert(5,actual);

    //ll->print();

    //ll->get_head()->data->imprimir();

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (const auto &id: vsearch) {
        ll->search(id)->data->imprimir();
    }

    //prueba = ll->search(vsearch[0]);

   // prueba->data->imprimir();

    delete ll;

    return 0;
}

void llenar_vector(std::vector<int> *llenar, std::string link){
    std::string linea;
    std::ifstream infile;
    infile.open(link);
    while(!infile.eof()){
        getline(infile,linea);
        llenar->push_back(std::stoi(linea));
        //std::cout<<std::stoi(linea)<<std::endl;
    }
}


   