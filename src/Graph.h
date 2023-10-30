#ifndef TP_FINAL_GRAPH_H
#define TP_FINAL_GRAPH_H

#include "Aeropuerto.h"

class Graph {
private:
    list<Aeropuerto> *aeropuertos;

public:
    Graph();

    void addAeropuerto(Aeropuerto &node);

    list<Aeropuerto> *getAeropuertos();

    string toString();

    void addVueloANodo(string iata, Vuelo vuelo);

    void showlist();

    Aeropuerto getAeropuerto(string iata);
};

#endif //TP_FINAL_GRAPH_H
