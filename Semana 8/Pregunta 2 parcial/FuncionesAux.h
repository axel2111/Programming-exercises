/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 19 de mayo de 2019, 08:33 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void leerEmpleados(int *,int *,double * );
void leerPlanilla(int , int ,double *,int *,int *);
int calculaDiasTotal(int , int* );
double calculaSueldoTotal(int ,double *);
void calculaMontos(double *,double *,double *,int ,double ,int , double ,int * ,double * );
void imprimirResultados (double*,double,FILE *,int *,double *,
                         double *, double *, int );
void imprimeLinea(char,int,FILE* );
void imprimeGrafica(FILE *archGrafica,double *utilidad, int numEmpleados);
int calculaElMayor(int *, int );
#endif /* FUNCIONESAUX_H */

