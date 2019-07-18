//
// Created by luis0 on 9/04/2019.
//

#ifndef LINKED_LIST_LOCATION_H
#define LINKED_LIST_LOCATION_H
#include <string>
#include <iostream>

class Location {
    int position_id;
    std::string state_code;
    std::string county;
    double latitude;    
    double longitude;
    std::string line;
    std::string construction;
public:
    Location(
            int position_id,
            std::string state_code,
            std::string county,
            double latitude,
            double longitude,
            std::string line,
            std::string construction);

    // Declare los metodos que crea necesario
    void imprimir();
    int get_id() {return position_id;}
    Location();
    // Cree que sea necesario agregar destructor, justifique

};

#endif //LINKED_LIST_LOCATION_H
