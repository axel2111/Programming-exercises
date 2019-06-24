/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 23 de abril de 2019, 12:45 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n,d, contPalabras, contOraciones;
    char c;
    FILE *f;
    
    n = fscanf(f,"%d", &d);
    while (1){ //alumno
       
        if (n == 1){
            n = 0;
            while (1){ // titulo
                
                c = fgetchar(f);
                if (feof(f))break;
                if (c == '\n')break
                c = mayuscula(c);
                printf(c);
            }
            while (1){ // texto
                c = fgetchar(f);
                if (feof(f))break;
                if (c == '\n') {
                    n = fscanf(f,"%d", &d);
                    if (feof(f))break;
                    if (n == 1)break;
                    else{
                        putchar(10);
                        putchar(10);
                        continue;
                    }
                }
                
                // contar palabras
                if (c == ' '){

                }

                // cuenta oracion
                if (c == '.'){

                }
            }
            // imprimir tus contadores y calcular promedios
        }
        if (feof(f))break;
    }
        
    }
    return (EXIT_SUCCESS);
}

