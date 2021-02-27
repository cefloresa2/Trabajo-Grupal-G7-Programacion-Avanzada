#include <iostream>
#include <fstream>
#include "producto.h"
using namespace std;
 
int main() {
    tProducto producto;
    fstream archivo;
    archivo.open("bd.dat", ios::in | ios::binary);
    archivo.read((char *) &producto, SIZE);
    int cuantos = archivo.gcount();
    while (cuantos == SIZE) {
        mostrar(producto); // Función mostrar registro
        archivo.read((char *) &producto, SIZE);
        cuantos = archivo.gcount();
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

