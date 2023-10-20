#include <iostream>
#include <iterator>
#include<fstream>
#include <string>
#include <list>

using namespace std;

class Edge;
class Node;

class Node {
private:
    string iata;
    list<Edge>* vuelos;
public:
    Node(string iata="") { 
        this->iata = iata;
        this->vuelos = new list<Edge>();
    }
    
    string getIATA() { return iata; }
    
    void setIATA(string iata) { this->iata = iata; }
    
    list<Edge>* getVuelos() { return vuelos; }
    
    void addVuelo(Edge &edge) {
        vuelos->push_back(edge);
    }
    
    string toString() {
        return "\n \tNode [iata=" + iata + ", vuelos=" + showlist() + "]";
    }

    string showlist()
    {
        string output = "";
        
/*
        list<Edge>::iterator it;
        for (it = vuelos->begin(); it != vuelos->end(); ++it)
            string txt = it->toString();
            output += '\t' + txt + "\t";
*/
        return to_string(vuelos->size());
    }

};

class Edge {
private:
    Node origen;
    Node destino;
    float tiempo_vuelo;
    int costo_vuelo;

public:
    Edge(Node origen, Node destino, float tiempo_vuelo, int costo_vuelo) 
    {
        this->origen = origen;
        this->destino = destino;
        this->tiempo_vuelo = tiempo_vuelo;
        this->costo_vuelo = costo_vuelo;
    }
    
    Node getOrigen() {
        return origen;
    }
    
    void setOrigen(Node origen) {
        this->origen = origen;
    }
    
    Node getDestino() {
        return destino;
    }
    
    void setDestino(Node destino) {
        this->destino = destino;
    }
    
    float getTiempoVuelo() {
        return tiempo_vuelo;
    }
    
    void setTiempoVuelo(float tiempo) {
        this->tiempo_vuelo = tiempo;
    }
    
    int getCostoVuelo() {
        return costo_vuelo;
    }
    
    void setCostoVuelo(int costo) {
        this->costo_vuelo = costo;
    }
    string toString() {
        return 
            "\n Edge [origen=" + origen.getIATA() + 
                   ", destino=" + destino.getIATA() + 
                   ", tiempo=" + to_string(tiempo_vuelo) +
                   ", costo=" + to_string(costo_vuelo) + "]";
    }
};

class Graph {
private:
    list<Node>* nodes;

public:
    Graph() {
        nodes = new list<Node>();
    }
    void addAeropuerto(Node &node) {
        nodes->push_back(node);
    }

    list<Node>* getNodes() {
        return nodes;
    }

    string toString() {
        return "Graph [nodes=" + to_string(nodes->size()) + "]";
    }

    void addVueloANodo(string iata, Edge vuelo) {
        list<Node>::iterator it;
        for (it = nodes->begin(); it != nodes->end(); ++it)
        {
            if (it->getIATA() == iata)
                it->addVuelo(vuelo);
        }
    }

    void showlist()
    {
        list<Node>::iterator it;
        for (it = nodes->begin(); it != nodes->end(); ++it)
            cout << '\t' << it->toString();
        cout << '\n';
    }    

};



int main() {
    Graph *lista = new Graph();
    Node eze("EZE");
    Node lax("LAX");
    Edge vuelo1(eze, lax, 12.4, 3456);

    cout << "Hola" << vuelo1.toString() << endl;

    ifstream file1("../resources/aeropuertos.txt");
    
	string iata;
	string nombre;
	string ciudad;
	string pais;
	float superficie;
	int terminales;
	int destNacionales;
	int destInternacionales;
    
    while (file1 >> iata >> nombre >> ciudad >> pais >> superficie >> terminales >> destNacionales >> destInternacionales)
    {
        //cout << iata << " " << nombre << endl;
        Node aeropuerto(iata);
        lista->addAeropuerto(aeropuerto);       
    }
    
    lista->showlist();
    
    file1.close();

    ifstream file2("../resources/vuelos.txt");
    
	string origen;
	string destino;
	int costo_vuelo;
	float tiempo_vuelo;
    
    while (file2 >> origen >> destino >> costo_vuelo >> tiempo_vuelo)
    {
        //cout << origen << " " << destino << " " << costo_vuelo << " " << tiempo_vuelo << endl;
        Edge vuelo(origen, destino, costo_vuelo, tiempo_vuelo);
        lista->addVueloANodo(origen, vuelo);
    }
    
    lista->showlist();
    
    file2.close();

    return 0;
}