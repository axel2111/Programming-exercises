/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicos.h
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 05:48 PM
 */

#ifndef MEDICOS_H
#define MEDICOS_H
#include "Aporte.h"
struct Medicos{
    struct Aporte aporte;
    int codigo ; 
    char nombre[50];
    char especialidad[50];
    double sueldo ;
};

#endif /* MEDICOS_H */

