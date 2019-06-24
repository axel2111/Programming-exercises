/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 12 de mayo de 2019, 04:37 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void obtenerReporte(FILE * , FILE * ,FILE * , FILE *,FILE *);
void mostrarReporte(FILE *,FILE *,FILE *,
                    int ,double ,double );
void comprasCliente(int ,double *, FILE *,FILE *);
double obtenerMonto (int cod,int cant,FILE *);
void imprimirLinea(char ,int );
void cerrarArchivos(FILE * , FILE * ,FILE * , FILE *,FILE *);
#endif 

