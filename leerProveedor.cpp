#include <iostream>
#include <fstream>
#include "proveedor.h"
using namespace std;
 
int main() {
    tProveedor proveedor;
    fstream archivo;
    archivo.open("bd.dat", ios::in | ios::binary);
    archivo.read((char *) &proveedor, SIZE);
    int cuantos = archivo.gcount();
    while (cuantos == SIZE) {
        mostrar(proveedor); // Función mostrar registro
        archivo.read((char *) &proveedor, SIZE);
        cuantos = archivo.gcount();
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

