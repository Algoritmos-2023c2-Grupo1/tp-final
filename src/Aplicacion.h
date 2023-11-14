#ifndef TP_FINAL_APLICACION_H
#define TP_FINAL_APLICACION_H

#include "Graph.h"
#include "Menu.h"
#include "Hash.h"
#include "Aeropuerto.h"
#include "LectorArchivos.h"

class Aplicacion {
private:

public:
    static void ejecutar();
};

void Aplicacion::ejecutar() {
    auto *aeropuertos = new Hash<Aeropuerto*>(5);
    auto *grafo = new Graph(aeropuertos); // TODO: Usar hash en grafo
    auto *menu = new Menu(grafo);

    LectorArchivos::obtenerAeropuertosDesdeArchivo(aeropuertos, grafo);
    LectorArchivos::obtenerVuelosDesdeArchivo(aeropuertos, grafo);

    menu->start();
}


#endif //TP_FINAL_APLICACION_H
