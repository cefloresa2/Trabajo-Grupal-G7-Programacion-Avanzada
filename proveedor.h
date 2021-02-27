#include <iostream>
using namespace std;
 

struct tProveedor{
    char nombre[15];
    int telefono;
    int ruc;
};
int SIZE = sizeof(tProveedor);
void mostrar(tProveedor &prov){
    cout<<"Nombre: "<<prov.nombre<<endl;
    cout<<"ruc: "<<prov.ruc<<endl;
}

