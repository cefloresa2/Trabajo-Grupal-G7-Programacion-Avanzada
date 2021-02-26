#include <iostream>
#include <fstream>
#include "factura.h"
//#include "cliente.h"
using namespace std;

int main() {
    tRegistro registro;
    fstream archivo;
    //c++ mostrarDatos() de factura
    archivo.open("basedatosfactura.dat", ios::in | ios::binary);
    archivo.read((char *) &registro, SIZE);
    int cuantos = archivo.gcount();
    while (cuantos == SIZE) {
        mostrar(registro); // Función mostrar registro
        archivo.read((char *) &registro, SIZE);
        cuantos = archivo.gcount();
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

