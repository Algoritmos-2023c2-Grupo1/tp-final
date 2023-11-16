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

/*
 * Se verifica si los aeropuertos de partida y destino existen en la lista de aeropuertos. Si no existen, se imprime un mensaje y se devuelve una lista vacía.
 * Se inicializan estructuras de datos como un mapa de costos desde el origen, un mapa de vuelos previos y una cola de prioridad para realizar el cálculo de la ruta con el menor costo.
 * Se inicializan los costos desde el origen como infinito para todos los aeropuertos, excepto el aeropuerto de partida, cuyo costo es 0.
 * Se utiliza el algoritmo de Dijkstra para encontrar la ruta más económica desde el aeropuerto de partida hasta el aeropuerto de destino.
 * Se reconstruye la ruta más económica y se imprime el resultado.
 */
std::list<Vuelo>
Graph::buscarRutaMasEconomica(const std::string &codigoIATAPartida, const std::string &codigoIATADestino) {
    optional<Aeropuerto *> origen = getAeropuerto(codigoIATAPartida);
    optional<Aeropuerto *> destino = getAeropuerto(codigoIATADestino);

    if (!origen.has_value() || !destino.has_value()) {
        // cout << "Aeropuerto de partida o destino no existe" << endl;
        return {};
    }

    // Estructuras para realizar el cálculo de la ruta con menor costo
    std::unordered_map<Aeropuerto *, float> costoDesdeOrigen;
    std::unordered_map<Aeropuerto *, Vuelo> vuelosPrevios;
    std::priority_queue<std::pair<float, Aeropuerto *>, std::vector<std::pair<float, Aeropuerto *>>, std::greater<>> colaPrioridad;

    // Inicializa el tiempo desde el origen como infinito para todos los aeropuertos
    for (Aeropuerto *aeropuerto: aeropuertos->listar()) {
        costoDesdeOrigen[aeropuerto] = INT_MAX;
    }

    // El tiempo desde el origen hacia el aeropuerto de partida es 0
    costoDesdeOrigen[origen.value()] = 0;

    // Agrega el aeropuerto de partida a la cola de prioridad
    colaPrioridad.push({0, origen.value()});
    // cout << "Agregando aeropuerto de partida a la cola de prioridad ->" << origen.value()->getCodigoIATA() << endl;

    while (!colaPrioridad.empty()) {
        Aeropuerto *aeropuertoActual = colaPrioridad.top().second;
        colaPrioridad.pop();
        if (aeropuertoActual == destino.value()) {
            // cout << "Estamos sobre el aeropuerto destino - " << destino.value()->getCodigoIATA()
            //     << " reconstruyendo ruta..."
            //     << endl;
            std::list<Vuelo> ruta;
            Aeropuerto *aeropuerto = destino.value();

            while (aeropuerto != origen.value()) {
                // cout << "Agregando vuelo " << vuelosPrevios[aeropuerto].toString() << " a la ruta mas económica " << vuelosPrevios[aeropuerto].getCostoVuelo() << endl;

                ruta.push_front(vuelosPrevios[aeropuerto]);
                aeropuerto = getAeropuerto(vuelosPrevios[aeropuerto].getCodigoIATAPartida()).value();
            }

//            cout << "Ruta más económica " << origen.value()->getCodigoIATA() << " a "
//                 << destino.value()->getCodigoIATA() << " con Costo: USD $" << costoDesdeOrigen[destino.value()]
//                 << endl;

            return ruta;
        }

        for (const Vuelo *vuelo: aeropuertoActual->getVuelos()) {
            Aeropuerto *aeropuertoDestino = getAeropuerto(vuelo->getCodigoIATADestino()).value();
            // Se guarda el costo acumulado + costo vuelo actual
            float costoHastaDestino = costoDesdeOrigen[aeropuertoActual] + vuelo->getCostoVuelo();

            // Verifica si hay otro camino minimo
            if (costoHastaDestino < costoDesdeOrigen[aeropuertoDestino]) {
                // Encontramos un camino minimo
                costoDesdeOrigen[aeropuertoDestino] = costoHastaDestino;
                vuelosPrevios[aeropuertoDestino] = *vuelo;
                colaPrioridad.push({costoHastaDestino, aeropuertoDestino});
            }
        }
    }

    //    cout << "No se encontró una ruta desde " << origen.value()->getCodigoIATA() << " a "
    //         << destino.value()->getCodigoIATA() << endl;
    return {};
}

/*
 * Se verifica si los aeropuertos de partida y destino existen en la lista de aeropuertos. Si no existen, se imprime un mensaje y se devuelve una lista vacía.
 * Se inicializan estructuras de datos como un mapa de duraciones desde el origen, un mapa de vuelos previos y una cola de prioridad para realizar el cálculo de la ruta con la menor duracion.
 * Se inicializan las duraciones desde el origen como infinito para todos los aeropuertos, excepto el aeropuerto de partida, cuya duracion es 0.
 * Se utiliza el algoritmo de Dijkstra para encontrar la ruta más corta en tiempo desde el aeropuerto de partida hasta el aeropuerto de destino.
 * Se reconstruye la ruta más corta en tiempo y se imprime el resultado.
 */
list<Vuelo> Graph::buscarRutaMasCortaEnTiempo(const string &codigoIATAPartida, const string &codigoIATADestino) {
    optional<Aeropuerto *> origen = getAeropuerto(codigoIATAPartida);
    optional<Aeropuerto *> destino = getAeropuerto(codigoIATADestino);

<<<<<<< Updated upstream
    if (!origen.has_value() || !destino.has_value()) {
        // cout << "Aeropuerto de partida o destino no existe" << endl;
        return {};
    }

    // Estructuras para realizar el cálculo de la ruta más corta en tiempo
    std::unordered_map<Aeropuerto *, float> tiempoDesdeOrigen;
    std::unordered_map<Aeropuerto *, Vuelo> vuelosPrevios;
    std::priority_queue<std::pair<float, Aeropuerto *>, std::vector<std::pair<float, Aeropuerto *>>, std::greater<>> colaPrioridad;
=======
    // Funcion lambda recibe x e y devuelve x
    auto costoCalculador = [](float costo, float tiempo) { return costo; };
    return buscarRutaOptima(codigoIATAPartida, codigoIATADestino, costoDesdeOrigen, vuelosPrevios, costoCalculador);
}
>>>>>>> Stashed changes

    // Inicializa el tiempo desde el origen como infinito para todos los aeropuertos
    for (Aeropuerto *aeropuerto: aeropuertos->listar()) {
        tiempoDesdeOrigen[aeropuerto] = INT_MAX;
    }

    // El tiempo desde el origen hacia el aeropuerto de partida es 0
    tiempoDesdeOrigen[origen.value()] = 0;

    // Agrega el aeropuerto de partida a la cola de prioridad
    colaPrioridad.push({0, origen.value()});
    // cout << "Agregando aeropuerto de partida a la cola de prioridad ->" << origen.value()->getCodigoIATA() << endl;

    while (!colaPrioridad.empty()) {
        Aeropuerto *aeropuertoActual = colaPrioridad.top().second;
        colaPrioridad.pop();
        if (aeropuertoActual == destino.value()) {
//            cout << "Estamos sobre el aeropuerto destino - " << destino.value()->getCodigoIATA()
//                 << " reconstruyendo ruta..."
//                 << endl;
            // TODO: Usar referencias
            std::list<Vuelo> ruta;
            Aeropuerto *aeropuerto = destino.value();

            while (aeropuerto != origen.value()) {
                // cout << "Agregando vuelo " << vuelosPrevios[aeropuerto].toString() << " a la ruta mas corta con duración " << vuelosPrevios[aeropuerto].getHorasVuelo() << endl;

                ruta.push_front(vuelosPrevios[aeropuerto]);
                aeropuerto = getAeropuerto(vuelosPrevios[aeropuerto].getCodigoIATAPartida()).value();
            }

//            cout << "Ruta más corta en tiempo desde " << origen.value()->getCodigoIATA() << " a "
//                 << destino.value()->getCodigoIATA() << " (Tiempo: " << tiempoDesdeOrigen[destino.value()] << " horas)"
//                 << endl;

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

    cout << "No se encontró una ruta desde " << origen.value()->getCodigoIATA() << " a "
         << destino.value()->getCodigoIATA() << endl;
    return {};
}

Graph::Graph(Hash<Aeropuerto *> *aeropuertos) {
    this->aeropuertos = aeropuertos;
}

void Graph::borrarAeropuerto(const string &codigoIATA){
    this->aeropuertos->borrar(codigoIATA);
}
