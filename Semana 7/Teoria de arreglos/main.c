/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de mayo de 2019, 01:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 100

int main(int argc, char** argv) {
/*
    int a [10]={11,22,33,44,55,66,77,88,99,100};
    int nd = 10 ;
    modificaArreglo(a,nd);
    imprimeArreglo (a,nd); 
*/
/*
    int *p;
    printf ("Usando arreglos:\n");
    for (int i = 0 ; i<10 ;i++){
        printf ("%d)%d\n",i , a[i]);
    }
    p=a;
    
    printf ("Usando punteros:\n") ;
    for (int j = 0 ; j < 10 ; j++){
        printf ("%d) %d\n",j , p[j]);
    }
*/
/*
         int arr [10]={11,22,33,44,55,66,77,88,99,100};
         int *pt1 , *pt2 ; 
         pt1 = arr ;
         printf ("Usando pt1: ");
         for (int i = 0 ; i<10 ;i++){
             printf ("%d ",pt1[i]);
         }
         printf ("\n\n");
         pt2 = pt1 + 1;
         printf ("pt2 = %d" , *pt2);
    
*/
    int arr[MAX] = {0};
    int nd= 10 ; 
    imprimeArreglo(arr , nd);
    return (EXIT_SUCCESS);
}

