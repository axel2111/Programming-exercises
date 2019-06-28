/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Axel
 *
 * Created on 27 de junio de 2019, 10:56 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"
#include "Productos.h"
#include "FuncionesPedidos.h"

/*
 *
 */
int main(int argc, char** argv) {
    struct Clientes clientes[50];
    struct Productos productos[50];
    int numClientes = 0;
    int numProd = 0;

    leerClientes(clientes, &numClientes);
    crearArchivoBin(clientes, numClientes);
    escribirProductosFaltantes(productos, &numProd);
    actualizarPedidosFaltantes();
    imprimirProductos();
    reponerStock();
    return (EXIT_SUCCESS);
}

