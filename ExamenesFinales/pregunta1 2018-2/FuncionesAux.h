/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 13 de junio de 2019, 03:34 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo(char *nombre,char *modo);
void leerCadena(char *cad , int numCar,FILE *arch);
char *leerCadenaExacta(FILE *arch);
void leerListaDeArchivos(char **lista,int *numArchivos, FILE *archLista);
void cambiarC(char **arr , int i , int j );
void ordenarArchivos(char **lista,int numArchivos);
void obtenerReporte(char *buscar,char **lista,int numArchivos);
void mostrarReporte(FILE *reporte,int *posLinea,int numPosLinea);
void buscarPalabra(int *posLinea,int *numPosLinea,char *buscar,FILE *arch);
FILE *verificarArchivo(char **lista,int i );
void buscarSeparador(char *separador,char *frase);
void sacarPalabras(char *frase,char **palabras,int *numPalabras,char *separador);

#endif /* FUNCIONESAUX_H */

