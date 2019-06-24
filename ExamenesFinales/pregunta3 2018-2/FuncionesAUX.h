/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAUX.h
 * Author: Axel
 *
 * Created on 14 de junio de 2019, 03:50 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo (char *nombre, char *modo);
void  leerDatos(char **nombre,int *operaciones,int *numOperaciones);
void mostrarReporte(double tiempo,char **nombre,int *operaciones,int numOperaciones);
void leerCadena(char *cad,int numCar,FILE *arch);
char *leerCadenaExacta(FILE *arch);
void sacarPalabras(char *frase,char **palabras,int *numPalabras,char *separador);
#endif /* FUNCIONESAUX_H */

