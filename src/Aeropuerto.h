#ifndef TP_FINAL_AEROPUERTO_H
#define TP_FINAL_AEROPUERTO_H

#include <string>
#include "Vuelo.h"
#include "list"

using namespace std;

class Vuelo;

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
    list<Vuelo> vuelos;

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

    void addVuelo(Vuelo &edge);

    list<Vuelo> getVuelos();

    string toString();
};


#endif //TP_FINAL_AEROPUERTO_H
