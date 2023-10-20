#include "Graph.h"
#include "iostream"

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
    list<Aeropuerto>::iterator it;
    for (it = aeropuertos->begin(); it != aeropuertos->end(); ++it) {
        if (it->getCodigoIATA() == iata)
            it->addVuelo(vuelo);
    }
}

void Graph::showlist() {
    list<Aeropuerto>::iterator it;
    for (it = aeropuertos->begin(); it != aeropuertos->end(); ++it) {
        cout << it->toString();
        list<Vuelo>::iterator at;
        for (at = it->getVuelos().begin(); at != it->getVuelos().end(); ++at) {
            cout << "\t" << at->toString() << "\n";
        }
        cout << "\n";
    }
}

Graph::Graph() {
    aeropuertos = new list<Aeropuerto>();
}
