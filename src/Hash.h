#ifndef TP_FINAL_HASH_H
#define TP_FINAL_HASH_H

#include<iostream>
#include"Lista.h"

using namespace std;

template <class T>
class Hash
{
private:
    int tamanio;
    Lista<T> *tabla;
public:
    Hash(int size)
    {
        tamanio = size;
        tabla = new Lista<T>[tamanio];
    }

    void insertItem(int key, T item)
    {
        int index = hashFunction(key);
        tabla[index]->alta(item, 1);        
    }
 
    void deleteItem(int key)
    {
    
    }
 
    int hashFunction(int key) 
    {
        return (key % tamanio);
    }
 
    void display()
    {
        for(int i=0; i<tamanio; i++) {
            cout << i;
            tabla[i].mostrar();
            /*
            for (int j=1; j < tabla[i].getLargo()+1; j++)
                cout << " --> " << tabla[i].consulta(j)->getDni();
            */
            cout << endl;
        }
    }
    
    void setItem(int i, Lista<T> *item) 
    {
        tabla[i] = *item;    
    }
    
    Lista<T>* getItem(int i) 
    {
        return &tabla[i];    
    }
    
};

#endif //TP_FINAL_HASH_H
