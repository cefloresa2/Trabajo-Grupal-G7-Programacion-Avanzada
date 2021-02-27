#include <iostream>
#include <fstream>
#include "proveedor.h"
using namespace std;
int main() {
	tProveedor proveedor;
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
		archivo.read( (char *) &proveedor, SIZE);
		mostrar(proveedor);
	
	cout << endl << "Cambiar nombre del proveedor [S/N]? ";
	char c;
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Nombre del proveedor: ";
		cin.sync();
		cin.getline(proveedor.nombre,15);
	}
	
	cout << endl << "Cambiar el telefono [S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Telefono: ";
		cin>>proveedor.telefono;
	}
	
	cout << endl << "Cambiar ruc [S/N]? ";
	cin.sync();
	cin >> c;
	if ((c == 's') || (c == 'S')) {
		cout << "Ruc: ";
		cin >>proveedor.ruc;
	}
	
	
	
	
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.write( (char *) &proveedor, SIZE);
		cout << endl << "Registro actualizado:" << endl;
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &proveedor, SIZE);
		mostrar(proveedor);
	}
	archivo.close();
	return 0;
}




