%{

/********************** 
 * Declaraciones en C++ *
 **********************/


  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include "string.h"
  extern int yylex(void);
  extern char *yytext;
  extern int linea;
  extern FILE *yyin;
  void yyerror(char *s);
%}

/*************************
  Declaraciones de Bison *
 *************************/


%union
{
  float real;
  char* VAL;
  char* Nombre;
  char* CONST
}


%start lista_i;

/*tokens validos para sintaxis*/

%token <real> DIGITO
%token <real> VAL
%token <real> CONST
%token PARA
%token PARC
%token COMA
%token IGUAL
%token MAYOR
%token CORCHA
%token CORCHC
%token PUNTOCOMA
%token DOSPUNTOS
%token PUNTO
%token GUION
%token CONS



%type <texto> Nombre



%%
/***********************
 * Reglas Gramaticales *
 ***********************/


lista_i : 	lista_i i;
			| i
			;
i:			hecho PUNTO
			|error PUNTO  /* Recuperacion de error modo panico */
			;

hecho:			Nombre PARA /*VACIO*/ PARC PUNTO;
hecho:			VAL
			|hecho ',' VAL
			;
			
predicado:		Nombre PARA VAL PARC PUNTO;
									
			
			;
			
							
		


			;	

%%
/**********************
 * Codigo C Adicional *
 **********************/
void yyerror(char *s)
{
	printf("Error sintactico %s \n",s);
}

int main(int argc,char **argv)
{
	
	if (argc>1)
		yyin=fopen(argv[1],"rt");
	else
		//yyin=stdin;
		yyin=fopen("entrada.txt","rt");
		

	yyparse();
	return 0;
}