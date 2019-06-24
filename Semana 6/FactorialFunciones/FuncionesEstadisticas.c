/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

int factorial(int num){
    int fact=1 ;
    for (int n=num ; n>0 ; n--){
        fact*=n;
    }
    return fact ; 
    
}