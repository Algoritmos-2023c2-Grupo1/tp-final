#ifndef TP_FINAL_COLA_H
#define TP_FINAL_COLA_H

#include<iostream>

using namespace std;

template <class T>
class Cola {
private:
    // Clase interna
    class Nodo {
    public:
	    T dato;
	    Nodo* siguiente;
	    
	    Nodo(T d)
	    {
		    dato = d;
		    siguiente = NULL;
	    }
    };
public:
	Nodo *primero;
	Nodo *ultimo;
	
	Cola() 
	{ 
		primero = NULL; 
		ultimo = NULL;
	}

	void aColar(T x)
	{
		Nodo* temp = new Nodo(x);

		if (ultimo == NULL) {
			primero = ultimo = temp;
			return;
		}

		ultimo->siguiente = temp;
		ultimo = temp;
	}

	T desaColar()
	{
		if (primero == NULL)
			exit (1);

		Nodo* temp = primero;
		T dato = temp->dato;
		primero = primero->siguiente;

		if (primero == NULL)
			ultimo = NULL;
    
        	delete(temp);
		return dato;
	}

	void mostrar()
	{
		Nodo* temp;

		if (primero == NULL) {
			cout << "\nCola Underflow";
			exit(1);
		}
		else 
		{
			temp = primero;
			while (temp != NULL) {
				cout << temp->dato;
				temp = temp->siguiente;
				if (temp != NULL)
					cout << " <- ";
			}
			cout << endl;
		}
	}	
};

#endif //TP_FINAL_COLA_H