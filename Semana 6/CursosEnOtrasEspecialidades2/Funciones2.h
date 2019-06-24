/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones2.h
 * Author: Axel
 *
 * Created on 5 de mayo de 2019, 11:42 AM
 */

#ifndef FUNCIONES2_H
#define FUNCIONES2_H


void fxPrueba(FILE*,FILE*,FILE*,FILE*,FILE*);
void buscarNotaCurso(int ,int ,double*,int*,FILE* );
void cursosLlevadosEnOtraEspecialidad(int ,int,int*,double*,double*,FILE*,FILE*);
void imprimeLinea(char,int , FILE* );
void mostrarReporte(int,int ,FILE*,FILE*,FILE*,FILE*);
void obtenerReporte(FILE*,FILE*,FILE*,FILE*,FILE*);
void cerrarArchivos(FILE*,FILE*,FILE*,FILE*,FILE*);
#endif /* FUNCIONES2_H */

