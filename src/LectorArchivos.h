#ifndef TP_FINAL_LECTORARCHIVOS_H
#define TP_FINAL_LECTORARCHIVOS_H

#include <string>
#include "Aeropuerto.h"
#include "Vuelo.h"
#include "Hash.h"
#include "Graph.h"

using namespace std;

class LectorArchivos {
public:
    static void obtenerAeropuertosDesdeArchivo(Hash<Aeropuerto> *aeropuertos, Graph *grafo);

    static void obtenerVuelosDesdeArchivo(Hash<Aeropuerto> *aeropuertos, Graph *grafo);

private:

};


#endif //TP_FINAL_LECTORARCHIVOS_H
