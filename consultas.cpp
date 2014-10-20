#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "predicados.h"

struct reglas {
    char pred[16];
    char args[32];
    char ant[64];
};

int saltoLinea(string str)// funcion para imprimir el write en pantalla
{
    int i=0;  
    char palabra[4];
    memset(palabra,0,4);
    int cont=0;
    while (i<str.length())
    {
        while (cont < 2)
        {
            palabra[cont] = str[i];
            cont++; i++;
        }
        if (strcmp(palabra,"nl")==0)
        {
            cout << endl;
        }
        i++;
    }
    return 1;
}


int write(string str)
{
    int i=6;  
    char palabra[32];
    memset(palabra,0,32);
    int cont=0;
    while (i<(str.length()-2))
    {  
      if (str[i] != '(' )
      {
          palabra [cont] = str[i];
          i++;
      }
      cont++;
    }
    cout << palabra <<endl;
    return 1;
}

int buscar(char* antecedente)
{
    char line[64];
    ifstream bc("bc.txt");
    while(bc.good())
    {
        bc >> line;
        if (strcmp(antecedente,line)== 0) 
        {
            bc.close();
            return 1;
        }
    }
    return 0;
}

int antecedentes(char* hechos,char* arg)
{
    int bandera=0,x=0,y=0,z=0;
    char hecho[64]; memset(hecho,0,64);
    while(hechos[x]!=46)
    {
        while(bandera==0)
        {
            hecho[y] = hechos[x];
            x++; y++;
            if(hechos[x]==40)
            {
                hecho[y] = '(';
                y++; x++;
                while(arg[z]!= 64)
                {
                    hecho[y] = arg[z];
                    y++; z++;
                }
                x++;
            }
            if(hechos[x]==44 ||hechos[x]==46)
            {
                hecho[y] = hechos[x];
                bandera++; x++;
                if(hecho[0]==119)
                {
                    int encontrado = write(hecho);
                    if(encontrado==1)
                        return 1;
                    else
                        return 0;
                }                   
                if(hecho[0]==110 && hecho[1]==108)
                {
                    int encontrado = saltoLinea(hecho);
                    if(encontrado==1)
                        return 1;
                    else
                        return 0;
                }                  
                else
                {
                    int encontrado = buscar(hecho);
                    if(encontrado==1)
                        return 1;
                    else
                        return 0;
                }
            }
        }
    }
}


void consulta(char* consult)
{
    int encontrado = buscar(consult);
    if (encontrado==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    else
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
        while(bandera==0)
        {
            consulta.pred[y] = consult[x];
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
            consulta.args[y] = consult[x];
            x++; y++;
            if(consult[x] == 41)
            {
                bandera++;
                x++;
                consulta.args[y] = '@';
            }
        }
        bandera=0;x=0;y=0;
        while(archivo.good())
        {
            archivo >> linea;
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
            if(strcmp(consulta.pred,regla.pred)==0)
            {
                if((linea[x]>=65) && (linea[x]<=90))
                {
                    char temp[64]; y=0;
                    memset(temp,0,64);
                    while(linea[x]!=45)
                        x++;
                    x++;
                    while(linea[x]!=46)
                    {
                        temp[y] = linea[x];
                        x++; y++;
                    }
                    temp[y] = linea[x];
                    int listo = antecedentes(temp,consulta.args);
                    if(listo==1)
                    {
                        cout<<"YES"<<endl;
                        archivo.close();
                        return;
                    }
                    else
                    {
                        cout<<"NO"<<endl;
                        archivo.close();
                        return;
                    }
                }
                else
                {
                    bandera=0;
                    x=0;
                    y=0;
                    memset(regla.pred,0,16);
                }
            }
            else
            {
                bandera=0;
                x=0;
                y=0;
                memset(regla.pred,0,16);
            }
        }
        cout<<"NO"<<endl;
        archivo.close();
        return;
    }
}
