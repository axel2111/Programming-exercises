/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 01:06 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

FILE *abrirArchivo (char *nombArch  ,char *modo);
void leerArregloD(double *arr,int *cont,FILE *arch);
void leerArregloI(int *arr,int *cont,FILE *arch);
void eliminarPosicion(double *premios,int numPremios,int *codigo,int numCodigos);
void mostrarReporte(double *premios,int numPremios,int *codigo); 
#endif /* FUNCIONESAUX_H */

