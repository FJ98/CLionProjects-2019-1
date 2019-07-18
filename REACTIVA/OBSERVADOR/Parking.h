// Created by felix on 6/26/2019.
#ifndef OBSERVADOR_PARKING_H
#define OBSERVADOR_PARKING_H

#include "Observer.h"
#include "Subject.h"
#include <vector>

class Notification : public Message{
    friend class Parking;
    int available;
public:
    explicit Notification(int available) : available{available} {}
    inline int getValue() override { return available; }
};

class Parking : public Subject {
private:
    int available, capacity;
    std::vector<Observer*> observers;
public:
    explicit Parking(int capacity) :
    available{capacity}, capacity{capacity} {}
    void attach(Observer* obs) override;
    void detach(Observer* obs) override;
    void notify() override;
    void setStatus(int p_available);
};


#endif //OBSERVADOR_PARKING_H
