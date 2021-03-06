/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cadenas.h"
#include "Persona.h"
#include "FuncionesBin.h"

void crearArhivoBinario(FILE *entrada, FILE *salida) {
    struct Persona persona;

    while (1) {
        leerPersona(entrada, &persona);
        if (feof(entrada))break;
        fwrite(&persona, sizeof (struct Persona), 1, salida);
    }
}

void leerPersona(FILE *arch, struct Persona *persona) {
    char buffer[100];
    char *palabra[50];
    int numPal = 0;
    leerCadena(buffer, 200, arch);
    if (feof(arch))return;
    sacarPalabra(buffer, palabra, &numPal, ",");
    persona->dni = atoi(palabra[0]);
    strcpy(persona->nombre, palabra[1]);
    persona->sueldo = atof(palabra[2]);
    printf(" %8d %-30s %.2lf\n", persona->dni, persona->nombre, persona->sueldo);
}

void mostrarDatos(FILE *archBin) {
    struct Persona per;
    int numReg;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Persona);
    fseek(archBin, 0, SEEK_SET);
    for (int i = 0; i < numReg; i++) {
        fread(&per, sizeof (struct Persona), 1, archBin);
        printf("%8d %-30s %.2lf\n", per.dni, per.nombre, per.sueldo);
    }
}

void modificaRegistro(int registro, FILE *archBin) {
    struct Persona per;
    int numReg;
    double sueldo;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Persona);
    fseek(archBin, 0, SEEK_SET);
    if (registro > numReg || registro == 0) {
        printf("Registro Fuera de rango");
        return;
    }
    fseek(archBin, sizeof (struct Persona)*(registro - 1), SEEK_SET);
    fread(&per, sizeof (struct Persona), 1, archBin);
    printf("%8d %-30s %.2lf", per.dni, per.nombre, per.sueldo);
    printf("\nIngrese nuevo sueldo: "), scanf("%lf", &sueldo);
    per.sueldo = sueldo;
    fseek(archBin, sizeof (struct Persona)*(registro - 1), SEEK_SET);
    fwrite(&per, sizeof (struct Persona), 1, archBin);

}

void aumetarSueldo(FILE *archBin) {
    struct Persona per;
    int numReg;
    fseek(archBin, 0, SEEK_END);
    numReg = ftell(archBin) / sizeof (struct Persona);
    fseek(archBin, 0, SEEK_SET);

    for (int i = 0; i < numReg; i++) {
        fread(&per, sizeof (struct Persona), 1, archBin);
        per.sueldo = per.sueldo * 150 / 100;
        fseek(archBin, sizeof (struct Persona)*i, SEEK_SET);
        fwrite(&per, sizeof (struct Persona), 1, archBin);
        fflush(archBin);
    }
}