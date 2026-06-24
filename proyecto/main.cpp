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
        std::cout <<"[SistemaMonitoreo] Inicializacion con limite de: " << limite << " m/s" << std::endl;
    }
    ~SistemaMonitoreo() {
        std::cout <<"[SistemaMonitoreo] Destructor invocado de manera segura (RAII)" << std::endl;
    }
    void procesarYReportar(Vehiculo<T> listaAutos[], T1 cantidad) {
        std::cout << " Reporte de trafico y captura de infractores" << std::endl;
        std::cout << std::left << std::setw(10) << "ESTADO" << "VELOCIDAD CALCULADA\n";
    }
}