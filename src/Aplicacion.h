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
    Hash<Aeropuerto> *aeropuertos = new Hash<Aeropuerto>(5);
    Graph *grafo = new Graph(); // TODO: Usar hash en grafo
    Menu *menu = new Menu(grafo);

    LectorArchivos::obtenerAeropuertosDesdeArchivo(aeropuertos, grafo);
    LectorArchivos::obtenerVuelosDesdeArchivo(aeropuertos, grafo);

    menu->start();
}


#endif //TP_FINAL_APLICACION_H
