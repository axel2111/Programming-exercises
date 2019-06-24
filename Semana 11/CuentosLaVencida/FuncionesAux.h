/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 11 de junio de 2019, 03:13 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo (char *nomb,char *modo);
void leerCadena(char *arr,int numCar,FILE *arch);
void leerPalabras(char **palabras,FILE *archPalabras,int *numPalabras);
int lonCad(char *arr);
void concatenar(char *destino , char *fuente);
int obtenerOraciones(char *linea);
void copiarCadena(char *destino,char *fuente);
char *obtenerCadenaExacta(FILE *arch);
void obtenerPalabrasRepetidas(char **palabrasLista,int numPalabrasLista,int *palabrasRepetidas,char *linea);
int comparaCadena(char *arr1,char *arr2);
void sacarPalabras(char *frase,char **arr,int *cant);
void corregirTexto(char *linea,char **sinonimos,char **palabras,int numPalabras,
                        FILE *archReporte);
int sumarPalabras(char *linea);
void corregirCadena(char *cad,char*signo);
void palabrasPalindromas(char *linea,char *palindromas,int *primera);
void convertirMayuscula(char *cad);
int obtenerPalindroma(char *cadAux);
#endif /* FUNCIONESAUX_H */

