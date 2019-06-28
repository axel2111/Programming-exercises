/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   FuncionesPedidos.h
 * Author: Axel
 *
 * Created on 27 de junio de 2019, 11:32 AM
 */

#ifndef FUNCIONESPEDIDOS_H
#define FUNCIONESPEDIDOS_H
#include "Clientes.h"
#include"Productos.h"
void leerCadena(char *cad, int numCar, FILE *arch);
char *leerCadenaExacta(FILE *arch);
void sacaPalabra(char *frase, char **palabra, int *numPal, char separador);
void leerClientes(struct Clientes *clientes, int *numClientes);
void escribirProductosFaltantes(struct Productos *productos, int *numProd);
void crearArchivoBin(struct Clientes *clientes, int numClientes);
void actualizarPedidosFaltantes();
void imprimirProductos();
void reponerStock();
void linea(char c, int numCar, FILE *arch);
void actualizarArchPedidos(int numReg, int cod, int cant, FILE *archBin);
#endif /* FUNCIONESPEDIDOS_H */

