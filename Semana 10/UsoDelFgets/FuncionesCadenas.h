/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesCadenas.h
 * Author: Axel
 *
 * Created on 4 de junio de 2019, 08:09 PM
 */

#ifndef FUNCIONESCADENAS_H
#define FUNCIONESCADENAS_H

char corregirCadena(char *cad);
int longitudCadena(const char *cad);
void leerCadena(char *palabra,int numCar,FILE *arch);
void copiarCadena(char *destino, const char *origen) ; 
int comparaCadena (char *cad1,char *cad2);
void     concatenarCadena(char *cad1,const char *fuente);

#endif /* FUNCIONESCADENAS_H */

