/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 22 de mayo de 2019, 02:10 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void obtenerReporte (FILE * , FILE * ,FILE * , FILE *,FILE *,FILE *);
int verificarCurso(FILE *,FILE *,int ,int );
int buscarAlumnoLlevoCurso(int ,int ,FILE *);
double buscarCreditos(FILE *,int );
int buscarEspecialidad (int ,FILE *);
void  imprimeLinea(char ,int ,FILE *);
void cerrarArchivos (FILE * , FILE * ,FILE * , FILE *,FILE *,FILE *);
#endif /* FUNCIONESAUX_H */

