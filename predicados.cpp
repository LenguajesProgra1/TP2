#include <stdio.h>
#include <string.h>
#include<iostream>
#include<fstream>
#include<ctype.h>
#include"predicados.h"

int validarPredicado()
{
	char inicio[] = "<define>";
	char fin[] = "</define>";
	char valido[100];
	char predicado[100];
	ofstream txt ("bc.txt",std::ofstream::out | std::ofstream::app);
	if(txt.is_open())
	{
		cout << "?- " ;
		cin.getline(valido,100);
		if(strcmp (inicio,valido)==0)
		{
			cin.getline(predicado,100);
			while (strcmp (fin,predicado)!=0)
			{	
				txt << predicado << endl;
				cin.getline(predicado,100);
			}
		}
	}
}
