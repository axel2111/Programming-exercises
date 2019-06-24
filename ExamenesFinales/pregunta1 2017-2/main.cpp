#include <stdio.h>
#include <string.h>

struct Cliente{
    int dni;
    char nombre [50];
    char direccion[50];
    int dd;
    int mm;
    int aa;
    int telefono;
};

struct Producto{
    int codigo;
    char nombre [50];
    double precioUnitario ;
    int stock;
};

struct ProductoFaltantes{
    int codigo;
    int stock;
};

struct Orden{
    Producto producto;
    int cantidad;
};

struct Fecha{
    int dd;
    int mm;
    int aa;
    int h;
    int m;
    int s;
};

struct Pedido{
    Fecha fecha;
    Cliente cliente;
    Orden ordenes[50];
    int total;
};


void generarDatos();
void generarProdutos();
void generarClientes();
void procesarPedidos(FILE*);
void escribirProdFalt(FILE *, FILE*);
void reducirStock(FILE *, Pedido);

int main(){
    
    FILE *arch =  fopen ("data.txt", "r") ; 
    
    FILE *archProd =  fopen ("archProd.bin", "rb") ; 
    FILE *archProdFalt =  fopen ("ProductosFaltantes.bin", "wb") ; 
    generarDatos();
    escribirProdFalt(archProd, archProdFalt);
    procesarPedidos(arch);

    fclose (arch);
    fclose (archProd);
    fclose (archProdFalt);
    return 0;
}


void escribirProdFalt(FILE * archProd, FILE* archProdFalt){
    struct Producto producto ; 
    struct ProductoFaltantes productoFaltantes ; 
    int numReg ; 
    fseek (archProd , 0 , SEEK_END);
    numReg = ftell (archProd) / sizeof (struct Producto);
    fseek (archProdFalt , 0 , SEEK_SET);
    for (int i = 0 ; i < numReg ; i++){
        fread(&producto  , sizeof(struct Producto) , 1, archProd);
        productoFaltantes.codigo = producto.codigo;
        productoFaltantes.stock = producto.stock;
        fwrite(&productoFaltantes , sizeof (struct ProductoFaltantes) , 1 , archProdFalt);
    }
          
}

void generarDatos(){
    generarProdutos();
    generarClientes();
}


void generarProdutos(){
    Producto prods[3];
    prods[0].codigo =0 ;
    strcpy(prods[0].nombre,"Manzana");
    prods[0].precioUnitario =2.5 ; 
    prods[0].stock = 3 ;

    prods[1].codigo =1 ;
    strcpy(prods[1].nombre,"Naranjas");
    prods[1].precioUnitario =1.5 ; 
    prods[1].stock = 2 ;

    prods[2].codigo =2 ;
    strcpy(prods[2].nombre,"Uvas");
    prods[2].precioUnitario =4.0 ; 
    prods[2].stock = 1;
    // guard en un archivo Productos.bin
    FILE *archBin  = fopen ("productos.bin" , "wb");
    fseek(archBin,0,SEEK_SET);
    for (int i =  0  ; i < 3 ; i++){
        fwrite (&prods[i] , sizeof (struct Producto) , 1, archBin);
    }
    fclose (archBin);
}
void generarClientes(){
    struct Cliente clientes[3] ; 
    clientes [0].dni = 702010;
    strcpy(clientes[0].nombre,"chino");
    strcpy(clientes[0].direccion,"echenique 450");
    clientes[1].dni = 12345;
    strcpy(clientes[1].nombre,"rosa");
    strcpy(clientes[1].direccion,"PUNO");
    clientes[2].dni = 258933;
    strcpy(clientes[2].nombre,"joaquin");
    strcpy(clientes[2].direccion,"Cusco");
    FILE *archBin = fopen ("clientes.bin" , "wb");
    fseek (archBin , 0 , SEEK_SET);
    for (int i =0 ; i < 3 ; i++){
        fwrite (&clientes[i] , sizeof( struct Cliente) ,1 , archBin);
    }
    fclose (archBin); 
}

void procesarPedidos(FILE* arch, FILE* archProdFalt){
    struct Fecha fecha;
    struct Cliente cliente ;
    struct Producto producto ; 
    char c ; 
    while (1){
        fscanf (arch,"%d %d %d %d %d %d %d",&fecha.dd, &fecha.mm , &fecha.aa ,
                                            &fecha.h , &fecha.m , &fecha.s ,
                                            &cliente.dni);
        if (feof(arch))break;
        struct Pedido pedido;
        pedido.fecha = fecha;
        pedido.cliente = cliente;
        int cantidad = 0;
        while(1){ //leer todas las ordenes por pedido
            struct Orden orden;
            fscanf(arch, "%d %d", &orden.producto, &orden.cantidad);
            fscanf(arch , "%c", &c);

            pedido.ordenes[cantidad] = orden;
            cantidad++;
            if (c=='\n')break ;
        }
        pedido.total  = cantidad;
        reducirStock(archProdFalt, pedido);
        imprimirFaltantes(archProdFalt);
    }
}

 
void reducirStock(FILE * archProdFalt, Pedido pedido){

    int numReg;
    int totalOrdenes =  pedido.total;
    fseek (archProdFalt , 0 , SEEK_END);
    numReg = ftell (archProdFalt) / sizeof (struct ProductoFaltantes);
    
    for (int i = 0; i< totalOrdenes; i++){ // por cada orden en pedido actual
        struct Orden orden = pedido.ordenes[i];
        for (int j = 0; j < numReg; j++){ // productos faltantes    
                ProductoFaltantes prodFalt;
                fseek (archProdFalt , sizeof (struct ProductoFaltantes)*(j),SEEK_SET);
                fread(&prodFalt , sizeof (struct ProductoFaltantes),1,archProdFalt);
                if (prodFalt.codigo == orden.producto.codigo){
                    prodFalt.stock -= orden.cantidad;
                    fseek (archProdFalt , sizeof (struct ProductoFaltantes)*(j),SEEK_SET);
                    fwrite(&prodFalt , sizeof (struct ProductoFaltantes),1,archProdFalt);
                    break;
                }

        }

    }

}