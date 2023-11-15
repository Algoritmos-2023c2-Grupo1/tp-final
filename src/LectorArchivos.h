 //TP_FINAL_LECTORARCHIVOS_H
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
    static void obtenerAeropuertosDesdeArchivo(Graph *grafo);

    static void obtenerVuelosDesdeArchivo(Graph *grafo);
};


#endif