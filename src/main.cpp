#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include "Graph.h"
#include "Aeropuerto.h"
#include "Menu.h"
#include"Hash.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");
    // TODO: Esto se haria en Aplicacion
    Graph *grafo = new Graph();

    Hash<Aeropuerto> aeropuertos(5);

    // TODO: Pasar esta logica a LectorArchivos, puede retornar la lista de aeropuertos, o el lector puede ver el grafo y el codigo quedaria casi igual
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
        Aeropuerto item(
                iata,
                nombre,
                ciudad,
                pais,
                superficie,
                terminales,
                destNacionales,
                destInternacionales);
        // Listado de aeropuertos.
        aeropuertos.insertar(iata, item);
        grafo->addAeropuerto(*aeropuerto);
    }

    file1.close();
    // TODO: Pasar esta logica a LectorArchivos, puede retornar la lista de vuelos, o el lector puede ver el grafo y el codigo quedaria casi igual
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


    Menu menu = Menu(grafo);

    menu.start();

    return 0;
}
