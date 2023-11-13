#include <iostream>
#include "Graph.h"
#include <optional>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void Graph::addAeropuerto(Aeropuerto *aeropuerto) {
    aeropuertos.push_back(aeropuerto);
}

list<Aeropuerto *> Graph::getAeropuertos() {
    return aeropuertos;
}

string Graph::toString() {
    return "Graph [aeropuertos=" + to_string(aeropuertos.size()) + "]";
}

void Graph::agregarVueloAAeropuerto(string iata, Vuelo *vuelo) {
    for (Aeropuerto *aeropuerto: aeropuertos) {
        if (aeropuerto->getCodigoIATA() == iata) {
            aeropuerto->addVuelo(vuelo);
        }
    }
}

void Graph::showlist() {
    for (Aeropuerto *aeropuerto: aeropuertos) {
        cout << aeropuerto->toString();
        for (const auto &vuelo: aeropuerto->getVuelos()) {
            cout << vuelo->toString() << endl;
        }
    }
}

optional<Aeropuerto *> Graph::getAeropuerto(string iata) {
    for (Aeropuerto *aeropuerto: aeropuertos) {
        if (aeropuerto->getCodigoIATA() == iata) {
            return aeropuerto;
        }
    }
    return {};
};

std::list<Vuelo *>
Graph::buscarRutaMasEconomica(const std::string &codigoIATAPartida, const std::string &codigoIATADestino) {
    optional<Aeropuerto *> origen = getAeropuerto(codigoIATAPartida);
    optional<Aeropuerto *> destino = getAeropuerto(codigoIATADestino);

    if (!origen.has_value() || !destino.has_value()) {
        cout << "Aeropuerto de partida o destino no existe" << endl;
        return {};
    }

    cout << origen.value()->getCodigoIATA() << endl;
    return {};
}

list<Vuelo *> Graph::buscarRutaMasCortaEnTiempo(const string &codigoIATAPartida, const string &codigoIATADestino) {
    optional<Aeropuerto *> origen = getAeropuerto(codigoIATAPartida);
    optional<Aeropuerto *> destino = getAeropuerto(codigoIATADestino);

    if (!origen.has_value() || !destino.has_value()) {
        cout << "Aeropuerto de partida o destino no existe" << endl;
        return {};
    }

    // Estructuras para realizar el cálculo de la ruta más corta en tiempo
    std::unordered_map<Aeropuerto *, float> tiempoDesdeOrigen;
    std::unordered_map<Aeropuerto *, Vuelo> vuelosPrevios;
    std::priority_queue<std::pair<float, Aeropuerto *>, std::vector<std::pair<float, Aeropuerto *>>, std::greater<>> colaPrioridad;

    // Inicializa el tiempo desde el origen como infinito para todos los aeropuertos
    for (Aeropuerto *aeropuerto: aeropuertos) {
        tiempoDesdeOrigen[aeropuerto] = INT_MAX;
    }

    // El tiempo desde el origen hacia el aeropuerto de partida es 0
    tiempoDesdeOrigen[origen.value()] = 0;

    // Agrega el aeropuerto de partida a la cola de prioridad
    colaPrioridad.push({0, origen.value()});
    cout << "Agregando aeropuerto de partida a la cola de prioridad ->" << origen.value()->getCodigoIATA() << endl;

    while (!colaPrioridad.empty()) {
        Aeropuerto *aeropuertoActual = colaPrioridad.top().second;
        colaPrioridad.pop();
        if (aeropuertoActual == destino.value()) {
            cout << "Estamos sobre el aeropuerto destino - " << destino.value()->getCodigoIATA()
                 << " reconstruyendo ruta..."
                 << endl;
            std::list<Vuelo *> ruta;
            Aeropuerto *aeropuerto = destino.value();

            while (aeropuerto != origen.value()) {
                // TODO:  Falla al reconstruir
                ruta.push_front(&vuelosPrevios[aeropuerto]);
                aeropuerto = getAeropuerto(vuelosPrevios[aeropuerto].getCodigoIATADestino()).value();
                break;
            }

            cout << "Ruta más corta en tiempo desde " << origen.value()->getCodigoIATA() << " a "
                 << destino.value()->getCodigoIATA() << " (Tiempo: " << tiempoDesdeOrigen[destino.value()] << " horas)"
                 << endl;

            return ruta;
        }

        for (const Vuelo *vuelo: aeropuertoActual->getVuelos()) {
            Aeropuerto *aeropuertoDestino = getAeropuerto(vuelo->getCodigoIATADestino()).value();
            float tiempoHastaDestino = tiempoDesdeOrigen[aeropuertoActual] + vuelo->getHorasVuelo();

            if (tiempoHastaDestino < tiempoDesdeOrigen[aeropuertoDestino]) {
                // Encontramos un camino más corto en tiempo
                tiempoDesdeOrigen[aeropuertoDestino] = tiempoHastaDestino;
                vuelosPrevios[aeropuertoDestino] = *vuelo;
                colaPrioridad.push({tiempoHastaDestino, aeropuertoDestino});
            }
        }
    }

    // Si llegamos aquí, no se encontró una ruta
    cout << "No se encontró una ruta desde " << origen.value()->getCodigoIATA() << " a "
         << destino.value()->getCodigoIATA() << endl;
    return {};
}