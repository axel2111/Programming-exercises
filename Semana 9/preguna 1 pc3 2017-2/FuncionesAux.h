/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 27 de mayo de 2019, 02:33 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void leerDatos (int *,int *,int *,int *,int *,int *);
void imprimirDatos(int *,int *,int *,int *,int );
void ordenarCumpleanos(int *,int *,int *,int *,int *,int );
void cambiar(int *,int ,int );
int validarFecha(int ,int ,int );
void generarReporte(int *,int *,int *,int *,int *,int *,
                                            int ,int ,int ,int );
int calcularDias(int *,int *,int *,int ,int ,int ,int );
int calcularEdad(int *,int *,int *,int ,int ,int ,int);
int aniobisiesto(int );
#endif /* FUNCIONESAUX_H */

