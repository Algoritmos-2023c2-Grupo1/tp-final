#include "LectorArchivos.h"
#include "iostream"
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;

void LectorArchivos::obtenerAeropuertosDesdeArchivo(Hash<Aeropuerto> *aeropuertos, Graph *grafo) {
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
        auto *aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, terminales, destNacionales,
                                          destInternacionales);
        aeropuertos->insertar(iata, *aeropuerto);
        grafo->addAeropuerto(aeropuerto);
    }

    file1.close();
}

void LectorArchivos::obtenerVuelosDesdeArchivo(Hash<Aeropuerto> *aeropuertos, Graph *grafo) {
    // TODO: Pasar esta logica a LectorArchivos, puede retornar la lista de vuelos, o el lector puede ver el grafo y el codigo quedaria casi igual
    ifstream file2("../resources/vuelos.txt");

    string origen;
    string destino;
    float costo_vuelo;
    float tiempo_vuelo;

    while (file2 >> origen >> destino >> costo_vuelo >> tiempo_vuelo) {
        auto *vuelo = new Vuelo(origen, destino, costo_vuelo, tiempo_vuelo);
        grafo->agregarVueloAAeropuerto(origen, vuelo);
    }
    file2.close();
}
