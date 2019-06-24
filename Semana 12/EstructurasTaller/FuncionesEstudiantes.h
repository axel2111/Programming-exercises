/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEstudiantes.h
 * Author: Axel
 *
 * Created on 20 de junio de 2019, 10:44 AM
 */

#ifndef FUNCIONESESTUDIANTES_H
#define FUNCIONESESTUDIANTES_H
#include "Estudiante.h"
void leerEstudiantes (struct Estudiante *estudiante ,int *numEstudiamtes); 
void leerCadena (char *cadAux , int numCar , FILE *arch);
char *leerCadenaExacta (FILE *arch);
void sacarPalabras(char *frase , char **palabra , int *numPal ,char separador );
void leerEstudiantes (struct Estudiante *estudiante ,int *numEstudiantes);
void ordenarEstudiantes(struct Estudiante *estudiante,int numEstudiantes);
void buscarAlumnosHorario (struct Estudiante *estudiante,int numEstudiantes);
void linea (char c , int numCar);
#endif /* FUNCIONESESTUDIANTES_H */

