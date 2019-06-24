/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Axel
 *
 * Created on 1 de mayo de 2019, 09:46 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirFacturas(FILE*,FILE*,FILE*,FILE*);
void imprimirLineas (char ,int , FILE* );
void buscarDni (FILE*,int , int* , int*);
void imprimirProductos(FILE*,FILE*,FILE*);
double buscarPrecio(int,FILE*);
void cerrarArchivos(FILE*,FILE*,FILE*,FILE*);
#endif /* FUNCIONESAUXILIARES_H */

