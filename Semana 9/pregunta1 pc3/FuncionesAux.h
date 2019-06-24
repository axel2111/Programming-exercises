/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 24 de mayo de 2019, 04:12 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void leerArticulos(int *,double *,double *,int *,int *);
void reescribirArticulos(int *,double *,double *,int *,int );
void cambiar (int *,int  ,int );
void cambiarD (double *,int  ,int );
void montoGastado(double *,int *,double *,double *,int *,int,int* );
void leerCompras (int *, int * ,int * ,double *,int *,
                int *,double *,double *,int *, int );
double costo(int ,int ,int *,double *,double *,
                int *,int );
void ordenarFechaYHora(int *,int *,int *,double *,int );
void imprimirMontoGastado(int *,int *,int *,double *,int );
void convertirFecha(int *,int ,int *,int *,int *);
void convertirHora(int *,int ,int *,int *,int *);
void estadisticaGastos(double *,int ,FILE *);
void ordenarGasto(double *gastoOrdenado,double *gasto,int numC);
#endif /* FUNCIONESAUX_H */

