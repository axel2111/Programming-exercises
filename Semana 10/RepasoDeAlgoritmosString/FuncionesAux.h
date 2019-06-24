/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 9 de junio de 2019, 11:03 AM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo(char *nombArch,char *modo);
void leerCadena(char *cad,int numCar,FILE *arch);
int lonCad(char *cad);
void copiarCadena(char *destino, char *origen);
void concatenarCadena(char *destino,char *fuente);
#endif /* FUNCIONESAUX_H */

