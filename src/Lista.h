#ifndef TP_FINAL_LISTA_H
#define TP_FINAL_LISTA_H

using namespace std;

template<class T>
class Lista {
private:
    // Clase interna
    class Nodo {
    private:
        T *dato;
        Nodo *siguiente;

    public:
        Nodo(T *d) {
            dato = d;
            siguiente = NULL;
        }

        void setDato(T d) {
            dato = d;
        }

        void setSiguiente(Nodo *s) {
            siguiente = s;
        }

        T *getDato() {
            return dato;
        }

        Nodo *getSiguiente() {
            return siguiente;
        }
    };

    Nodo<T> *primero;
    int largo;

public:
    Lista() {
        primero = NULL;
        largo = 0;
    }

    void alta(Nodo<T> d, int pos) {
        Nodo<T> *nuevo = new Nodo<T>(d);
        if (pos == 1) {
            nuevo->setSiguiente(primero);
            primero = nuevo;
        } else {
            Nodo<T> *anterior = getNodo(pos - 1);
            Nodo<T> *siguiente = anterior->getSiguiente();
            nuevo->setSiguiente(siguiente);
            anterior->setSiguiente(nuevo);
        }
        largo++;
    }

    void baja(int pos) {
        Nodo<T> *borrar;
        if (pos == 1) {
            borrar = primero;
            primero = borrar->getSiguiente();
        } else {
            Nodo<T> *anterior = getNodo(pos - 1);
            borrar = anterior->getSiguiente();
            Nodo<T> *siguiente = borrar->getSiguiente();
            anterior->setSiguiente(siguiente);
        }
        delete borrar;
        largo--;
    }

    T *consulta(int pos) {
        Nodo<T> *aux = getNodo(pos);
        return aux->getDato();
    }

    bool vacia() {
        return (largo == 0);
    }

    virtual ~Lista() {
        while (!vacia())
            baja(1);
    }

    int getLargo() {
        return largo;
    }

    void mostrar() {
        cout << "[";

        if (!vacia()) {
            for (int i = 1; i < largo; i++)
                cout << consulta(i) << ",";
            cout << consulta(largo);
        }

        cout << "]" << endl;
    }

private:
    Nodo<T> *getNodo(int pos) {
        Nodo<T> *aux = primero;
        for (int i = 1; i < pos; i++)
            aux = aux->getSiguiente();
        return aux;
    }
};

#endif //TP_FINAL_LISTA_H