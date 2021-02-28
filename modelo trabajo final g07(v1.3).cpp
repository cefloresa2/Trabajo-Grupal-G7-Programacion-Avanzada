#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
	  						//______________________________________________________ Cliente
class Cliente{
    private:
        char client[3][20];
		int nclients;
	
		int dni;
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
        int ruc;

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
    int nLib = 0, nRev = 0, nArt = 0, ind = 0, op;
    char opc, pags[8];

    do{
        system("CLS");    //borrar datos
        cout<<"\n\t Sistema de facturacion Tienda: \t"<<endl; //titulo
        cout<<"1. AGREGAR CLIENTE:"<<endl;
        cout<<"2. AGREGAR PROVEEDOR: "<<endl;
        cout<<"3. AGREGAR PRODUCTO: "<<endl;
        cout<<"\t -----------Opciones extras----------- \t"<<endl;
        cout<<"4. MOSTRAR LISTA DE CLIENTES: "<<endl;
        cout<<"5. MOSTRAR LISTA DE PROVEEDORES: "<<endl;
        cout<<"6. MOSTRAR LISTA DE PRODUCTOS: "<<endl;
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
                cout<<setw(40)<<"Cliente";
                cout<<setw(10)<<"DNI:";
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
