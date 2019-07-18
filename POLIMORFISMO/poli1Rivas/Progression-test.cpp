// Created by felix on 4/26/2019.

#include "catch.hpp"
#include "Progression.h"

SCENARIO("Suma de la Serie "){
    GIVEN("Progresion Aritmetica - Constructor por Default"){
        WHEN("Empieza en 1, razon es 1 y la cantidad es 4: 1, 2, 3, 4"){
            ArithProgression p;
            auto total = calculate_total(&p, 4);
            THEN("Total es 10"){
                REQUIRE(total==10);
            }
        }
    }

    GIVEN("Progresion Aritmetica - Constructor con parametros"){
        WHEN("Empieza en 1, razon es 2 y la cantidad es 4: 1, 3, 5, 7"){
            ArithProgression p(2);
            auto total = calculate_total(&p, 4);
            THEN("Total es 16"){
                REQUIRE(total==16);
            }
        }
    }

    GIVEN("Progresion Geometrica - Constructor por default"){
        WHEN("Empieza en 1, razon es 2 y la cantidad es 4: 1 2 4 8"){
            GeoProgression g;
            auto total = calculate_total(&g,4);
            THEN("Total es 15"){
                REQUIRE(total==15);
            }
        }
    }
    GIVEN("Progresion Geometrica - Constructor con parametros"){
        WHEN("Empieza en 1, razon es 4 y la cantidad es 4: 1, 4, 16, 64"){
            GeoProgression g(4);
            auto total = calculate_total(&g, 4);
            THEN("Total es 85"){
                REQUIRE(total==85);
            }
        }
    }

    GIVEN("Progresion Fibonacci - Constructor por default"){
        WHEN("Empieza en 1, razon es previo+anterior y la cantidad es 4: 1, 1, 2, 3"){
            FibonacciProgression f;
            auto total = calculate_total(&f, 4);
            THEN("Total es 7"){
                REQUIRE(total==7);
            }
        }
    }
    GIVEN("Progresion Fibonacci - Constructor con parametros"){
        WHEN("Empieza en 1, razon es el previo+anterior y la cantidad es 4: 2, 3, 5, 8"){
            FibonacciProgression f(2,1);
            auto total = calculate_total(&f, 4);
            THEN("Total es 18"){
                REQUIRE(total==18);
            }
        }
    }
}


