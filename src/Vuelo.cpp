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

string Vuelo::getTiempoVuelo() const {
    return to_string((unsigned int)horasVuelo) + ':' +
            to_string((unsigned int)(60 * (horasVuelo - (unsigned int)horasVuelo)));
}

Aeropuerto* Vuelo::getAeropuertoPartida() const {
    return aeropuertoPartida;
}

Aeropuerto* Vuelo::getAeropuertoDestino() const {
    return aeropuertoDestino;
}

string Vuelo::toString() const {
    return "Vuelo [" + codigoIATAPartida + " a " + 
                    codigoIATADestino + " (" + getTiempoVuelo()+
                    ") USD" + to_string(getCostoVuelo()) + "]";           
}
