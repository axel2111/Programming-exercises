/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LeerFunciones.h
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 02:28 PM
 */

#ifndef LEERFUNCIONES_H
#define LEERFUNCIONES_H
#include "Facturas.h"
void leerFacturas(struct Facturas *facturas, int *numFacturas );
void leerFechas (struct Facturas *factura,int *numFacturas ,char *fecha);
void  ordenarDatos(struct Facturas *facturas,int numFacturas);
void cambiarS(struct Facturas *facturas,int i,int j);
#endif /* LEERFUNCIONES_H */

