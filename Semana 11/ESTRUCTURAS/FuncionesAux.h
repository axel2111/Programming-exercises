/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 15 de junio de 2019, 02:03 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
#include "Nombre.h"
#include "Consultas.h"
void obtenerConsultas(struct Consultas *consultas,int *numConsultas);
void obtenerAportes(struct Nombre *nombre,struct Consultas consultas,int numDatos , int numConsultas);
void leerCadena(char*cad,int numCar , FILE *arch);
char *leerCadenaExacta(FILE *arch);
void sacarPalabras(char *frase,char **palabras,int *numPal);
void leerDatos (struct Nombre *nombre , int *numDatos );
#endif /* FUNCIONESAUX_H */

