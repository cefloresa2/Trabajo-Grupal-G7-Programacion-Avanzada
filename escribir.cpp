#include <iostream>
#include <fstream>
#include "alumno.h"
using namespace std;
 
int main(){
    tRegistro registro;
    fstream archivo;
    archivo.open("bd.dat", ios::out | ios::binary);
    bool seguir = true;
    while (seguir) {
        cout << "Codigo: ";
        cin.sync();
        cin >> registro.codigo;
        cout << "Nombre: ";
        cin.sync();
        cin.getline(registro.nombre, MAX); // MAX: 80
        cout << "Promedio: ";
        cin.sync();
        cin >> registro.promedio;
        archivo.write((char *) &registro, SIZE);
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

