#ifndef TP_FINAL_MENU_H
#define TP_FINAL_MENU_H

#include <iostream>
#include <vector>
#include "Controlador.h"

using namespace std;


// consultar por un aeropuerto en particular
// dar de alta un nuevo aeropuerto
// dar de baja a alguno
// mostrar todos los aeropuertos(ordenados por codigo IATA)
// eleccion de camino minimo


class Menu {

    private:
        int opcion;
        vector<string> opciones;
        Controlador controlador;

    public:
        Menu();
        Menu(Graph *graph);
        void start();
        void getSaludo();
        void getOpciones();
        void setOpcion(int _opcion);
        void realizarTarea();
};


#endif