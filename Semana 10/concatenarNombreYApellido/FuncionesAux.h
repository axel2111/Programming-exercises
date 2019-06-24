/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 6 de junio de 2019, 01:50 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

FILE *abrirArchivo (const char *nombArch,const char *modo);
void leerCadena(char *cad ,  int numCar ,  FILE *arch);
char *leerCadenaExacta(FILE *arch);
char *crecerPuntero (char *cad,int inc );
#endif /* FUNCIONESAUX_H */

