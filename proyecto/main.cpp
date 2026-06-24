#include <iostream>
#include <fstream>
#include <iomanip>
#include "radar.h"

template <typename T>
void ordenarVehiculosPorVelocidad(vehiculo<T>* arreglos, UT1 tamaño) {
    for (UT1 i = 0; i < tamaño - 1; ++i) {
        for (UT1 j = 0; j < tamaño - i - 1; ++j) {
            vehiculo<T> temp1 = arreglos[j];
            arreglos[j] = arreglos[j + 1];
            arreglos[j + 1] = temp1;
            }
        }
    }

template <typename T>
struct SistemaMonitoreo {
    T2 limite;

    SistemaMonitoreo(T2 lim) : limite(lim) {
        std::cout
    }
}
