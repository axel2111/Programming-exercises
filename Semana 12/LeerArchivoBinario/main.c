/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 20 de junio de 2019, 08:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archBin = fopen ("datos.bin" , "rb+");
    
    int numReg , num ;
    int pos ; 
    fseek(archBin,0,SEEK_END);
    numReg = ftell(archBin)/sizeof(int);
    fseek(archBin,0,SEEK_SET);
    for (int i = 0 ; i < numReg ; i++){
        fread (&num , sizeof(int) ,1 , archBin);
        printf ("%2d) %9d\n" , i+1,num );
    }
    int x , nuevo;
    char op;
    while (1){
        printf ("Ingrese la posicion (0 PARA SALIR): "),scanf ("%d",&pos); 
        getchar();
       
        
        if (pos == 0 )break;
        if (pos>numReg){
            printf ("error , fuera del rango de valores \n");
            continue;
        }
        fseek(archBin,sizeof(int)*(pos-1),SEEK_SET);
        fread(&x,sizeof(int),1,archBin);
        printf ("%8d\n" , x);
        fseek(archBin,0,SEEK_END);
        printf ("Desea modificarlo? (s/n): "),scanf ("%c" ,&op );
        if (op=='s'){
            printf ("Ingrese el nuevo valor: "),scanf ("%d",&nuevo);
            fseek(archBin,sizeof(int)*(pos-1),SEEK_SET);
            fwrite(&nuevo,sizeof(int),1,archBin);
            fseek(archBin,0,SEEK_SET);
            printf ("\n\n");
            for (int i = 0 ; i <numReg ; i++){
                fread(&num,sizeof(int),1,archBin);
                printf ("%d) %7d\n" , i+1 , num);
            }
        }

    }
    fclose(archBin);
    return (EXIT_SUCCESS);
}

