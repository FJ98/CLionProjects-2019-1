// Created by felix on 6/26/2019.
#ifndef OBSERVADOR_SUBJECT_H
#define OBSERVADOR_SUBJECT_H

class Observer;

class Subject {
public:
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    virtual void notify() = 0;

};


#endif //OBSERVADOR_SUBJECT_H
