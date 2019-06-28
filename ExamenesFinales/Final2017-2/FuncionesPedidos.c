/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "Productos.h"
#include "FuncionesPedidos.h"

void leerCadena(char *cad, int numCar, FILE *arch) {
    fgets(cad, numCar, arch);
    int i = strlen(cad);
    cad[i - 1] = 0;
}

char *leerCadenaExacta(FILE *arch) {
    char cadAux[150], *cad;
    leerCadena(cadAux, 150, arch);
    if (feof(arch))return NULL;
    cad = (char *) malloc(sizeof (char) * (strlen(cadAux) + 1));
    strcpy(cad, cadAux);
    return cad;
}

void sacaPalabra(char *frase, char **palabra, int *numPal, char separador) {
    char cadAux [100], *cad;
    int i = 0, j;
    (*numPal) = 0;
    while (1) {
        while (frase[i] == separador) i++;
        if (frase[i] == 0)break;
        j = 0;
        while (frase[i] != separador && frase[i] != 0) {
            cadAux[j] = frase[i];
            i++;
            j++;
        }
        cadAux[j] = 0;
        cad = (char*) malloc(sizeof (char)*(strlen(cadAux) + 1));
        strcpy(cad, cadAux);
        palabra[*numPal] = cad;
        (*numPal)++;
    }

}

void leerClientes(struct Clientes *clientes, int *numClientes) {
    FILE *arch = fopen("clientes.txt", "r");
    char *frase;
    char *palabra[50];
    (*numClientes) = 0;
    int numPal = 0;
    while (1) {
        frase = leerCadenaExacta(arch);
        if (frase == NULL)break;
        sacaPalabra(frase, palabra, &numPal, ',');
        clientes[*numClientes].dni = atoi(palabra[0]);
        strcpy(clientes[*numClientes].nombre, palabra[1]);
        strcpy(clientes[*numClientes].direccion, palabra[2]);
        clientes[*numClientes].nacimiento.dia = atoi(palabra[3]);
        clientes[*numClientes].nacimiento.mes = atoi(palabra[4]);
        clientes[*numClientes].nacimiento.anio = atoi(palabra[5]);
        clientes[*numClientes].telefono = atoi(palabra[6]);
        (*numClientes)++;
    }
    fclose(arch);
}

void crearArchivoBin(struct Clientes *clientes, int numClientes) {
    FILE *archBin = fopen("clientes.bin", "wb");
    for (int i = 0; i < numClientes; i++) {
        printf("%d %s %s %d\n", clientes[i].dni, clientes[i].nombre, clientes[i].direccion, clientes[i].telefono);
        fwrite(&clientes[i], sizeof (struct Clientes), 1, archBin);
    }
    fclose(archBin);
}

void escribirProductosFaltantes(struct Productos *productos, int *numProd) {
    FILE *arch = fopen("productos.txt", "r");
    FILE *arch2 = fopen("productosFaltantes.txt", "w");
    FILE *archBin = fopen("productosFaltantes.bin", "wb");
    char *frase;
    char *palabra[50];
    (*numProd) = 0;
    int numPal = 0;
    printf("PRODUCTOS FALTANTES .BIN\n");
    while (1) {
        frase = leerCadenaExacta(arch);
        if (frase == NULL)break;
        sacaPalabra(frase, palabra, &numPal, ',');
        productos [*numProd].codigo = atoi(palabra[0]);
        strcpy(productos [*numProd].nombre, palabra[1]);
        productos [*numProd].pu = atof(palabra[2]);
        productos[*numProd].stock = atoi(palabra[3]);
        fprintf(stdout, "%d %s %lf %d\n", productos[*numProd].codigo, productos[*numProd].nombre
                , productos[*numProd].pu, productos[*numProd].stock);
        fwrite(&productos[*numProd], sizeof (struct Productos), 1, archBin);
        (*numProd)++;
    }
    printf("FIN\n");
    fclose(arch2);
    fclose(arch);
    fclose(archBin);
}

void actualizarPedidosFaltantes() {
    FILE *archBin = fopen("productosFaltantes.bin", "rb+");
    FILE *archPed = fopen("pedidos.txt", "r");
    int dia, mes, anio, h, m, s;
    int dni;
    int cod, cant;
    int numReg;
    struct Clientes cliente;
    struct Productos prod;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Productos);
    fseek(archBin, 0, SEEK_SET);
    char c;
    while (1) {
        fscanf(archPed, "%d %d %d %d %d %d %d", &dia, &mes, &anio, &h, &m, &s, &dni);
        if (feof(archPed))break;
        while (1) {
            fscanf(archPed, "%d %d", &cod, &cant);
            c = fgetc(archPed);
            printf("\nPedido: %d %d \n", cod, cant);
            fseek(archBin, 0, SEEK_SET);
            actualizarArchPedidos(numReg, cod, cant, archBin);
            /*
                        for (int i = 0; i < numReg; i++) {
                            fread(&prod, sizeof (struct Productos), 1, archBin);
                            if (prod.codigo == cod) {
                                prod.stock -= cant;
                                fseek(archBin, sizeof (struct Productos)*i, SEEK_SET);
                                fwrite(&prod, sizeof (struct Productos), 1, archBin);

                                break;
                            }
                        }
             */
            if (c == '\n')break;
        }
    }
    fclose(archBin);
    fclose(archPed);
}

void actualizarArchPedidos(int numReg, int cod, int cant, FILE *archBin) {
    struct Productos prod;
    for (int i = 0; i < numReg; i++) {
        fread(&prod, sizeof (struct Productos), 1, archBin);
        if (prod.codigo == cod) {
            prod.stock -= cant;
            fseek(archBin, sizeof (struct Productos)*i, SEEK_SET);
            fwrite(&prod, sizeof (struct Productos), 1, archBin);
            break;
        }
    }
}

void imprimirProductos() {
    FILE *archBin = fopen("productosFaltantes.bin", "rb");
    struct Productos prod;
    int numReg;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Productos);
    fseek(archBin, 0, SEEK_SET);
    printf("ARCHIVO BINARIO\n");
    for (int i = 0; i < numReg; i++) {
        fread(&prod, sizeof (struct Productos), 1, archBin);
        printf("%d %s %.2lf %d\n", prod.codigo, prod.nombre, prod.pu
                , prod.stock);
    }
    fclose(archBin);
}

void reponerStock() {
    FILE *reporte = fopen("reponerStock.txt", "w");
    FILE *archBin = fopen("productosFaltantes.bin", "rb");
    int numReg;
    struct Productos prod;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Productos);
    fseek(archBin, 0, SEEK_SET);
    fprintf(reporte, "         MI TIENDA S.A \n");
    fprintf(reporte, "   Relacion de productos faltantes \n");
    linea('-', 70, reporte);
    for (int i = 0; i < numReg; i++) {
        fread(&prod, sizeof (struct Productos), 1, archBin);
        if (prod.stock < 0) {
            fprintf(reporte, "%7d    %30s\n", prod.codigo, prod.nombre);
        }
    }

}

void linea(char c, int numCar, FILE *arch) {
    for (int i = 0; i < numCar; i++) {
        fprintf(arch, "%c", c);
    }
    fprintf(arch, "\n");
}