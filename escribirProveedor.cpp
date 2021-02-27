#include <iostream>
#include <fstream>
#include "proveedor.h"
using namespace std;
 
int main(){
    tProveedor proveedor;
    fstream archivo;
    archivo.open("bd.dat", ios::out | ios::binary);
    bool seguir = true;
    while (seguir) {
    	
    	
    	cout <<"\nIngresa el nombre del proveedor ";
        cin.sync();
       	cin.getline(proveedor.nombre,15);    
		     		      			

		cout<<"\nIngresa el telefono ";
		cin.sync();
		cin>>proveedor.telefono;			
		
				
		cout<<"\nIngresa el ruc: ";
		cin.sync();
		cin >>proveedor.ruc;		
		
		
		
		
		
		
		
        archivo.write((char *) &proveedor, SIZE);
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
