#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <Graph.h>
#include <Aeropuerto.h>

using namespace std;

int main() {
    Graph *grafo = new Graph();

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
        Aeropuerto *aeropuerto = new Aeropuerto(iata, nombre, ciudad, pais, superficie, terminales, destNacionales,
                                                destInternacionales);
        grafo->addAeropuerto(*aeropuerto);
    }

    file1.close();

    ifstream file2("../resources/vuelos.txt");

    string origen;
    string destino;
    float costo_vuelo;
    float tiempo_vuelo;

    while (file2 >> origen >> destino >> costo_vuelo >> tiempo_vuelo) {
        Vuelo vuelo(origen, destino, costo_vuelo, tiempo_vuelo);
        grafo->addVueloANodo(origen, vuelo);
    }

    grafo->showlist();

    file2.close();

    return 0;
}
