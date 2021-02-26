#include <iostream>
#include <fstream>
#include "factura.h"
using namespace std;

int main(){
    tRegistro registro;
    fstream archivo;
    archivo.open("basedatosfactura.dat", ios::out | ios::binary);
    bool seguir = true;
    while (seguir) {
    	//c++ leerdatos() de factura
        cout<<"Fecha: "; cin.sync();
		cin>>registro.fecha;

		cout<<"Nombre: "; cin.sync();
		cin.getline(registro.nombre, MAX); // MAX: 80

		cout<<"Producto: "; cin.sync();
		cin>>registro.producto;
		
		cout<<"Cantidad: "; cin.sync();
		cin>>registro.cantidad;
		
		cout<<"Codigo factura: "; cin.sync();
		cin>>registro.codigofac;

		archivo.write((char *) &registro, SIZE);
        cout<<"Otro [S/N]? ";
        char c;
        cin >> c;
        if ((c == 'n') || (c == 'N')) {
            seguir = false;
        }
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

