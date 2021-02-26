#include <iostream>
using namespace std;
 
const int MAX = 10;
struct tRegistro{
    int codigo;
    char nombre[MAX];
    float promedio;
};
int SIZE = sizeof(tRegistro);
 
void mostrar(tRegistro &reg){
    cout<<"Codigo: "<<reg.codigo<<endl;
    cout<<"Nombre: "<<reg.nombre<<endl;
    cout<<"Promedio: "<<reg.promedio<<endl;
}

