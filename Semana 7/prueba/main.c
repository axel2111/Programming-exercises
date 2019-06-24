/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 13 de mayo de 2019, 03:09 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int n  , m;
    for (int i = 0 ; i < 4 ; i++){
        
    scanf ("%d:%d" , &n , &m);
    printf ("\n%d : %d\n" , n , m);
    }
    return (EXIT_SUCCESS);
}

