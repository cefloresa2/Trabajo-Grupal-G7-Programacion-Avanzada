#include <iostream>
using namespace std;

//const int MAX = 10;
struct tRegistro{
    int dni;
    char nombre[30];
    int telefono;
    char correo[30];
    char apellido[30];
    char apellido2[30];
};
int SIZE = sizeof(tRegistro);
 
void mostrar(tRegistro &reg){
	//se mostrara en leer
    cout<<"Dni: "<<reg.dni<<endl;
    cout<<"Nombre: "<<reg.nombre<<" "<<reg.apellido<<" "<<reg.apellido2<<endl;
    cout<<"Telefono: "<<reg.telefono<<endl;
    cout<<"Correo: "<<reg.correo<<endl;
}

