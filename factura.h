#include <iostream>
using namespace std;

const int MAX = 10;
struct tRegistro{
    char fecha[10]; //04/03/2021
    char nombre[20];
	char producto[20]; //arroz
	int cantidad;
	int codigofac;
};
int SIZE = sizeof(tRegistro);

void mostrar(tRegistro &reg){
	//se mostrara en leer2
    cout<<"Fecha: "<<reg.fecha<<endl;
    cout<<"Cliente: "<<reg.nombre<<endl;
    cout<<"Producto: "<<reg.producto<<endl;
    cout<<"Cantidad: "<<reg.cantidad<<endl;
    cout<<"Codigo factura: "<<reg.codigofac<<endl;
    
}

