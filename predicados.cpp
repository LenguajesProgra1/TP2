#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "predicados.h"

int main ()
{
	system("clear");
    // bienvenida al usuario en consola
    cout<< "- - - - - - - - - Bienvenido al interprete de Prolog- - - - - - - - - \n *Si desea crear un hecho debe escribir <define>. \n *Para terminar el proceso de creacion se escribe </define>.\n *Si desea realizar una consulta solamente ingresela.\n *Para cerrar el interprete ingrese la palabra SALIR.\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n?-";

    ifstream archivo("bc.txt");//busca el archivo txt y lo lee
    char linea[12];
    char consul[]= "perro(gala).";
	char salir[] = "SALIR";
	char token[64];
  	char inicio[] = "<define>";

	do{
		cin.getline(token,64);
		if(strcmp(token,salir)==0)
			return 0;
		else
		{
			if(strcmp(token,inicio)==0)
				validarPredicado();
			else
			{
				if (archivo.good())
    			{
        			archivo >> linea;
        			if (strcmp(consul,linea)== 0) //compara cada linea del archivo con lo ingresado por el usuario
					{
						cout<< "Funciona \n";
						cout<<linea;
						archivo.close();
					}  
    			}
    			else
        			cout<< "Error al abrir el archivo";
			}
		}
	}while(true);
}
