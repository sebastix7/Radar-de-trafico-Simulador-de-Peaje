#ifndef RADAR_H
#define RADAR_H
#include "types1.h"
#include <cstddef>

//Suponemos que el hardware tiene un alcance de 50 metros 
//Por ende en un carril tiene como capacidad máxima de 12 vehículos
const T1 max_vehiculos = 10;

//Creamos un struct
//Usamos templates para variar los valores de la velocidad si queremos que sea mas exacto usamos double y sino un float
template <typename T>
struct vehiculo {
    private:
        T1 id;
        T velocidadActual;
        char placa[8];
    
    public:
        //Constructor
        vehiculo() {
            id = 0;
            velocidadActual = 0.0f;
            placa[0] = '\0';
        }

        void llenarDatos(T1 m_id, T m_velocidad, const char* m_placa){
            id = m_id;
            velocidadActual = m_velocidad;
            for(size_t i = 0; i < 7; i++){
                *(placa + i) = m_placa[i];
            }
            *(placa + 7) = '\0';
        }

        //Declaramos las funciones
        //Nos acordamos que la formula para calcular la velocidad es variación de la posición sobre la variación del tiempo
        void calcularVelocidad(const T* deltaX, const T* deltaT, T* velocidadResultado);
        void capturarTraficoSimulado(vehiculo<T> listaAutos[], T1* cantidadDetectados);
};

//Definimos las funciones
//Calculamos la velocidad de cada vehículo
template <typename T>
void vehiculo<T>::calcularVelocidad(const T* deltaX, const T* deltaT, T* velocidadResultado){
    if(deltaT != nullptr && *deltaT > 0.0f){ //el denominador no debe ser 0, por teoria
        *velocidadResultado = (*deltaX)/(*deltaT);
    }
    else{
        *velocidadResultado = 0;
    }
}

//Simulador de trafico para llenar el arreglo unidimensional listaAutos
template <typename T>
void vehiculo<T>:: capturarTraficoSimulado(vehiculo<T> listaAutos[], int* cantidadDetectados){
    //Inicializamos 
    *cantidadDetectados = 0;

    if(*cantidadDetectados < max_vehiculos){
        T dX = 20.0; //metros
        T dT = 1.0; //segundos
        T velocidadCalculada;

        //Llamamos a la funcion calcularVelocidad
        calcularVelocidad(&dX, &dT, &velocidadCalculada);

        listaAutos[*cantidadDetectados].
    }
}
