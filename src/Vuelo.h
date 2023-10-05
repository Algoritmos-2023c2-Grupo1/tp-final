#ifndef TP_FINAL_VUELO_H
#define TP_FINAL_VUELO_H
#include <string>

using namespace std;

class Vuelo {
private:
    string codigoIATAPartida;
    string codigoIATADestino;
public:
    Vuelo(const string &codigoIataPartida, const string &codigoIataDestino);
    string getCodigoIATAPartida;
    string getCodigoIATADestino;
};


#endif //TP_FINAL_VUELO_H
