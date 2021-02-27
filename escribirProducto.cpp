#include <iostream>
#include <fstream>
#include "producto.h"
using namespace std;
 
int main(){
    tProducto producto;
    fstream archivo;
    archivo.open("bd.dat", ios::out | ios::binary);
    bool seguir = true;
    while (seguir) {
    	
    	
    	cout <<"\nIngresa el nombre del producto: ";
        cin.sync();
       	cin.getline(producto.nombre,15);      
        cout <<"\nIngresa el nombre del proveedor de este producto: ";
        cin.sync();
        cin.getline(producto.proveedor,10);	
        cout << "\nIngresa la fecha de caducidad(//): ";
        cin.sync();
        cin.getline(producto.fechacaduca,10);        		      			
		cout<<"\nIngrese la cantidad de unidades: ";
		cin.sync();
		cin>>producto.unidades;				
		cout<<"\nIngresa su precio costo en soles: ";
		cin.sync();
		cin>>producto.preciocoste;				
        archivo.write((char *) &producto, SIZE);
        cout << "Otro [S/N]? ";
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

