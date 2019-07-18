#include <iostream>

#include "Parking.h"
#include "Client.h"

int main() {
    Parking utc(10);
    utc.attach(new Client("User 1"));
    utc.attach(new Client("User 2"));
    utc.setStatus(10);
    return 0;
}