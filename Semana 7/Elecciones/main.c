/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de mayo de 2019, 03:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_CANDIDATOS 100
#define MAX_VOTOS 10000
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int candidatos[MAX_CANDIDATOS] , numCandidatos = 0 ;
    int votos[MAX_VOTOS]; 
    double porcentaje[MAX_CANDIDATOS];
    leerCandidatos (candidatos,&numCandidatos);
    contarVotos (votos,numCandidatos) ; 
    calcularPorcentaje(votos,numCandidatos,porcentaje);
    mostrarResultados(votos, candidatos,numCandidatos,porcentaje) ; 
    return (EXIT_SUCCESS);
}

