/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesCadenas.h
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 02:41 PM
 */

#ifndef FUNCIONESCADENAS_H
#define FUNCIONESCADENAS_H
void leerFrase(char *cadena,FILE *arch);
void nombrePropio(char *cadena);
int lonCad(char *cad);
void concatenar(char *destino,char *fuente);
void copiarCadena(char *destino,char *fuente);
FILE *abrirArchivo (char *nombArch  ,char *modo);
int subConjunto(char *cadena1,char *cadena2);
void codigoAleatorio(char *codigo,char *cadena);
    
#endif /* FUNCIONESCADENAS_H */

