/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.h
 * Author: Axel
 *
 * Created on 20 de junio de 2019, 10:40 AM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Cursos.h"
#include "Persona.h"
struct Estudiante{
    struct Cursos *curso ;
    struct Persona persona;
    int codigo  ; 
    int numCursos;
    double creditosTotales;
};
#endif /* ESTUDIANTE_H */

