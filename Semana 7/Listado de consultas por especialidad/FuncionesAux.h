/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 9 de mayo de 2019, 12:41 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H


void obtenerReporte (FILE *, FILE *, FILE * ,FILE * ,FILE *, int ,int);
void mostrarReporte(int ,double ,FILE *,FILE *,FILE *,int,int,FILE*,double*,double*,int*,double*,double *,
                                    int *,int*,int *,int *);
int obtenerConsultas( int  , FILE *, FILE *,int , int,FILE*);
void mostrarConsultas(double *,double *,int *,FILE *,FILE *, int , double,int ,int,FILE* );
void buscarPaciente(int,int *,int *,double *,FILE *,double ,FILE *);
void imprimeLinea (char  , int,FILE *) ; 
void cerrarArchivos (FILE *, FILE *, FILE * ,FILE * ,FILE *);
#endif /* FUNCIONESAUX_H */

