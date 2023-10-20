#include "Aeropuerto.h"

float Aeropuerto::getSuperficie() const {
    return superficie;
}


int Aeropuerto::getCantidadTerminales() const {
    return cantidad_terminales;
}


int Aeropuerto::getDestinosNacionales() const {
    return destinos_nacionales;
}


int Aeropuerto::getDestinosInternacionales() const {
    return destinos_internacionales;
}

string Aeropuerto::getCodigoIATA() const {
    return codigo_IATA;
}

string Aeropuerto::getNombre() const {
    return nombre;
}

string Aeropuerto::getCiudad() const {
    return ciudad;
}

string Aeropuerto::getPais() const {
    return pais;
}

Aeropuerto::Aeropuerto(const string &codigoIata,
                       const string &nombre,
                       const string &ciudad,
                       const string &pais,
                       float superficie,
                       int cantidadTerminales,
                       int cantidadDestinosNacionales,
                       int cantidadDestinosInternacionales
) : codigo_IATA(codigoIata),
    nombre(nombre),
    ciudad(ciudad),
    pais(pais),
    superficie(superficie),
    cantidad_terminales(cantidadTerminales),
    destinos_nacionales(cantidadDestinosNacionales),
    destinos_internacionales(cantidadDestinosInternacionales) {

}

void Aeropuerto::addVuelo(Vuelo &edge) {
    vuelos.push_back(edge);
}

list<Vuelo> Aeropuerto::getVuelos() {
    return vuelos;
}

string Aeropuerto::toString() {
    return "Nodo [" + codigo_IATA + ", vuelos=" + to_string(vuelos.size()) + "]\n";
}