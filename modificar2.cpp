#include <iostream>
#include <fstream>
#include "factura.h"
using namespace std;
int main() {
	tRegistro registro;
	fstream archivo;
	//c++ modificarDatos() de factura
	archivo.open("basedatosfactura.dat", ios::in | ios::out | ios::binary);
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE;
	cout<<"Numero de registros: " <<numReg<<endl;
	int num;
	cout<<"Registro numero? ";
	cin>>num;
	if((num > 0) && (num <= numReg)){
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &registro, SIZE);
		mostrar(registro);
	//_______________________________________________
	cout<<endl<< "Cambiar fecha [S/N]? ";
	char c;
	cin.sync();
	cin>>c;
	if ((c == 's') || (c == 'S')) {
		cout<<"fecha: ";
		cin>>registro.fecha;
	}
	//_______________________________________________
	cout<<endl<<"Cambiar nombre [S/N]? ";
	char cs;
	cin.sync();
	cin>>c;
	if((c == 's') || (c == 'S')){
		cout<<"Nombre: ";
		cin.sync();
		cin.getline(registro.nombre, 80);
	}
	//_______________________________________________
	cout << endl << "Cambiar producto [S/N]? ";
	cin.sync();
	cin>>c;
	if ((c == 's') || (c == 'S')) {
		cout<<"Producto: ";
		cin>>registro.producto;
	}
	//_______________________________________________
	cout<<endl<<"Cambiar cantidad [S/N]? ";
	cin.sync();
	cin>>c;
	if ((c == 's') || (c == 'S')) {
		cout<<"Cantidad: ";
		cin>>registro.cantidad;
	}
	//_______________________________________________
	cout<<endl<<"Cambiar codigo de factura [S/N]? ";
	cin.sync();
	cin>>c;
	if ((c == 's') || (c == 'S')) {
		cout<<"Codigo Factura: ";
		cin>>registro.codigofac;
	}
	//_______________________________________________
	
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.write( (char *) &registro, SIZE);
		cout << endl << "Registro actualizado:" << endl;
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read( (char *) &registro, SIZE);
		mostrar(registro);
	}
	archivo.close();
	return 0;
}




