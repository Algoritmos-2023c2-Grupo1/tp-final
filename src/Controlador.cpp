#define NOMINMAX
#include <windows.h>
#include <limits> 
#include <iostream>
#include <wchar.h>
#include <locale.h>
#include "Controlador.h"


void Controlador::saludo() {

	cout << "*****************************************************************************" << endl;
	cout << "*************** BIENVENIDO, VAMOS A COMENZAR A TRABAJAR. ********************" << endl;
	cout << "*****************************************************************************" << endl;
}

void Controlador::continuarOpciones() {
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
	try
	{
		setlocale(LC_ALL, "");
		string iata;
		generarEspacio();
		cout << "******************** PERFECTO, VAMOS A REALIZAR LA CONSULTA *******************" << endl;
		cout << "*******************************************************************************" << endl;
		cout << "Ingrese los datos solicitados " << endl;
		cout << "C�digo IATA: "; cin >> iata; cout << "" << endl;
		//ac� enviaria el codigo al manejador para que traiga el aeropuerto;
		aguardar();
	}
	catch (int n)
	{
		cargaDatosError();
	}
	
}
void Controlador::alta() {
	try
	{
		setlocale(LC_ALL, "");
		generarEspacio();
		string iata, nombre, ciudad, pais;
		float superficie;
		int terminales, dest_nacionales, dest_internacionales;
		cout << "***********************  PERFECTO, VAMOS A DAR DE ALTA ***************************" << endl;
		cout << "**********************************************************************************" << endl;
		cout << "Ingrese los datos solicitados " << endl;
		cout << "C�digo IATA: "; cin >> iata; cout << "" << endl;
		cout << "Nombre: ";  cin >> nombre; cout << "" << endl;
		cout << "Ciudad: ";  cin >> ciudad; cout << "" << endl;
		cout << "Pa�s: ";  cin >> pais; cout << "" << endl;
		cout << "Superficie: ";  cin >> superficie; cout << "" << endl;
		cout << "Cantidad de terminales: ";  cin >> terminales; cout << "" << endl;
		cout << "Cantidad de destinos nacionales: ";  cin >> dest_nacionales; cout << "" << endl;
		cout << "Cantidad de destinos internacionales: ";  cin >> dest_internacionales; cout << "" << endl;

		//Ac� se envian los datos al manejador para que lo agregue.
		// y se avisa que la tarea sali� satisfactoria.
		//  
		aguardar();
	}
	catch (int n)
	{
		cargaDatosError();
	}
	
}
void Controlador::baja() {
	try
	{
		setlocale(LC_ALL, "");
		generarEspacio();
		string iata;
		cout << "***********************  PERFECTO, VAMOS A DAR DE BAJA ***************************" << endl;
		cout << "**********************************************************************************" << endl;
		cout << "Ingrese el dato solicitado" << endl;
		cout << "C�digo IATA: "; cin >> iata; cout << "" << endl;
		
		// Ac� se manda el c�digo IATA al manejador de aeropuertos para que devuelva el aeropuerto.
		// Se muestran los datos del aeropuerto y se pregunta si quiere continuar.
		aguardar();
		// Si pone que S� se da de baja
	}
	catch (int n)
	{
		cargaDatosError();
	}
}
void Controlador::mostrarTodos() {
	try
	{
		setlocale(LC_ALL, "");
		generarEspacio();
		cout << "***************** PERFECTO, SE MOSTRAR�N TODOS LOS AEROPUERTOS ********************" << endl;
		cout << "***********************************************************************************" << endl;
		aguardar();
		//Ac� hace la llamada al manejador de los aeropuertos
		// para que devuelva un lista y se itera mostrandola.
	}
	catch (int n)
	{
		cargaDatosError();
	}
	
}
void Controlador::caminoMinimo() {
	try
	{
		setlocale(LC_ALL, "");
		generarEspacio();
		string iataorigen, iatadestino;
		int opcion;
		cout << "***********************  PERFECTO, VAMOS A AVERIGUAR LA MEJOR OPCI�N **************************" << endl;
		cout << "***********************************************************************************************" << endl;
		cout << "Ingrese los datos solicitados " << endl;
		cout << "C�digo IATA origen: "; cin >> iataorigen; cout << "" << endl;
		cout << "C�digo IATA destino: "; cin >> iatadestino; cout << "" << endl;
		cout << "Ahora ingrese el tipo de combinaci�n " << endl;
		cout << "1 _ M�s econ�mica." << endl;
		cout << "2 _ Menor tiempo." << endl;
		cin >> opcion;
		aguardar();

		//Ac� se env�an los datos al manejador para que devuelva la lista de combinaciones 
		// y se itera para mostrar

		//De estar vac�a hay que avisar que no hay conexiones posibles.
	}
	catch (const std::exception&)
	{
		cargaDatosError();
	}
}
void Controlador::salir() {
	try {
		setlocale(LC_ALL, "");
		generarEspacio();
		cout << "***********************************************************************************" << endl;
		cout << "***************** LA APLICACI�N SE CERRARA, HASTA LUEGO!! *******************" << endl;
		cout << "***********************************************************************************" << endl;
		Sleep(3000);
	}
	catch (int e) {
		cargaDatosError();
	}
}
void Controlador::error() {
	try {
		setlocale(LC_ALL, "");
		cout << "" << endl;
		cout << "" << endl;
		cout << "************************ OPCI�N ELEGIDA INCORRECTA **************************" << endl;
		cout << "*************************** Vuelva a intentarlo *****************************" << endl;
		cout << "*****************************************************************************" << endl;
		Sleep(5000);
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
		cout << " .";
		Sleep(1000);
	}
	cout << "" << endl;
}
