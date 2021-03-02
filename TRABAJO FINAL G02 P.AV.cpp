#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <conio.h>

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


class Venta
{
	private:
		string Producto[10];
		float Cantidad;
		string Cantidades[20];
		string Montos[20];
  float Monto;
  int num;
		string fecha[10];
		string Numfactura[10];
		string Nombre[20];
		string ApellidoP[20];
		string ApellidoM[20];
		string Dni[8];
		string Dni2[8];
	public:
		float resultado;
		float a;
		float b;
  void agregarventa();
		void mostrar();
		void mostrar_factura();
		void verificar_dni();

};
int i=0;
int a=0;
int b=0;
int resultado=0;
int suma=0;

 void Venta::agregarventa(){
	char op;
	do{
		system("cls");
	    string nombre[20];
	    cout<<"Nombre del cliente: ";
        cin>>Nombre[i];
		cout<<"Apellido Paterno: ";
		cin>>ApellidoP[i];
		cout<<"Apellido Materno: ";
		cin>>ApellidoM[i];
		cout<<"Ingrese Dni: ";
		cin>>Dni[i];
  cout<<"Ingresar el nombre del producto: ";
		cin>>Producto[i];
		cout<<"\nIngresar la Cantidad: ";
		cin>>Cantidad;
		cout<<"\Ingrese la cantidad: ";
		cin>>Cantidades[i];
  cout<<"\n Ingresar monto: ";
		cin>>Monto;
		cout<<"\n Ingrese el monto:";
		cin>>Montos[i];
  cout<<"\nIngresar fecha: ";
		cin>>fecha[i];
		a = Monto;
		b = Cantidad;
		resultado = a*b;
		suma = suma + resultado;
		i++;
		system("cls");
		cout<<"\n\n¿Desea seguir con otra venta?(s/n): ";
		cin>>op;
	}while (op=='s');
}

void Venta::mostrar(){
	cout<<"-----Mostrar Factura------\n\n";
	int j=0;
	while(j<i){              //es j<i no j<=i corregido  //muestra
		cout<<"\n\n---Venta ["<<j+1<<"] ----\n";
		cout<<"\n Cliente: "<<Nombre[j];
		cout<<" ";
		cout<<ApellidoP[j];
	 	cout<<" ";
		cout<<ApellidoM[j];
		cout<<"\n Dni: "<<Dni[j];
		cout<<"\n Producto: "<<Producto[j];
		a = Monto;
		b = Cantidad;
		cout<<"\n Cantidad: "<<Cantidades[j];
		cout<<"\n Monto: "<<Montos[j];
		cout<<"\n Fecha: "<<fecha[j];
  		resultado = a*b;
		cout<<"\n Total: "<<"S/. "<<suma<<endl;
		j++;
	}

}
class Cliente{
    private:
        char client[3][20];
		int nclients;

		char dni[8];
	public:
        void leerDatos();
        void mostrarDatos();
};
void Cliente :: leerDatos(){
	cout<<"Ingrese numero de clientes: ";
    cin>>nclients;
    for(int i = 0; i < nclients; i++){
        cout<<"Ingrese nombre del cliente #"<<i+1<<" por favor: ";
        fflush(stdin); gets(client[i]);
        cout<<"Ingrese el DNI del cliente: ";
		cin>>dni;
    }
}
void Cliente :: mostrarDatos(){
    char clinete[3]="";
    cout<<left;
    cout<<setw(40);
    for(int i = 0; i < nclients; i++){
        strcat(clinete,client[i]);
        if(i != nclients-1)
            strcat(clinete,", ");
            cout<<dni;
    }
    cout<<clinete;
   cout<<endl;
}
class Proveedor{
	private:
        char nom_prov[20];
        int num_prov;
        char ruc[11];
	public:
        void leerDatos();
        void mostrarDatos();
        char* getName();
};
void Proveedor :: leerDatos(){
	cout<<"Ingrese nombre del proveedor: ";
	fflush(stdin); gets(nom_prov);
    cout<<"Ingrese el numero del proveedor "; cin>>num_prov;
    cout<<"Ingrese el ruc: "; cin>>ruc;
}
void Proveedor :: mostrarDatos(){
    cout<<left;
    cout<<setw(15)<<nom_prov;
    cout<<setw(10)<<num_prov;
    cout<<setw(5)<<ruc;
    cout<<endl;
}
char* Proveedor :: getName(){
}
class Producto{
	private:
	public:
		char nom_prod[15];
		char proveedorr[15];
		char fechacaduc[15];
        int precio;
        int unidades;
        void leerDatos();
        void mostrarDatos();
        char* getName();
}pr[50];
void Producto :: leerDatos(){
	cout<<"Ingrese nombre del producto: ";
	fflush(stdin); gets(nom_prod);
	cout<<"Ingrese nombre del proveedor: ";
	fflush(stdin); gets(proveedorr);
	cout<<"Ingrese la fecha de caducidad: ";
	fflush(stdin); gets(fechacaduc);
	cout<<"Ingrese el precio "; cin>>precio;
    cout<<"Ingrese las unidades: "; cin>>unidades;
}
void Producto :: mostrarDatos(){
    cout<<left;
    cout<<setw(15)<<nom_prod;
    cout<<setw(15)<<proveedorr;
    cout<<setw(15)<<fechacaduc;
    cout<<setw(10)<<precio;
    cout<<setw(10)<<unidades;
    cout<<endl;
}
char* Producto :: getName(){
}
int main(){
    Cliente listaClientes[10];
    Proveedor listaProveedors[10];
    Producto listaProductos[10];
    Venta listaVenta[30];
    int nLib = 0, nRev = 0, nArt = 0, ind = 0,clien = 0, nPro=0, op, n2=1, n;
    char opc, pags[8];
    string prodd;
    do{
        system("CLS");
        cout<<"\n    V2.1 \n";
        cout<<"\n\t Sistema de facturacion La Genovesa: \t"<<endl;
        cout<<"1. AGREGAR CLIENTE:"<<endl;
        cout<<"2. AGREGAR PROVEEDOR: "<<endl;
        cout<<"3. AGREGAR PRODUCTO: "<<endl;
        cout<<"\t -----------Opciones extras----------- \t"<<endl;
        cout<<"4. MOSTRAR LISTA DE CLIENTES: "<<endl;
        cout<<"5. MOSTRAR LISTA DE PROVEEDORES: "<<endl;
        cout<<"6. MOSTRAR LISTA DE PRODUCTOS: "<<endl;
        cout<<"7. AGREGAR VENTA: "<<endl;
        cout<<"8. MOSTRAR FACTURA: "<<endl;
		cout<<"9. MODIFICAR PRODUCTOS: "<<endl;
        cout<<"0. Salir"<<endl<<endl;
        cout<<"Selecciones una opcion por favor, [1 ,2 ,3]: "; cin>>op;
        cout<<endl;
        switch(op){
            case 1:
                listaClientes[nLib].leerDatos();
                nLib = nLib + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
            break;
            case 2:
                listaProveedors[nRev].leerDatos();
                nRev = nRev + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
            break;
            case 3:
            cout<<"Ingrese cuantos productos va a ingresar: ";
    		cin>>n;
    		cout<<"\n"<<endl;
    		for(int i=1; i<=n; i++)
			{
				fflush(stdin);   
   				cout<<"\nIngresa el nombre del producto: ";
   				cin.getline(pr[i].nom_prod,20);
   				cout<<"\nIngresa el nombre del proveedor: ";
   				cin.getline(pr[i].proveedorr,20);
   				cout<<"\nIngresa la fecha de caducacion: ";
   				cin.getline(pr[i].fechacaduc,20);
   				cout<<"\nIngresa el precio: ";
   				cin>>pr[i].precio;
   				cout<<"\nIngresa la cantidad: ";
   				cin>>pr[i].unidades;
   				cout<<"\n\n"<<endl;
   				cout<<"--------------------------------------"<<endl;
   				cout<<"\n"<<endl;
   				system("CLS");
			}
            break;
            case 4:
                cout<<left;
                cout<<setw(1)<<"# ";
                cout<<setw(40)<<"Dni";
                cout<<setw(10)<<"Cliente:";
                cout<<endl;
                for(int i = 0; i < nLib; i++){
                    cout<<left<<setw(3)<<i+1;
                    listaClientes[i].mostrarDatos();
                }
            break;
            case 5:
                cout<<left;
                cout<<setw(3)<<"#";
                cout<<setw(15)<<"Proveedor";
                cout<<setw(10)<<"numero";
                cout<<setw(5)<<"ruc";
                cout<<endl;
                for(int i = 0; i < nRev; i++){
                    cout<<left<<setw(3)<<i+1;
                    listaProveedors[i].mostrarDatos();
                }
            break;
            case 6:
				cout<<"\n"<<endl;
					cout<<"  nombre  proveedor   fechacaduc    precio   unidades  "<<endl;
					cout<<"\n"<<endl;
					    
					for(int i=1; i<=n; i++)
			    	{
					fflush(stdin);   
					cout<<"  "<<pr[i].nom_prod;
   					cout<<"       "<<pr[i].proveedorr;
   					cout<<"       "<<pr[i].fechacaduc;
				    cout<<"      "<<pr[i].precio;
				     cout<<"      "<<pr[i].unidades;
				     cout<<"\n"<<endl;
					}
					system("pause");
					system("CLS");
            break;
            case 7:
                listaVenta[clien].agregarventa();
                nLib = nLib + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
            break;
          case 8:
                listaVenta[clien].mostrar();
                nLib = nLib + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
          break;
 		  case 9:
		cout<<"-----Modificar producto------\n\n";
				    cout<<"Ingrese el nombre del producto: ";
				    cin>>prodd;
				    cout<<"\n"<<endl;
				    for(int i=0; i<=n2; i++)
					{
						if(pr[i].nom_prod == prodd)
	 					{
	 						fflush(stdin);   
   							cout<<"\nIngresa el nuevo nombre del produto: ";
   							cin.getline(pr[i].nom_prod,15);
    						cout<<"\nIngrese la nueva cantidad: ";
							cin>>pr[i].unidades;
   						    cout<<"\nIngrese el nuevo precio: ";
							cin>>pr[i].precio;
   			 				cout<<"\n\n"<<endl;
   							cout<<"--------------------------------------"<<endl;
   							cout<<"\n"<<endl;
   							system("CLS");
				  			}
						}
           break;
            case 0:
            cout<<"Gracias Vuelva pronto!"<<endl;
            break;
            default:
                cout<<"Error , digite una opcion valida por favor "<<endl;
            break;
        }
        cout<<endl;
        system("PAUSE");
    }while(op != 0);
    system("CLS");
    return 0;
}
