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
    auto *grafo = new Graph(aeropuertos);
    auto *menu = new Menu(grafo);

    LectorArchivos::obtenerAeropuertosDesdeArchivo(grafo);
    LectorArchivos::obtenerVuelosDesdeArchivo(grafo);

    menu->start();
    //TODO: menu->clean();
}


#endif //TP_FINAL_APLICACION_H
