#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main ()
{
    cout<< "----------Bienvenido al interprete de Prolog----------\n *Si desea crear un hecho debe escribir <define> y para terminar debe escribir </define>.\n *Si desea realizar una consulta solamente ingresela.\n";

    ifstream archivo("bc.txt");
    char linea[12];
    char *consul= "perro(gala).";
    if (archivo.good())
    {
        archivo >> linea;
        if (strcmp(consul,linea)== 0)
        {
            cout<< "Funciona \n";
            cout<<linea;
            archivo.close();
        }  
    }
    else
        cout<< "Error al abrir el archivo";
}
      
