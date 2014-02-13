//
//  main.cpp
//  Práctica_Grafos
//
//  Created by Jonás López Mesa on 27/03/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "grafo.h"
int menu();
int menu ()
{
	int opc = 0;
    cout << "MENÚ----------------------" << endl;
	cout << "1. Cargar y Mostrar Grafo." << endl;
    cout << "2. Salir." << endl;
    cout << "--------------------------" << endl;
    cout << "Opcion: ";
	do
	{
		cin >> opc;
		
	}while ( opc > 4 || opc < 1);
	
	return (opc);
}

int main ()
{
    char nombrefichero[50];
    int opcion;
    int x = 1;
    while(x == 1) 
    {
		opcion = menu ();
        
        if (opcion == 1) {
            cout << "Introduzca el nombre del fichero a cargar: ";
            cin >> nombrefichero;
            cout << "CONSTRUYENDO GRAFO..." << endl;
            GRAFO A(nombrefichero);
            cout << "Grafo construido" << endl;
            cout << "CREANDO LISTA DE PREDECESORES..." << endl;
            A.ListaPredecesores();
            cout << "Lista de predecesores construida" << endl;
            A.MostrarGrafo();
        }
		if (opcion == 2) {
            cout << "Fin del Programa" << endl;
            x=2;
            return 0;
        }
        if (opcion != 1 && opcion != 2) {
            cout << "Opción incorrecta, por favor escoja una opción correcta" << endl;
        }
    }
    return 0;
}

