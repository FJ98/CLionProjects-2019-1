// Created by felix on 6/26/2019.
#ifndef OBSERVADOR_OBSERVER_H
#define OBSERVADOR_OBSERVER_H

struct Message{
    virtual int getValue() = 0;
};

class Observer {
public:
    virtual void update(Message* msg) = 0;
};


#endif //OBSERVADOR_OBSERVER_H
