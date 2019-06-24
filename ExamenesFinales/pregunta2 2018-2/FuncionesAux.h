/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAux.h
 * Author: Axel
 *
 * Created on 14 de junio de 2019, 06:04 PM
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H
FILE *abrirArchivo (char *nombre,char *modo);
void leerCadena(char *cadAux,int numCar,FILE *arch);
char *leerCadenaExacta (FILE *arch);
void leerDatosConsulta(int *conMed,int *numConsultas);
void sacarPalabras(char *frase , char **palabras,int *numPal ,char *separador ) ;
void leerDatosMedico(int *codigo,double *tarifa,char **nombre,char **especialidad,int *numMed);
void  mostrarReporte(int *codigo,double *tarifa,char **nombre,char **especialidad,
                    int numMed,int *conMed,int numConsultas);
void ordenarAportes(int *codigo,char **nombre,char **especialidad,double *aporte,int numMed);
void cambiarI(int *arr ,int i, int j);
void cambiarD(double *arr ,int i, int j);
void cambiarC(char **arr ,int i, int j);
void obtenerAportes(int *codigo,int *conMed,double *tarifa,int numMed,int numConsultas,double *aporte);
#endif /* FUNCIONESAUX_H */

