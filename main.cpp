#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "predicados.h"

struct reglas {
	char pred[16];
	char args[32];
	char ant[64];
	};

int buscar(char* antecedente)
{	
	char line[64];
	ifstream bc("bc.txt");//busca el archivo txt y lo lee
	while(Bc.good())
	{
		bc >> line;
		if (strcmp(antecedente,line)== 0) //compara cada linea del archivo con lo ingresado por el usuario
		{
			bc.close();
			return 1;
		}
	else
		return 0;
	}
}

void consulta(char* consult)
{
	int bandera=0,x=0,y=0;
	reglas consulta,regla;
	memset(consulta.pred,0,16);
	memset(consulta.args,0,32);
	memset(consulta.ant,0,64);
	memset(regla.pred,0,16);
	memset(regla.args,0,32);
	memset(regla.ant,0,64);
	ifstream archivo("bc.txt");//busca el archivo txt y lo lee
	char linea[64];
	int encontrado = buscar(consult);
	if (encontrado)
	{
		cout<<"YES"<<endl;
		return;
	}
	while(bandera==0)
	{
		r.pred[y] = consult[x];
		x++; y++;
		if(consult[x] == 40)
		{
			bandera++;
			x++;
		}
	}
	y=0;
	while(bandera==1)
	{
		r.args[y] = consult[x];
		x++; y++;
		if(consult[x] == 41)
		{
			bandera++;
			x++;
		}
	}
	bandera=0;x=0;y=0;
	while(archivo.good())
	{
		while(bandera==0)
		{
			regla.pred[y] = linea[x];
			x++; y++;
			if(linea[x] == 40)
			{
				bandera++;
				x++;
			}
		}
	if(strcmp(consulta.pred = regla.pred)&&linea[x]>=65 && linea[x]<=90)
	{
		char temp[64]; int z=0;
		bandera =0; y=0;
		while(bandera==0)
		{
			temp[y] = consulta.p
		}
		
	}
		
	}
	
	}
	
	
	cout<<"FALSE"<<endl;
	archivo.close();
	return;
}
