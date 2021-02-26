#include <iostream>
#include <fstream>
#include "cliente.h"
using namespace std;

int main(){
    tRegistro registro;
    fstream archivo;
    archivo.open("basedatoscliente.dat", ios::out | ios::binary);
    bool seguir = true;
    while (seguir) {
    	//leerdatos() de cliente
        cout<<"Dni: "; cin.sync();
		cin>>registro.dni;

		cout<<"Nombre: "; cin.sync();
		cin.getline(registro.nombre, 30); // MAX: 80

		cout<<"Apellido Paterno: "; cin.sync();
		cin.getline(registro.apellido, 30); // MAX: 80
		
		cout<<"Apellido Materno: "; cin.sync();
		cin.getline(registro.apellido2, 30); // MAX: 80

		cout<<"Telefono: "; cin.sync();
		cin>>registro.telefono;
		
		cout<<"Correo: "; cin.sync();
		cin.getline(registro.correo, 30); // MAX: 80

		archivo.write((char *) &registro, SIZE);
        cout<<"Otro [S/N]? ";
        char c;
        cin>>c;
        if ((c == 'n') || (c == 'N')) {
            seguir = false;
        }
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

