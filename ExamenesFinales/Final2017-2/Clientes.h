/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Clientes.h
 * Author: Axel
 *
 * Created on 27 de junio de 2019, 11:20 AM
 */

#ifndef CLIENTES_H
#define CLIENTES_H
#include "Fecha.h"

struct Clientes {
    int dni;
    char nombre[50];
    char direccion[50];
    struct Fecha nacimiento;
    int telefono;
};
#endif /* CLIENTES_H */

