#include "LectorArchivos.h"
#include "iostream"
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace std;

vector<Aeropuerto> LectorArchivos::obtenerAeropuertosDesdeArchivo() {
    vector<Aeropuerto> aeropuertos;
    string pathArchivoAeropuertos = "aeropuertos.txt";
    ifstream archivo(pathArchivoAeropuertos);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << pathArchivoAeropuertos << endl;
        return aeropuertos;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string codigo_IATA, nombre, ciudad, pais;
        float superficie;
        int cantidad_terminales, destinos_nacionales, destinos_internacionales;

        ss >> codigo_IATA >> nombre >> ciudad >> pais >> superficie >> cantidad_terminales >> destinos_nacionales
           >> destinos_internacionales;

        Aeropuerto aeropuerto(codigo_IATA,
                              nombre,
                              ciudad,
                              pais,
                              superficie,
                              cantidad_terminales,
                              destinos_nacionales,
                              destinos_internacionales);

        aeropuertos.push_back(aeropuerto);
    }

    archivo.close();
    return aeropuertos;
}

vector<Vuelo> LectorArchivos::obtenerVuelosDesdeArchivo() {
    vector<Vuelo> vuelos;
    string pathArchivoVuelos = "vuelos.txt";
    ifstream archivo(pathArchivoVuelos);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << pathArchivoVuelos << endl;
        return vuelos;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string codigoIATAPartida, codigoIATADestino;
        float costoVuelo, horasVuelo;

        ss >> codigoIATAPartida >> codigoIATADestino >> costoVuelo >> horasVuelo;

        Vuelo vuelo(codigoIATAPartida, codigoIATADestino, costoVuelo, horasVuelo);

        vuelos.push_back(vuelo);
    }

    archivo.close();
    return vuelos;
}
