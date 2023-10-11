#include "LectorArchivos.h"
#include "iostream"

using namespace std;

int main() {
    vector<Aeropuerto> aeropuertos = LectorArchivos::obtenerAeropuertosDesdeArchivo();

    for (const Aeropuerto &aeropuerto: aeropuertos) {
        cout << "Aeropuerto: " << aeropuerto.getNombre() << " (IATA: " << aeropuerto.getCodigoIATA() << ")" << endl;
    }

    vector<Vuelo> vuelos = LectorArchivos::obtenerVuelosDesdeArchivo();

    for (const Vuelo vuelo: vuelos) {
        cout << "Vuelo: desde " << vuelo.getCodigoIATAPartida() << " hasta " << vuelo.getCodigoIATADestino()
             << " con costo $" << vuelo.getCostoVuelo()
             << " con horas " << vuelo.getHorasVuelo() << "hs."
             << endl;
    }
};
