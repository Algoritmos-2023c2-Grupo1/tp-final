#include <iostream>
#include "Graph.h"
#include <optional>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void Graph::addAeropuerto(Aeropuerto *aeropuerto) {
    aeropuertos->insertar(aeropuerto->getCodigoIATA(), aeropuerto);
}

list<Aeropuerto *> Graph::getAeropuertos() {
    return aeropuertos->listar();
}

string Graph::toString() {
    return "Graph [aeropuertos=" + to_string(aeropuertos->size()) + "]";
}

void Graph::agregarVueloAAeropuerto(string iata, Vuelo *vuelo) {
    aeropuertos->buscar(iata)->addVuelo(vuelo);
}

void Graph::showlist() {
    for (Aeropuerto *aeropuerto: aeropuertos->listar()) {
        cout << aeropuerto->toString();
        for (const auto &vuelo: aeropuerto->getVuelos()) {
            cout << vuelo->toString() << endl;
        }
    }
}

optional<Aeropuerto *> Graph::getAeropuerto(string iata) {
    return aeropuertos->buscar(iata);
};

std::list<Vuelo> Graph::buscarRutaOptima(const std::string &codigoIATAPartida, const std::string &codigoIATADestino,
                                         std::unordered_map<Aeropuerto *, float> &costosDesdeOrigen,
                                         std::unordered_map<Aeropuerto *, Vuelo> &vuelosPrevios,
                                         std::function<float(float, float)> calculador) {
    optional<Aeropuerto *> origen = getAeropuerto(codigoIATAPartida);
    optional<Aeropuerto *> destino = getAeropuerto(codigoIATADestino);

    if (!origen.has_value() || !destino.has_value()) {
        // cout << "Aeropuerto de partida o destino no existe" << endl;
        return {};
    }

    // Estructuras para realizar el cálculo de la ruta óptima
    std::priority_queue<std::pair<float, Aeropuerto *>, std::vector<std::pair<float, Aeropuerto *>>, std::greater<>> colaPrioridad;

    // Inicializa el costo desde el origen como infinito para todos los aeropuertos
    for (Aeropuerto *aeropuerto : aeropuertos->listar()) {
        costosDesdeOrigen[aeropuerto] = std::numeric_limits<float>::infinity();
    }

    // El costo desde el origen hacia el aeropuerto de partida es 0
    costosDesdeOrigen[origen.value()] = 0;

    // Agrega el aeropuerto de partida a la cola de prioridad
    colaPrioridad.push({0, origen.value()});

    // Algoritmo de Dijkstra
    while (!colaPrioridad.empty()) {
        Aeropuerto *aeropuertoActual = colaPrioridad.top().second;
        colaPrioridad.pop();

        // Aeropuerto es el destino, reconstruir y devolver la ruta
        if (aeropuertoActual == destino.value()) {
            std::list<Vuelo> ruta;
            Aeropuerto *aeropuerto = destino.value();

            // Reconstruir la ruta desde el destino hasta el origen
            while (aeropuerto != origen.value()) {
                ruta.push_front(vuelosPrevios[aeropuerto]);
                aeropuerto = getAeropuerto(vuelosPrevios[aeropuerto].getCodigoIATAPartida()).value();
            }

            return ruta;
        }

        // Explorar los vuelos desde el aeropuerto actual
        for (const Vuelo *vuelo : aeropuertoActual->getVuelos()) {
            Aeropuerto *aeropuertoDestino = getAeropuerto(vuelo->getCodigoIATADestino()).value();
            float costoHastaDestino = costosDesdeOrigen[aeropuertoActual] + calculador(vuelo->getCostoVuelo(), vuelo->getHorasVuelo());

            // Actualizar el costo si encontramos una ruta más corta
            if (costoHastaDestino < costosDesdeOrigen[aeropuertoDestino]) {
                costosDesdeOrigen[aeropuertoDestino] = costoHastaDestino;
                vuelosPrevios[aeropuertoDestino] = *vuelo;
                colaPrioridad.push({costoHastaDestino, aeropuertoDestino});
            }
        }
    }

    // cout << "No se encontró una ruta desde " << origen.value()->getCodigoIATA() << " a "
    //      << destino.value()->getCodigoIATA() << endl;
    return {};
}

// Método para buscar la ruta más económica
std::list<Vuelo> Graph::buscarRutaMasEconomica(const std::string &codigoIATAPartida, const std::string &codigoIATADestino) {
    unordered_map<Aeropuerto *, float> costoDesdeOrigen;
    unordered_map<Aeropuerto *, Vuelo> vuelosPrevios;

    // Funcion lambda recibe x e y devuelve x
    auto costoCalculador = [](float costo, float tiempo) { return costo; };

    return buscarRutaOptima(codigoIATAPartida, codigoIATADestino, costoDesdeOrigen, vuelosPrevios, costoCalculador);
}

// Método para buscar la ruta más corta en tiempo
std::list<Vuelo> Graph::buscarRutaMasCortaEnTiempo(const std::string &codigoIATAPartida, const std::string &codigoIATADestino) {
    unordered_map<Aeropuerto *, float> tiempoDesdeOrigen;
    unordered_map<Aeropuerto *, Vuelo> vuelosPrevios;

    // Funcion lambda recibe x e y devuelve y
    auto tiempoCalculador = [](float costo, float tiempo) { return tiempo; };

    return buscarRutaOptima(codigoIATAPartida, codigoIATADestino, tiempoDesdeOrigen, vuelosPrevios, tiempoCalculador);
}

Graph::Graph(Hash<Aeropuerto *> *aeropuertos) {
    this->aeropuertos = aeropuertos;
}

void Graph::borrarAeropuerto(const string &codigoIATA){
    this->aeropuertos->borrar(codigoIATA);
}
