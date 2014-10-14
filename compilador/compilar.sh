#!/bin/bash
bison -d sintactico.y -o sintactico.tab.cpp
flex lexico.l
gcc lex.yy.c sintactico.tab.cpp -o analizador -lfl -lm

