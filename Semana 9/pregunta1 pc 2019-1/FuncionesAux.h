/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 27 de mayo de 2019, 10:08 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
void leerUtilidades(int *,double *,double *,int *);
void ordenarUtilidades(int *,double *,double *,int );
void cambiar(int *,int ,int );
void cambiarD(double *,int ,int );
void leerEmpleados (int * ,double  * , int *); 
void leerPlanilla(int *,int ,double *,int *,int *,int *,double *,
                    int *,int *);
void ordenarPlantilla(int *,int *,int *,double *,int *,int );
int buscarCodigo(int ,int *,int );
int buscarTrabajo(int *,int *,int ,int ,int );
void mostrarReporte(int *,int ,int ,int,
                    int *,double *,int *,int *,int ,
                                int *,double *,double *,int );
double calculaSueldoTotal(double *,int );
int calculaDiasTotal(int *,int );
int buscarAnio(int *,int ,int );
void    imprimir(int *,int *,int *,double *,int *,int );



#endif /* FUNCIONESAUX_H */

