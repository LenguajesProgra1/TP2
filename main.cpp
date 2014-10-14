#include <iostream>
#include <cstdlib>
#include <cstring>
#include "predicados.h"

int main ()
{
	system("clear");
    // bienvenida al usuario en consola
    cout<< "- - - - - - - - - Bienvenido al interprete de Prolog- - - - - - - - - \n * Si desea crear un hecho debe escribir <define>. \n * Para terminar el proceso de creacion se escribe </define>.\n * Si desea realizar una consulta solamente ingresela.\n * Para cerrar el interprete ingrese la palabra SALIR.\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n?-";
    
	char salir[] = "SALIR";
	char token[64];
  	char inicio[] = "<define>";

	do{
		cin.getline(token,64);
		if(strcmp(token,salir)==0)
		{
			system("clear");
			return 0;
		}
		else
		{
			if(strcmp(token,inicio)==0)
				validarPredicado();
			else
			{
				consulta(token);
			}
		}
	}while(true);
}
