#ifndef TP_FINAL_GRAPH_H
#define TP_FINAL_GRAPH_H

#include "Aeropuerto.h"
#include <vector>
#include <optional>
#include "Hash.h"

class Graph {
private:
    list<Aeropuerto *> aeropuertos;

public:
    void addAeropuerto(Aeropuerto *aeropuerto);

    list<Aeropuerto *> getAeropuertos();

    string toString();

    void agregarVueloAAeropuerto(string iata, Vuelo *vuelo);

    void showlist();

    std::optional<Aeropuerto *> getAeropuerto(string iata);

    list<Vuelo> buscarRutaMasEconomica(const std::string &codigoIATAPartida, const std::string &codigoIATADestino);

    list<Vuelo> buscarRutaMasCortaEnTiempo(const std::string &codigoIATAPartida, const std::string &codigoIATADestino);
};

#endif //TP_FINAL_GRAPH_H
