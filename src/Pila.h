#ifndef TP_FINAL_PILA_H
#define TP_FINAL_PILA_H

#include<iostream>

using namespace std;

template<class T>
class Pila {
private:
    // Clase interna Nodo
    class Nodo {
    public:
        T dato;
        Nodo *siguiente;

        Nodo(T elemento) {
            dato = elemento;
            siguiente = NULL;
        }
    };


    Nodo *ultimo;

public:
    Pila() {
        ultimo = NULL;
    }

    void push(T dato) {
        Nodo *temp = new Nodo(dato);

        if (!temp) {
            cout << "Pila Overflow";
            exit(1);
        }
        temp->siguiente = ultimo;
        ultimo = temp;
    }

    bool vacia() {
        return (ultimo == NULL);
    }

    T top() {
        if (!vacia())
            return ultimo->dato;
        else
            exit(1);
    }

    void pop() {
        Nodo *temp;

        if (vacia()) {
            cout << "Pila Underflow" << endl;
            exit(1);
        } else {
            temp = ultimo;
            ultimo = ultimo->siguiente;
            free(temp);
        }
    }

    void mostrar() {
        Nodo *temp;

        if (vacia()) {
            cout << "\nPila Underflow";
            exit(1);
        } else {
            temp = ultimo;
            while (temp != NULL) {
                cout << temp->dato;
                temp = temp->siguiente;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

#endif //TP_FINAL_PILA_H
