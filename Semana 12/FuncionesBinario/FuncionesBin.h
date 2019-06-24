/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesBin.h
 * Author: Axel
 *
 * Created on 23 de junio de 2019, 03:08 PM
 */

#ifndef FUNCIONESBIN_H
#define FUNCIONESBIN_H
#include "Cadenas.h"
#include "Persona.h"
void crearArhivoBinario(FILE *entrada, FILE *salida);
void leerPersona (FILE *arch , struct Persona *persona );
void mostrarDatos(FILE *archBin);
void aumetarSueldo (FILE *archBin) ; 
    

#endif /* FUNCIONESBIN_H */

