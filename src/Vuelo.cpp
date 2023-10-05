#include "Vuelo.h"

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
