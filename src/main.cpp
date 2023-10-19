#include <iostream>
#include <string>
#include <list>

using namespace std;

class Node;
class Edge;

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
    
    void addEdge(Edge &edge) {
        vuelos->push_back(edge);
    }
    
    string toString() {
        return "\n \tNode [iata=" + iata + ", vuelos=" + "]";
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

int main() {
    
    Node eze("EZE");
    Node lax("LAX");
    Edge vuelo1(eze, lax, 12.4, 3456);
    cout << "Hola" << vuelo1.toString();
    return 0;    
}