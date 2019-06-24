#include <stdio.h>
#include <string.h>
struct Cliente{
    int dni;
    char nombre[];
    
    //char nombre [50];
    //char direccion[50];
    //int dd;
    //int mm;
    //int aa;
    //int telefonoñ
};

struct Productos{
    int codigo;
    char nombre [50];
    double precioUnitario ;
    int stock;
};



int main(){
    FILE *archBin = fopen ("datos.bin" , "wb");
    struct Cliente cliente[2];
    cliente[0].dni = 0;
    strcpy(cliente[0].nombre,"abc");
    cliente[1].dni = 2147483647;
    strcpy(cliente[1].nombre,"xyzw");
    fwrite(&cliente,sizeof(Cliente),-1,archBin);
    fclose (archBin);
    printf("size cliente: %d\n", sizeof(Cliente));

    
    
    FILE *archBin2 = fopen ("datos.bin" , "rb");
    /*
    fwrite(&cliente,sizeof(Cliente),3,archBin);
    fclose (archBin);
    int xx = 5;
    printf("size float: %d\n", sizeof(float));

    
    FILE *archBin2 = fopen ("datos.bin" , "rb");

    int numReg = ftell(archBin2);
    printf("numreg: %d\n", numReg);
    
    struct Cliente cc;
    
    for (int i = 0; i < 3 ; i++){
        fseek(archBin2,sizeof(struct Cliente) * i ,SEEK_SET);
        fread (&cc , sizeof(struct Cliente) ,1 , archBin2);
        printf("cliente dni: %d\n", cc.dni);
        printf("cliente altura: %f\n", cc.altura);
    }
    */
    return 0;
}
