/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 6 de mayo de 2019, 06:49 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void obtenerReporte(FILE * ,FILE *, FILE *,FILE *,FILE * );
void mostrarGanadores(int ,int ,FILE *,FILE *,FILE *);
double obtenerMontoT(int ,FILE *,FILE *);
void calcularMonto (int ,int   , double * ,FILE *);
void imprimirLinea(char ,int );
void cerrarArch(FILE * ,FILE *, FILE *,FILE *,FILE *);

#endif /* FUNCIONESAUX_H */

