/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facturas.h
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 12:57 PM
 */

#ifndef FACTURAS_H
#define FACTURAS_H
#include "Fecha.h"
#include "Persona.h"
#include "Productos.h"
struct Facturas {
    struct Fecha fecha ; 
    struct Persona persona ;
    struct Productos *compras;
    double total ;
};
#endif /* FACTURAS_H */

