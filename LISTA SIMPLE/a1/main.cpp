#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    BinarySearchTree bst;
    std::vector<int> vsearch;

    // Grabar Datos del archivo "Locations.csv" en ll
    // Grabar Datos del archivo "Locations.csv" en bst

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch

    double avgtime_ll = 0;
    double avgtime_bst = 0;

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso
    for (const auto& id: vsearch) {

        // Buscar en ll

        // Buscar en bsd
    }


    return 0;
}