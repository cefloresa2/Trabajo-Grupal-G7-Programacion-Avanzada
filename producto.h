#include <iostream>
using namespace std;
 

struct tProducto{
    char nombre[15];
    char proveedor[10];
    char fechacaduca[10];
    float preciocoste;
    int unidades;
};
int SIZE = sizeof(tProducto);
void mostrar(tProducto &pro){
    cout<<"Nombre: "<<pro.nombre<<endl;
    cout<<"Cantidad: "<<pro.unidades<<endl;
}

