#pragma once
#ifndef TP_FINAL_CONTROLADOR_H
#define TP_FINAL_CONTROLADOR_H

#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


// consultar por un aeropuerto en particular
// dar de alta un nuevo aeropuerto
// dar de baja a alguno
// mostrar todos los aeropuertos(ordenados por c�digo IATA)
// eleccion de camino minimo


class Controlador {

private:
    Graph *grafo;

public:
    Controlador(Graph *grafo);

    Controlador();

    void saludo();
    void continuarOpciones();
    void cargaDatosError();
    void generarEspacio();
    void consultar();
    void alta();
    void baja();
    void mostrarTodos();
    void caminoMinimo();
    void salir();
    void error();
    void aguardar();
    
};


#endif