//
//  grafo.cpp
//  Práctica_Grafos
//
//  Created by Jonás López Mesa on 27/03/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "grafo.h"


//////////////////////////////////////////////CONSTRUCTOR
GRAFO::GRAFO(char nombrefichero[]){ 
    unsigned int i, j, k/*p*/;              //variables de recorrido yde almacenaje de información
	ElementoLista dummy;                    //variable tipo ElementoLista que va a almacenar las variables j y c
	ifstream tex;                           //variable tipo ifstream que es la que irá recogiendo los datos del fichero
    cout << nombrefichero << endl;
	tex.open(nombrefichero);                //Se abre el fichero en la variable text
	if (tex.is_open())                      //Si el fichero se abrió correctamente entonces:
	{
		LP.clear();                         //vacía la lista de adyacencia de los sucesores
		LS.clear();                         //vacía la lista de adyacencia de los predecesores
		tex >> n >> m >> dirigido;          //saca los tres primeros valores de tex: el número de nodos, el número de arístas y si el grafo 
                                            //es dirigido o no
		LS.resize(n);                       //Redimensiona el vector LS(lista de sucesores) para que tenga tamaño n(números de nodos)
		for (k=0;k<m;k++)                   //por cada una de las aristas hacer:
		{
			tex >> i >> j;                  //recoge el nodo y a donde se dirije su arista
			//dummy.c=p;                    //asigna el valor del coste a dummy.c
			dummy.j=j-1;                    //asigna el valor de a que nodo se dirije la arista a dummy.j
			LS[i - 1].push_back(dummy);     // introduce el la lista de adyacencia el valor de dummy, tanto la c como la j.
			if ( dirigido == 0 )            //si el grafo no es dirigido, entonces:
			{
				dummy.j=i-1;                //a continuación de la anterior j, asigna una arista en sentido contrario, es decir, hacia el
                                            //nodo de origen
				//dummy.c=p;                //añade el coste de esa arista
				LS[j-1].push_back(dummy);   //introduce dummy en el vector de adyacencia
			}
		}
	}
	tex.close();                            //cierra el archivo
}

/////////////////////////////////////////////DESTRUCTOR
GRAFO::~GRAFO(){ 
    LP.clear(); //vacía la lista de adyacencia de los sucesores
    LS.clear(); //vacía la lista de adyacencia de los sucesores
}

void GRAFO::MostrarGrafo(){
    cout << "Atriburos del Grafo" << endl; 
    cout << n << " " << m << " " << dirigido << endl;
    cout << "Lista de Sucesores" << endl;
    for (int k=0; k < LS.size(); k++) {
        for (int w=0; w < LS[k].size(); w++) {
            cout << k+1 << "--->" << LS[k][w].j+1 << endl;
        }
    }
    if (dirigido == 1) {
        cout << "Lista de Predecesores" << endl;
        for (int k=1; k < LS.size(); k++) {
            for (int w=0; w < LP[k].size(); w++) {
                cout << k+1 << "--->" << LP[k][w].j+1 << endl;
            }
        }
    }

    
        ComponentesConexas();

}

void GRAFO::ListaPredecesores() {
    if (dirigido == 1) {
        ElementoLista dummy;
        LP.resize(n);
        for (int k=0; k < LS.size(); k++) {
            for (int w=0; w < LS[k].size(); w++) {
                dummy.j = k;
                LP[LS[k][w].j].push_back(dummy);
            }
        }
    }
}

void GRAFO::ComponentesConexas() {
    unsigned i, componentesconexas = 0;
    vector<bool> visitado;
    visitado.resize(n,false);
    i=0;
    while (i < n) {
        if (visitado[i] == false) {
            componentesconexas++;
            cout << "componente Conexa " << componentesconexas << " {: ";
                dfs(i,visitado);
            cout << endl;
            }
            i++;
        }

}

void GRAFO::dfs(unsigned i, vector<bool> &visitado) {
    visitado[i] = true;
    cout << i+1 << " ";
    //para todo nodo j en LS[i] no visitado hacer
    for (int j = 0; j < LS[i].size(); j++) {
        if (visitado[LS[i][j].j] == false) {
            dfs(LS[i][j].j,visitado);
        }
    }
   }
