/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 12:13 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
char *leerCadenaExacta(FILE *arch);
void leerCadena(char *cad,int numCar,FILE *arch);
int lonCad(char *cad);
void copiarCadena(char *destino,char *fuente);
void sacarPalabra(char *frase,char **palabra,int *numDatos);
#endif /* FUNCIONESAUX_H */

