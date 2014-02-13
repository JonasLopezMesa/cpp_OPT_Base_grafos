//
//  grafo.h
//  Práctica_Grafos
//
//  Created by Jonás López Mesa on 27/03/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Pra_ctica_Grafos_grafo_h
#define Pra_ctica_Grafos_grafo_h

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

// Definición de un elemento de una lista de Adyacencia
typedef struct {
    unsigned j; // nodo
    int      c; // peso, longitud, etc
}ElementoLista;
// Definición de una lista de adyacencia de un nodo
typedef vector<ElementoLista> LAnodo;

class GRAFO
{
    unsigned    dirigido; // 0 si el grafo es no dirigido y 1 si es dirigido
    unsigned    n; //dimensión
    unsigned    m; //numero de aristas o arcos.
    vector<LAnodo> LS; // Lista de adyacencia de los Sucesores 
    vector<LAnodo> LP; // Lista de adyacencia de los Predecesores 
    //Métodos Privados
    void dfs(unsigned i, vector<bool> &visitado);
    void dfsOrder(unsigned i, vector<unsigned> &order, vector<bool> &visitado, unsigned &cont);
    void dfsInv(unsigned i, vector<bool> &visitado);
public:
    GRAFO(char nombrefichero[]); // constructor
    ~GRAFO(); // destructor
    void ListaPredecesores(); // Construye la lista de predecesores 
    void MostrarGrafo(); // Método para mostrar el grafo por pantalla 
    void ComponentesConexas();
    void ComponentesFuertementeConexas();
};


#endif
