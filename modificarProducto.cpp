#include <iostream>
#include <fstream>
#include "producto.h"
using namespace std;
int main() {
	tProducto producto;
	fstream archivo;
	archivo.open("bd.dat", ios::in | ios::out | ios::binary);
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE;
	cout << "Numero de registros: " << numReg << endl;
	int num;
	cout << "Registro numero? ";
	cin >> num;
	if ((num > 0) && (num <= numReg)) {
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &producto, SIZE);
		mostrar(producto);
	
	
	cout << endl << "Cambiar nombre [S/N]? ";
	char c;
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Nombre: ";
		cin.sync();
		cin.getline(producto.nombre, 15);
	}
	cout << endl << "Cambiar proveedor [S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Proveedor: ";
		cin.getline(producto.proveedor, 10);
	}
	cout << endl << "Cambiar fecha caducacion [S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "fecha caducacion : ";
		cin.getline(producto.fechacaduca, 10);
	}

	cout << endl << "Cambiar precio_coste[S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Precio_coste: ";
		cin >> producto.preciocoste;
	}
	cout << endl << "Cambiar unidades[S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Unidad: ";
		cin >> producto.unidades;
	}
	
	
	
	
	
	
	
	
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.write( (char *) &producto, SIZE);
		cout << endl << "Registro actualizado:" << endl;
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &producto, SIZE);
		mostrar(producto);
	}
	archivo.close();
	return 0;
}




