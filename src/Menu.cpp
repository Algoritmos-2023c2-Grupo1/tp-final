#include "Menu.h"

// consultar por un aeropuerto en particular
// dar de alta un nuevo aeropuerto
// dar de baja a alguno
// mostrar todos los aeropuertos(ordenados por codigo IATA)
// eleccion de camino minimo

Menu::Menu(Graph *graph) {
    opcion = 0;
    opciones = { "1. Consultar por un aeropuerto.", "2. Alta un nuevo aeropuerto", "3. Baja de un aeropuerto", "4. Mostrar todos los aeropuertos", "5. Elegir mejor opcion de viaje", "6. Salir" };
    controlador = Controlador(graph);
}

void Menu::start() {
	this->getSaludo();
	this->getOpciones();
};
void Menu::getSaludo() {
    controlador.saludo();
};
void Menu::getOpciones() {
    int opcionelegida;
    try {

        for (int i = 0; i < this->opciones.size(); i++) {

            cout << this->opciones[i] << endl;
        }
        cout << "Opcion: "; cin >> opcionelegida;
        this->setOpcion(opcionelegida);
    }
    catch (int n) {
        controlador.error();
        this->getOpciones();
    }
};
void Menu::setOpcion(int _opcion) {
	this->opcion = _opcion;
	this->realizarTarea();
};
void Menu::realizarTarea() {

    switch (this->opcion) {

        case 1:
            controlador.consultar();
            this->getOpciones();
            break;
        case 2:
            controlador.alta();
            this->getOpciones();
            break;
        case 3:
            controlador.baja();
            this->getOpciones();
            break;
        case 4:
            controlador.mostrarTodos();
            this->getOpciones();
            break;
        case 5:
            controlador.caminoMinimo();
            this->getOpciones();
            break;
        case 6:
            controlador.salir();
            exit(0);
            break;
        default:
            controlador.error();
            this->getOpciones();
            break;
    }
};