#include <utility>

// Created by felix on 6/26/2019.
#ifndef OBSERVADOR_CLIENT_H
#define OBSERVADOR_CLIENT_H

#include <string>
#include "Observer.h"

class Client : public Observer {
private:
    std::string id;
public:
    explicit Client(std::string   id) : id{std::move(id)} {}
    void update(Message* msg) override;
};


#endif //OBSERVADOR_CLIENT_H
