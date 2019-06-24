/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 10:34 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

FILE *abrirArchivo(char *,char* );
void leerDatos(char *arr,FILE *arch);
void leerCadena(char *aux,int numCar,FILE *arch);
void leerPalabrasSinonimos(char **,char **,int *);
char *leeCadenaExacta(FILE *);
void contarPalabrasUsadas(char *,char **,int *,int );
void sacarPalabras(char *,char **,int *);
void reemplazarSinonimos(char *linea,char **palabras,char **sinonimos,int numPalabras,FILE *archReporte);
void obtenerPalindromas(char *palindromas,char *linea,int*);
int palin(char *cadAux);
#endif /* FUNCIONESAUX_H */

