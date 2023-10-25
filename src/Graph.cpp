#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::addAeropuerto(Aeropuerto &aeropuerto) {
    aeropuertos->push_back(aeropuerto);
}

list<Aeropuerto> *Graph::getAeropuertos() {
    return aeropuertos;
}

string Graph::toString() {
    return "Graph [aeropuertos=" + to_string(aeropuertos->size()) + "]";
}

void Graph::addVueloANodo(string iata, Vuelo vuelo) {
    for(auto& aeropuerto : *aeropuertos)
        {
            if (aeropuerto.getCodigoIATA() == iata)
                aeropuerto.addVuelo(vuelo);
        }
}

void Graph::showlist() {
    for(auto& aeropuerto : *aeropuertos)
    {
        cout << aeropuerto.toString();       
        for(const auto& vuelo : aeropuerto.getVuelos())
        {
            cout << vuelo.toString() << "\n";
        }
        cout<<"\n";
    }
}

Graph::Graph() {
    aeropuertos = new list<Aeropuerto>();
}
