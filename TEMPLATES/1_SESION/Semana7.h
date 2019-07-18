// Created by felix on 5/8/2019.
#ifndef INC_1_SESION_SEMANA7_H
#define INC_1_SESION_SEMANA7_H

#include <string.h>
#include <stdio.h>
#include <cstring>

namespace UTEC {
    template<typename T>
    T max(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T1, typename T2>
    auto max(T1 a, T2 b) {
        return a > b ? a : b;
    }

    template<typename T1, typename T2, typename T3>
    T3 max(T1 a, T2 b) {
        return a > b ? a : b;
    }

    const char *max(const char *a, const char *b) {
        return strcmp(a, b) > 0 ? a : b;
    }
}
#endif //INC_1_SESION_SEMANA7_H
