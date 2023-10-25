#ifndef TP_FINAL_VUELO_H
#define TP_FINAL_VUELO_H

#include <string>
#include "Aeropuerto.h"

using namespace std;
class Aeropuerto;

class Vuelo {
private:
    string codigoIATAPartida;
    string codigoIATADestino;
    float costoVuelo;
    float horasVuelo;
    Aeropuerto *aeropuertoPartida;
    Aeropuerto *aeropuertoDestino;
public:
    Vuelo(const string &codigoIataPartida,
          const string &codigoIataDestino,
          const float costoVuelo,
          const float horasVuelo);

    Vuelo(const string &codigoIataPartida,
          const string &codigoIataDestino,
          const float costoVuelo,
          const float horasVuelo,
          Aeropuerto *aeropuertoPartida,
          Aeropuerto *aeropuertoDestino
    );

    string getCodigoIATAPartida() const;

    string getCodigoIATADestino() const;

    float getCostoVuelo() const;

    float getHorasVuelo() const;

    string getTiempoVuelo() const;

    Aeropuerto *getAeropuertoPartida() const;

    Aeropuerto *getAeropuertoDestino() const;

    string toString() const;
};


#endif //TP_FINAL_VUELO_H
