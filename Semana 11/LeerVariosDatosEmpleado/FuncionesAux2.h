/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 12 de junio de 2019, 08:47 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo (char *nombre,char *modo);
void leerCadena(char *cad,int numCar,FILE *arch);
char *leerCadenaExacta(FILE *arch);
void buscarSeparador(char *separador,char *frase);
void sacarPalabra(char *frase,char **palabras,int *numPalabras,char *separador);
void leerDatosEmpleado(FILE *arch ,int *codigo,double *sueldo,char **nombre,int *numEmpleados);
void cambiarI(int *arr,int i,int j);
void cambiarD(double *arr,int i,int j);
void cambiarC(char **arr,int i,int j);
void ordenarDatosEmpleado(int *codigo,double *sueldo,char **nombre, int numEmpleados);
#endif /* FUNCIONESAUX_H */

