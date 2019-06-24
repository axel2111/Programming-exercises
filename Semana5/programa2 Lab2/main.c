/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 23 de abril de 2019, 10:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archTexto, *reporte;
    
    archTexto=fopen("cuentos.txt","r");
    reporte=fopen("reporte.txt","w");
    
    if (archTexto==NULL){
        printf ("Error , el archivo Cuentos.txt no existe ");
        exit (1);
    }
    if (reporte==NULL){
        printf ("Error , el archivo reporte.txt no existe ");
        exit (1);
    }
    char c ;
    int n , codigo, 
        vieneDeParrafo = 0;  // flag
    
    while(1){ // cuento
        n = fscanf (archTexto, "%d\n" , &codigo);
        if (feof(archTexto)) break;
        if (n == 1) {
            printf("Alumno: %04d\t\t\tTITULO:", codigo);
            vieneDeParrafo=0;
/*
            c=fgetc(archTexto);
*/
            if(c=='\n')continue;
        }
        if (!vieneDeParrafo){
            // Lee el titulo
            while(1){
                c=fgetc(archTexto);
                if (c=='\n') {
                    printf("%c",c);
                    break;
                }
                vieneDeParrafo=0;
                if (c  >= 'a' && c <= 'z') printf("%c",c - 32);
                else printf("%c",c);
            }
        }
        
        // Lee el parrafo
        
            while ((c = fgetc(archTexto)) != EOF){
                printf("%c",c);//leo el salto de linea del codigo al titulo
                vieneDeParrafo=1;
                
                // acumulas palabras, maximo, oraciones
                if (c=='\n')break;
            }
        
    }
    
    
     
    fclose(archTexto);
    fclose(reporte);
    return (EXIT_SUCCESS);
}

