/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 12 de junio de 2019, 05:57 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
int lonCad(char *cad);
void leerCadena(char *cad , int numCar , FILE *arch );
void copiarCadena(char *destino,char *fuente);
void concatenar(char *destino,char *fuente);
char *leerCadenaExacta(FILE *arch);
void buscarSeparador (char*separador ,char *frase);
void sacarPalabra(char *frase , char **arr ,int *num ,char *separar);
void leerDatosEmpleado(FILE *arch,char *nombre,int *codigo,double *sueldo);

#endif /* FUNCIONESAUX_H */

