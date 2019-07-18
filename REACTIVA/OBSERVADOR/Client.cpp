// Created by felix on 6/26/2019.
#include <iostream>
#include "Client.h"


void Client::update(Message *msg) {
    std::cout << "El cliente: " << id << std::endl;
    std::cout << "Recibio el mensaje: " <<
    msg->getValue() << " estacionamientos estan disponibles." << std::endl;
}
