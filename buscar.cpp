#include <iostream>
#include <fstream>
#include "factura.h"
using namespace std;
int main() {
	tRegistro registro;
	fstream archivo;
	archivo.open("basedatosfactura.dat", ios::in | ios::out | ios::binary);
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE;
	cout << "Numero de registros: " << numReg << endl;
	int num;
	cout << "Registro numero? ";
	cin >> num;
	if ((num > 0) && (num <= numReg)) {
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &registro, SIZE);
		mostrar(registro);
	}
	archivo.close();
	return 0;
}

