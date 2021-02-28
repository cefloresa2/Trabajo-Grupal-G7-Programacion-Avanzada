#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <windows.h>                                                 //mejorado
#include <conio.h>




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
		string fecha[10];      //01/02/2020
		string Numfactura[10];
		//
		string Nombre[20];    //cliente
		string ApellidoP[20];      //cliente
		string ApellidoM[20];        //cliente
		string Dni[8];
		string Dni2[8];
		//float resultado;
		
  //
	public:
		float resultado;
		float a;
		float b;
  void agregarventa();
		void mostrar();
		//
		void mostrar_factura();
		void verificar_dni();
		//

};
int i=0;
int a=0;
int b=0;
int resultado=0;
int suma=0;





 void Venta::agregarventa(){                                    //crea venta
	char op;
	do{                        //lee
		system("cls");
        //c++
	    string nombre[20];
	    cout<<"Nombre del cliente: ";
        cin>>Nombre[i];
		cout<<"Apellido Paterno: ";
		cin>>ApellidoP[i];
		cout<<"Apellido Materno: ";
		cin>>ApellidoM[i];
		cout<<"Ingrese Dni: ";
		cin>>Dni[i];
		//c++
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

		//cout<<"\nIngresar numero de factura: ";
		//cin>>Numfactura[i];
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
	//	cout<<"\nNombre factura: "<<Numfact ura[j];
		j++;
	}

}



		  
				  
				  
				  			//______________________________________________________ Cliente
class Cliente{
    private:
        char client[3][20];
		int nclients;
	
		char dni[8];
	public:
        void leerDatos();
        void mostrarDatos();
};
  			 											 		//implementndo leerDatos()
void Cliente :: leerDatos(){
     		 																   //Persona :: registrar();
		
	cout<<"Ingrese numero de clientes: ";
    cin>>nclients;
    for(int i = 0; i < nclients; i++){
        cout<<"Ingrese nombre del cliente #"<<i+1<<" por favor: ";
        fflush(stdin); gets(client[i]);
        cout<<"Ingrese el DNI del cliente: ";
		cin>>dni;
       
        
    }
 

}
 	 			 	   	  	  	  		   //implementando mostrarDatos(); cambiar el ; por llave {
void Cliente :: mostrarDatos(){
    char clinete[3]="";
    cout<<left;
    //--cout<<setw(20)<<nombre;
    //--cout<<setw(10)<<fecha;
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
//______________________________________________________
class Articulo; //producto clase
//______________________________________________________DFD Proveedor
class Proveedor{

	private:
        char nom_prov[20];
        
        int num_prov;
        char ruc[11];

	public:
        void leerDatos();
        void mostrarDatos();
        char* getName();

        void agregarArticulo(Articulo*);
        void mostrarArticulos();
};

void Proveedor :: leerDatos(){
    //Persona :: registrar();
//	cout<<"nombre_proveedor :";
//	cin>>nombre_proveedor;
	cout<<"Ingrese nombre del proveedor: ";
	fflush(stdin); gets(nom_prov);
    cout<<"Ingrese el numero del proveedor "; cin>>num_prov;
    cout<<"Ingrese el ruc: "; cin>>ruc;
}

void Proveedor :: mostrarDatos(){
    cout<<left;
    //cout<<setw(20)<<nombre;
    //cout<<setw(10)<<fecha;
    cout<<setw(15)<<nom_prov;
    cout<<setw(5)<<num_prov;
    cout<<setw(5)<<ruc;
    cout<<endl;
    //prec_io = can_t*dia_mes;
}

char* Proveedor :: getName(){
   // return nombre;
}

void Proveedor :: agregarArticulo(Articulo *a){
    
    num_prov = num_prov + 1;
}
//______________________________________________________ dfd persona
class Articulo{
    private:
        char nom_produ[1][20];
        int nAutores;
        char cant_produt[30];
        char fecha_caduca[30];
        int precio;
        int unidades;
        
        
        Proveedor *producto = NULL;
        char pag[8];
    public:
        void leerDatos();
        void mostrarDatos();
        void asignarRevista(Proveedor*, char[]);
};

void Articulo :: leerDatos(){
    //Persona :: registrar();
    char op;
    cout<<"Cantidad de producto (1): ";cin>>nAutores;
    for(int i = 1; i<nAutores; i++){
        cout<<"Ingrese nombre de producto #"<<i+1<<" : ";
        fflush(stdin); gets(nom_produ[i]);
        
    }
    
}

void Articulo :: asignarRevista(Proveedor *r, char p[]){
    producto = r;
    strcpy(pag,p);
}

void Articulo :: mostrarDatos(){
    char autores[3]="";
    cout<<left;
    //cout<<setw(20)<<nombre;
    //cout<<setw(10)<<fecha;
    cout<<setw(40);
    for(int i = 0; i < nAutores; i++){
        strcat(autores,nom_produ[i]);
        if(i != nAutores-1)
             
            strcat(autores,", ");
            
    }
    cout<<autores;
    cout<<setw(15)<<cant_produt;
    //cout<<setw(25);
    if(producto != NULL){
        cout<<producto -> getName()<<" "<<pag;
    } else{
        cout<<"<no asignado>";
    }
    cout<<endl;
}
//______________________________________________________ dfd proveedor
void Proveedor :: mostrarArticulos(){
    if(num_prov != 0){
        for(int i = 0; i < num_prov; i++){
       //     articulos[i] -> mostrarDatos();
        }
    }
    else {
         cout<<"No hay productos registrados";
    }
}
//______________________________________________________ int main (){
int main(){
    Cliente listaClientes[10];
    Proveedor listaRevistas[10];
    Articulo listaArticulos[30];
    Venta listaVenta[30];
    
    
    int nLib = 0, nRev = 0, nArt = 0, ind = 0,clien = 0, op;
    char opc, pags[8];

    do{
        system("CLS");    //borrar datos
        cout<<"\n    V1.3 \n"; //_________________________________________________version
        cout<<"\n\t Sistema de facturacion La Genovesa: \t"<<endl; //titulo
        cout<<"1. AGREGAR CLIENTE:"<<endl;
        cout<<"2. AGREGAR PROVEEDOR: "<<endl;
        cout<<"3. AGREGAR PRODUCTO: "<<endl;
        
        cout<<"\t -----------Opciones extras----------- \t"<<endl;
        cout<<"4. MOSTRAR LISTA DE CLIENTES: "<<endl;
        cout<<"5. MOSTRAR LISTA DE PROVEEDORES: "<<endl;
        cout<<"6. MOSTRAR LISTA DE PRODUCTOS: "<<endl;
        
        
        cout<<"7. AGREGAR VENTA: "<<endl;
        cout<<"8. MOSTRAR FACTURA: "<<endl;
        
        
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
                listaRevistas[nRev].leerDatos();
                nRev = nRev + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
            break;
            case 3:
                listaArticulos[nArt].leerDatos();
                cout<<"Desea ver productos? (S/N): "; cin>>opc;
                if(opc == 'S' || opc == 's'){
                    cout<<endl;
                    cout<<left;
                    cout<<setw(3)<<"#";
                    cout<<setw(20)<<"Atendido por:";
                    cout<<setw(10)<<"Dia/Mes: ";
                    cout<<setw(15)<<"Proveedor: ";
                    cout<<setw(5)<<"D/M.";
                    cout<<setw(5)<<"Cant.";
                    cout<<setw(5)<<"S/.";
                    cout<<endl;
                    for(int i = 0; i < nRev; i++){
                        cout<<left<<setw(3)<<i+1;
                        listaRevistas[i].mostrarDatos();
                    }
                    cout<<endl;
                    cout<<"Ingrese numero (#) de proveedor: "; cin>>ind;
                    cout<<"Ingrese precio del producto: "; cin>>pags;
                    listaArticulos[nArt].asignarRevista(&listaRevistas[ind-1], pags);
                    listaRevistas[ind-1].agregarArticulo(&listaArticulos[nArt]);
                }
                nArt = nArt + 1;
                cout<<endl<<"Registro exitoso!"<<endl;
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

                cout<<setw(5)<<"numero";
                cout<<setw(5)<<"ruc";
 
                cout<<endl;
                for(int i = 0; i < nRev; i++){
                    cout<<left<<setw(3)<<i+1;
                    listaRevistas[i].mostrarDatos();
                }
                cout<<endl;
                cout<<"Desea visualizar lista productos de un proveedor? (S/N): "; cin>>opc;
                if(opc == 'S' || opc == 's'){
                    cout<<endl;
                    cout<<"Ingrese numero (#) de proveedor: "; cin>>ind;
                    cout<<endl;
                    cout<<setw(20)<<"Recibido por";
                    cout<<setw(10)<<"Dia/Mes";
                    cout<<setw(40)<<"Producto";
                    cout<<setw(10)<<"Cantidad";
                    cout<<setw(10)<<"Proveedor";
                    cout<<setw(15)<<"S/.";
                    cout<<endl;
                    listaRevistas[ind-1].mostrarArticulos();
                }
            break;
            case 6:
                cout<<left;
                cout<<setw(3)<<"#";
                cout<<setw(20)<<"Vendedor:";
                cout<<setw(10)<<"D/M";
                cout<<setw(40)<<"Producto";
                cout<<setw(10)<<"Cant.";
                cout<<setw(20)<<"Proveedor S/.";
                cout<<endl;
                for(int i = 0; i < nArt; i++){
                    cout<<left<<setw(3)<<i+1;
                    listaArticulos[i].mostrarDatos();
                }
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
