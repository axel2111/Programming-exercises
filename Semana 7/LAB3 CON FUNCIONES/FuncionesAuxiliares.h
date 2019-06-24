/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Axel
 *
 * Created on 9 de mayo de 2019, 11:45 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void obtenerReporte (FILE *, FILE *, FILE * ,FILE * ,FILE *, int ,int);
void mostrarDoctor(int, double,FILE *,FILE *,FILE *);
void consultasEspecialidad(int * ,int   ,double , FILE *,FILE *);
void imprimeLinea (char  , int) ; 
void cerrarArchivos (FILE *, FILE *, FILE * ,FILE * ,FILE *);
#endif /* FUNCIONESAUXILIARES_H */
