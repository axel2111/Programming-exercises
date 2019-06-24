/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEstadisticas.h
 * Author: Axel
 *
 * Created on 12 de mayo de 2019, 02:37 PM
 */

#ifndef FUNCIONESESTADISTICAS_H
#define FUNCIONESESTADISTICAS_H

void  leerNotas(int *,int *);
void  contarNotas(int *,int *, int ) ;
double porcentajeAprob(int *,int );
double promedio (int *,int ); 
double desviacionEstandar (double  , int * , int );
void imprimeResultados  (int *,double  , double ,int,double) ; 
int calcularMaximo (int *, int );
#endif /* FUNCIONESESTADISTICAS_H */

