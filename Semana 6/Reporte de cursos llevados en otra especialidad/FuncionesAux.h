/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 5 de mayo de 2019, 10:27 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void obtenerReporte(FILE* ,FILE* ,FILE* , FILE*,FILE*);
void mostrarReporte(int,int,FILE*,FILE*,FILE*,FILE*);
void cursosEnOtraEspecialidad(int , int , int *,double *,double *,FILE*,FILE*);
void buscarNotaCurso(double *,int *,int , int ,FILE *);
void imprimeLinea(char ,int,FILE *);
void cerrarArchivos(FILE* ,FILE* ,FILE* , FILE*,FILE*);

#endif /* FUNCIONESAUX_H */



