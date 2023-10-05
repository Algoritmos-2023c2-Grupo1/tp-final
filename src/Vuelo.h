#ifndef TP_FINAL_VUELO_H
#define TP_FINAL_VUELO_H

#include <string>

using namespace std;

class Vuelo {
private:
    string codigoIATAPartida;
    string codigoIATADestino;
    float costoVuelo;
    float horasVuelo;
public:
    Vuelo(const string &codigoIataPartida,
          const string &codigoIataDestino,
          const float costoVuelo,
          const float horasVuelo);

    string getCodigoIATAPartida() const;

    string getCodigoIATADestino() const;

    float getCostoVuelo() const;

    float getHorasVuelo() const;
};


#endif //TP_FINAL_VUELO_H
