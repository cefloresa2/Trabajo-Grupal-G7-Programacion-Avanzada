#include <iostream>
#include <fstream>
#include "alumno.h"
using namespace std;
 
int main() {
    tRegistro registro;
    fstream archivo;
    archivo.open("bd.dat", ios::in | ios::binary);
    archivo.read((char *) &registro, SIZE);
    int cuantos = archivo.gcount();
    while (cuantos == SIZE) {
        mostrar(registro); // Funci�n mostrar registro
        archivo.read((char *) &registro, SIZE);
        cuantos = archivo.gcount();
        cout<<"\n";
    }
    archivo.close();
    return 0;
}

