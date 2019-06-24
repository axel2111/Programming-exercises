/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesCadenas.h
 * Author: Axel
 *
 * Created on 9 de junio de 2019, 10:03 PM
 */

#ifndef FUNCIONESCADENAS_H
#define FUNCIONESCADENAS_H

FILE *abrirArchivo(char *nombArch,char *modo);
void leerCadena(char *aux,int numCar,FILE *arch);
char *leerCadenaExacta(FILE *arch);
void ordenarDatos(char **nombre,int numDatos);
void cambiar (char **arr , int i, int j);
#endif /* FUNCIONESCADENAS_H */

