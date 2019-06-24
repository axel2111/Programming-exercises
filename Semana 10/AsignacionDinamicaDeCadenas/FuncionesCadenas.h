/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesCadenas.h
 * Author: Axel
 *
 * Created on 6 de junio de 2019, 11:38 AM
 */

#ifndef FUNCIONESCADENAS_H
#define FUNCIONESCADENAS_H

void  leerCadena(char *cad, int numCar ,FILE *arch);
FILE  *abrirArchivo (char *nombArch,char *modo);
char *leerCadenaExacta (FILE *arch);
char *crecerPuntero (char *p , int inc);

#endif /* FUNCIONESCADENAS_H */

