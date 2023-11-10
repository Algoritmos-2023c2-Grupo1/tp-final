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
        cout << aeropuerto.toString() << endl;
        for(const auto& vuelo : aeropuerto.getVuelos())
        {
            cout << vuelo.toString() << endl;
        }
    }
}

Aeropuerto Graph::getAeropuerto(string iata){
    Aeropuerto _aeropuerto = Aeropuerto( "","","","",0,0,
                                        0,0);
    for(auto& aeropuerto : *aeropuertos)
    {
        if(aeropuerto.getCodigoIATA().compare(iata)==0){
            _aeropuerto = aeropuerto;
        }
    }
    return _aeropuerto;
};

Graph::Graph() {
    aeropuertos = new list<Aeropuerto>();
}
