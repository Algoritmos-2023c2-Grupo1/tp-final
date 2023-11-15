#include "LectorArchivos.h"
#include "iostream"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;

void LectorArchivos::obtenerAeropuertosDesdeArchivo(Graph *grafo) {
    ifstream file1("../resources/aeropuertos.txt");
    string iata;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int terminales;
    int destNacionales;
    int destInternacionales;

    while (file1 >> iata >> nombre >> ciudad >> pais >> superficie >> terminales >> destNacionales
                 >> destInternacionales) {
        transform(iata.begin(), iata.end(), iata.begin(), ::toupper);
        auto *aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, terminales, destNacionales,
                                          destInternacionales);
        grafo->addAeropuerto(aeropuerto);
    }

    file1.close();
}

void LectorArchivos::obtenerVuelosDesdeArchivo(Graph *grafo) {
    ifstream file2("../resources/vuelos.txt");

    string origen;
    string destino;
    float costo_vuelo;
    float tiempo_vuelo;

    while (file2 >> origen >> destino >> costo_vuelo >> tiempo_vuelo) {
        transform(origen.begin(), origen.end(), origen.begin(), ::toupper);
        transform(destino.begin(), destino.end(), destino.begin(), ::toupper);
        auto *vuelo = new Vuelo(origen, destino, costo_vuelo, tiempo_vuelo);
        grafo->agregarVueloAAeropuerto(origen, vuelo);
    }
    file2.close();
}
