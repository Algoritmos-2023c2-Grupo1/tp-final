//
// Created by ttoloza on 05/10/2023.
//

#ifndef TP_FINAL_LECTORARCHIVOS_H
#define TP_FINAL_LECTORARCHIVOS_H

#include <string>
#include "Aeropuerto.h"
#include "Vuelo.h"
#include "Lista.h"

using namespace std;

class LectorArchivos {
public:
    static vector<Aeropuerto> obtenerAeropuertosDesdeArchivo();

    static vector<Vuelo> obtenerVuelosDesdeArchivo();
private:

};


#endif //TP_FINAL_LECTORARCHIVOS_H
