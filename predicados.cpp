#include <stdio.h>
#include <string.h>
#include<iostream>
#include<fstream>
#include<ctype.h>
#include <cstdlib>
#include"predicados.h"

int validarPredicado()
{
	system("clear");
	cout << "- - - - - - - - - Modo Declaracion de Hechos - - - - - - - - - -\n*Para salir del proceso de declaracion se escribe </define>.\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	char fin[] = "</define>";
	char predicado[100];
	ofstream txt ("bc.txt",std::ofstream::out | std::ofstream::app);
	if(txt.is_open())
	{
		cin.getline(predicado,100);
		while (strcmp (fin,predicado)!=0)
		{	
			txt << predicado << endl;
			cin.getline(predicado,100);
		}
		system("clear");
		cout<< "- - - - - - - - - Bienvenido al interprete de Prolog- - - - - - - - - \n *Si desea crear un hecho debe escribir <define>. \n *Para terminar el proceso de creacion se escribe </define>.\n *Si desea realizar una consulta solamente ingresela.\n *Para cerrar el interprete ingrese la palabra SALIR.\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n?-";
	}
}
