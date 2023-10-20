#include "Vuelo.h"

Vuelo::Vuelo(const string &codigoIataPartida,
             const string &codigoIataDestino,
             const float costoVuelo,
             const float horasVuelo,
             Aeropuerto *aeropuertoPartida,
             Aeropuerto *aeropuertoDestino
) : codigoIATAPartida(codigoIataPartida),
    codigoIATADestino(codigoIataDestino),
    costoVuelo(costoVuelo),
    horasVuelo(horasVuelo),
    aeropuertoPartida(aeropuertoPartida),
    aeropuertoDestino(aeropuertoDestino) {
}

Vuelo::Vuelo(const string &codigoIataPartida,
             const string &codigoIataDestino,
             const float costoVuelo,
             const float horasVuelo
) : codigoIATAPartida(codigoIataPartida),
    codigoIATADestino(codigoIataDestino),
    costoVuelo(costoVuelo),
    horasVuelo(horasVuelo) {
}


string Vuelo::getCodigoIATAPartida() const {
    return codigoIATAPartida;
}

string Vuelo::getCodigoIATADestino() const {
    return codigoIATADestino;
}

float Vuelo::getCostoVuelo() const {
    return costoVuelo;
}

float Vuelo::getHorasVuelo() const {
    return horasVuelo;
}

Aeropuerto* Vuelo::getAeropuertoPartida() const {
    return aeropuertoPartida;
}

Aeropuerto* Vuelo::getAeropuertoDestino() const {
    return aeropuertoDestino;
}

string Vuelo::toString() const {
    return "\n Edge [origin=" + aeropuertoPartida->getCiudad() + ", destination=" + aeropuertoDestino->getCiudad() +
           ", distance=" + to_string(horasVuelo) + "]";
}
