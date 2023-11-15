#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H

#include<iostream>

using namespace std;


//------------------------------
template<typename T>
class Hash;

template<typename T>
class NodoH {
private:
    string clave;
    T valor;
    NodoH *siguiente;

    friend class Hash<T>;

public:
    NodoH(string clave, T valor) : clave(clave), valor(valor), siguiente(NULL) {
    }

    NodoH(NodoH &obj) {
        this->clave = obj.clave;
        this->valor = obj.valor;
        this->siguiente = NULL;
    }

    ~NodoH() {
        NodoH *inicio = this;
        while (inicio != NULL) {
            NodoH *actual = inicio;
            inicio = inicio->siguiente;
            delete actual;
        }
    }
};

template<typename T>
class Hash {
private:
    int modulo;
    NodoH<T> **lista;

    int funcionHash(string clave) {
        unsigned long n = 0;

        for (int i = 0; clave[i]; i++)
            n = clave[i] + (31 * n);

        return n % this->modulo;
    }

public:
    Hash(int clases) {
        this->modulo = clases;
        this->lista = new NodoH<T> *[this->modulo];
        this->lista[0] = NULL;
    }

    void insertar(string clave, T valor) {
        int clase = this->funcionHash(clave);
        NodoH<T> *nuevo = new NodoH<T>(clave, valor);

        if (this->lista[clase] != NULL)
            nuevo->siguiente = this->lista[clase];

        this->lista[clase] = nuevo;
    }

    T buscar(string clave) {
        int clase = this->funcionHash(clave);
        NodoH<T> *nodo = this->lista[clase];
        while (nodo != NULL) {
            if (nodo->clave == clave)
                return nodo->valor;
            nodo = nodo->siguiente;
        }
        return T();
    }

    list<T> listar() {
        list<T> valores;
        for (int i = 0; i < this->modulo; ++i) {
            NodoH<T> *nodo = this->lista[i];
            while (nodo != nullptr) {
                valores.push_back(nodo->valor);
                nodo = nodo->siguiente;
            }
        }
        return valores;
    }

    int size() {
        return modulo;
    }
};

#endif //TP_FINAL_HASH_H
