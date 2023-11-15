#include <limits>
#include <iostream>
#include <algorithm>
#include "Controlador.h"

Controlador::Controlador(Graph *_grafo) {
    grafo = _grafo;
};


void Controlador::saludo() {

    cout << "*****************************************************************************" << endl;
    cout << "*************** BIENVENIDO, VAMOS A COMENZAR A TRABAJAR. ********************" << endl;
    cout << "*****************************************************************************" << endl;
}

void Controlador::continuarOpciones() {
    cout << "" << endl;
    string enter;
    cout << "Toque c y luego Enter para continuar..." << endl;
    cin >> enter;
    generarEspacio();
    cout << "**************************** SIGAMOS TRABAJANDO *****************************" << endl;
    cout << "*****************************************************************************" << endl;
}

void Controlador::cargaDatosError() {
    cout << "Hubo un error en la carga de los datos....!!" << endl;
    cout << "Toque enter para continuar....!!" << endl;
    cout << "" << endl;
    cout << "" << endl;
    generarEspacio();
    continuarOpciones();
}

void Controlador::generarEspacio() {
    for (int i = 0; i < 200; i++) {
        cout << "" << endl;
    }
}

void Controlador::consultar() {
    try {
        string iata;
        generarEspacio();
        cout << "******************* PERFECTO, VAMOS A REALIZAR LA CONSULTA ******************" << endl;
        cout << "*****************************************************************************" << endl;
        cout << "Ingrese los datos solicitados " << endl;
        cout << "Código IATA: ";
        cin >> iata;
        cout << "" << endl;
        //aca enviaria el codigo al manejador para que traiga el aeropuerto;
        transform(iata.begin(), iata.end(), iata.begin(), ::toupper);
        aguardar();
        optional<Aeropuerto *> aeropuerto = grafo->getAeropuerto(iata);
        if (aeropuerto.has_value()) {
            generarEspacio();
            cout << "******************* Datos del aeropuerto buscado ******************" << endl;
            mostrarAeropuerto(aeropuerto.value());
        } else {
            cout << "No se ha encontrado ningun aeropuerto con el código ingresado." << "" << endl;
        }
        continuarOpciones();
    }
    catch (int n) {
        cargaDatosError();
    }

}

void Controlador::alta() {
    try {
        generarEspacio();
        string iata, nombre, ciudad, pais;
        float superficie;
        int terminales, dest_nacionales, dest_internacionales;
        cout << "********************* PERFECTO, VAMOS A DAR DE ALTA *************************" << endl;
        cout << "*****************************************************************************" << endl;
        cout << "Ingrese los datos solicitados " << endl;
        cout << "Código IATA: ";
        cin >> iata;
        cout << "" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "" << endl;
        cout << "Ciudad: ";
        cin >> ciudad;
        cout << "" << endl;
        cout << "País: ";
        cin >> pais;
        cout << "" << endl;
        cout << "Superficie: ";
        cin >> superficie;
        cout << "" << endl;
        cout << "Cantidad de terminales: ";
        cin >> terminales;
        cout << "" << endl;
        cout << "Cantidad de destinos nacionales: ";
        cin >> dest_nacionales;
        cout << "" << endl;
        cout << "Cantidad de destinos internacionales: ";
        cin >> dest_internacionales;
        cout << "" << endl;

        // TODO: Aca se envian los datos al manejador para que lo agregue.
        // y se avisa que la tarea salio satisfactoria.

        aguardar();
    }
    catch (int n) {
        cargaDatosError();
    }

}

void Controlador::baja() {
    try {
        generarEspacio();
        string iata;
        cout << "********************* PERFECTO, VAMOS A DAR DE BAJA *************************" << endl;
        cout << "*****************************************************************************" << endl;
        cout << "Ingrese el dato solicitado" << endl;
        cout << "Código IATA: ";
        cin >> iata;
        cout << "" << endl;

        // TODO: Aca se manda el codigo IATA al manejador de aeropuertos para que devuelva el aeropuerto.
        // Se muestran los datos del aeropuerto y se pregunta si quiere continuar.
        aguardar();
        // Si pone que Si se da de baja
    }
    catch (int n) {
        cargaDatosError();
    }
}

void Controlador::mostrarTodos() {
    try {
        generarEspacio();
        cout << "***************** PERFECTO, SE MOSTRARAN TODOS LOS AEROPUERTOS ********************" << endl;
        cout << "***********************************************************************************" << endl;
        aguardar();
        cout << "************************" << endl;
        for (auto aeropuerto: grafo->getAeropuertos()) {

            mostrarAeropuerto(aeropuerto);
            cout << "************************" << endl;
        }
    }
    catch (int n) {
        cargaDatosError();
    }
    continuarOpciones();
}

void Controlador::caminoMinimo() {
    try {
        generarEspacio();
        string iataorigen, iatadestino;
        int opcion;
        cout << "***********************  PERFECTO, VAMOS A AVERIGUAR LA MEJOR OPCIÓN **************************"
             << endl;
        cout << "***********************************************************************************************"
             << endl;
        cout << "Ingrese los datos solicitados " << endl;
        cout << "Código IATA origen: ";
        cin >> iataorigen;
        cout << "" << endl;
        cout << "Código IATA destino: ";
        cin >> iatadestino;
        cout << "" << endl;
        cout << "Ahora ingrese el tipo de combinación " << endl;
        cout << "1 _ Más económica." << endl;
        cout << "2 _ Menor tiempo." << endl;
        cin >> opcion;
        aguardar();

        list<Vuelo> ruta;
        if (opcion == 1){
            ruta = grafo->buscarRutaMasEconomica(iataorigen, iatadestino);
        } else if (opcion == 2 ){
            ruta = grafo->buscarRutaMasCortaEnTiempo(iataorigen, iatadestino);
        }

        if (ruta.empty()){
            cout << "No hay combinaciones posibles desde " << iataorigen << " hasta " << iatadestino << endl;
        } else {
            cout << "Combinacion de vuelos mas cortos en tiempo desde " << iataorigen << " hasta " << iatadestino << endl;
            for (const Vuelo& vuelo: ruta) {
                cout << vuelo.toString() << endl;
            }
        }

        continuarOpciones();
    }
    catch (const std::exception &) {
        cargaDatosError();
    }
}

void Controlador::salir() {
    try {
        generarEspacio();
        cout << "***********************************************************************************" << endl;
        cout << "******************** LA APLICACIÓN SE CERRARA, HASTA LUEGO!! **********************" << endl;
        cout << "***********************************************************************************" << endl;
    }
    catch (int e) {
        cargaDatosError();
    }
}

void Controlador::error() {
    try {
        cout << "" << endl;
        cout << "" << endl;
        cout << "************************ OPCIÓN ELEGIDA INCORRECTA **************************" << endl;
        cout << "*************************** Vuelva a intentarlo *****************************" << endl;
        cout << "*****************************************************************************" << endl;
        generarEspacio();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continuarOpciones();
    }
    catch (int e) {
        cargaDatosError();
    }
}

void Controlador::aguardar() {
    cout << "Aguarde un momento";
    for (int i = 0; i < 5; i++) {
        cout << ".";
    }
    cout << endl;
}

void Controlador::mostrarAeropuerto(Aeropuerto *aeropuerto) {
    cout << "Codigo IATA: " << aeropuerto->getCodigoIATA() << endl;
    cout << "Nombre: " << aeropuerto->getNombre() << endl;
    cout << "Ciudad: " << aeropuerto->getCiudad() << endl;
    cout << "Pais: " << aeropuerto->getPais() << endl;
    cout << "Superficie: " << aeropuerto->getSuperficie() << endl;
    cout << "Cantidad de terminales: " << aeropuerto->getCantidadTerminales() << endl;
    cout << "Destinos Nacionales: " << aeropuerto->getDestinosNacionales() << endl;
    cout << "Destinos Internacionales: " << aeropuerto->getDestinosInternacionales() << endl;
    cout << "Sus vuelos son: " << endl;
    for (const auto &vuelo: aeropuerto->getVuelos()) {
        cout << vuelo->toString();
    }
    cout << " " << endl;
}

Controlador::Controlador() {}
