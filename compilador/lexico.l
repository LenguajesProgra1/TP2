/*****************
 * Declaraciones *
 ****************/ 

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "sintactico.tab.h"	
	
	int linea=0;
%}

DIGITO [0-9]
VAL [A-Z][a-z]
CONST [a-z][a-z]

%%


 /*********************
  * Reglas y Acciones *
 **********************/

{DIGITO} {yylval.real=atof(yytext); return(DIGITO);}
{VAL} {yylval.real=atof(yytext); return(VAL);}
{CONST} {yylval.real=atof(yytext); return(CONST);}
"(" 	{return(PARA);}
")" 	{return(PARC);}
"," 	{return(COMA);}
"=" 	{return(IGUAL);}
">" 	{return(MAYOR);}
"[" 	{return(CORCHA);}
"]" 	{return(CORCHC);}
";" 	{return(PUNTOCOMA);}
":"	{return(DOSPUNTOS);}
"."	{return(PUNTO);}
"-"	{return(GUION);}
"|"	{return(CONS);}
"\n" 	{linea++;}
[\t\r\f] {}
" "		{}
 
.	{printf("Error lexico en linea %d",linea);}
%%
/*********************
 * Codigo de Usuario *
*********************/



