#ifndef TP_FINAL_MENUPRINCIPAL_H
#define TP_FINAL_MENUPRINCIPAL_H

#include <string>

using namespace std;

class MenuPrincipal {
public:

    // Consultar información de un aeropuerto en particular
    void obtenerInfoAeropuerto();

    // Dar de alta un nuevo aeropuerto
    void crearAeropuerto();

    // Dar de baja un aeropuerto
    void eliminarAeropuerto();

    // Mostrar todos los aeropuertos (ordenados por código IATA)
    void listarAeropuertosSegunCodigoIATA();

    // Buscar la ruta más económica entre dos aeropuertos
    void buscarRutaMasEconomica();

    // Buscar la ruta más rápida entre dos aeropuertos
    void buscarRutaMasRapida();

    // Salir del programa
    void finalizar();


};


#endif //TP_FINAL_MENUPRINCIPAL_H
