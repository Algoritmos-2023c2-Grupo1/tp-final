#ifndef TP_FINAL_AEROPUERTO_H
#define TP_FINAL_AEROPUERTO_H

#include <string>

using namespace std;

class Aeropuerto {
private:
    string codigo_IATA;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;

public:
    Aeropuerto(const string &codigoIata,
               const string &nombre,
               const string &ciudad,
               const string &pais,
               float superficie,
               int cantidadTerminales,
               int destinosNacionales,
               int destinosInternacionales);

    string getCodigoIATA() const;

    string getNombre() const;

    string getCiudad() const;

    string getPais() const;

    float getSuperficie() const;

    int getCantidadTerminales() const;

    int getDestinosNacionales() const;

    int getDestinosInternacionales() const;
};


#endif //TP_FINAL_AEROPUERTO_H
