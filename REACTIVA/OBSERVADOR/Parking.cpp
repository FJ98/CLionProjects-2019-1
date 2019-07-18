// Created by felix on 6/26/2019.
#include "Parking.h"
#include <algorithm>
#include "Observer.h"
void Parking::attach(Observer *obs) {
    observers.push_back(obs);
}

void Parking::detach(Observer *obs) {
    auto item = std::find(begin(observers),end(observers), obs);
    if (item != end(observers)) { observers.erase(item); }
}

void Parking::notify() {
    for (auto obs: observers) {
        obs->update( new Notification(available) );
    }
}

void Parking::setStatus(int p_available) {
    this->available = p_available;
    notify();
}

