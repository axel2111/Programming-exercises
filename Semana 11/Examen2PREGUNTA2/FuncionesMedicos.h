/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesMedicos.h
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 06:01 PM
 */

#ifndef FUNCIONESMEDICOS_H
#define FUNCIONESMEDICOS_H
#include "Medicos.h"
#include "Consultas.h"
void leerMedicos(struct Medicos *medicos,int *numMedicos);
void leerConsultas (struct Consultas *consultas,int *numConsultas);
void obtenerAportes(struct Medicos *medicos,struct Consultas *consultas,int numMedicos,int numConsultas);
void  ordenarAportes(struct Medicos *medicos,int numMedicos);
void cambiarS(struct Medicos *medicos,int i , int j);
#endif /* FUNCIONESMEDICOS_H */

