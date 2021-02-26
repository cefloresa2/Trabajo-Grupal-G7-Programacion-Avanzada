#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;



struct tproducto{
   	char nombre[20];
	char proveedor[13];
   	char fechacaduca[13];
   	float preciocoste;
   	int unidades;
   	int id;
};
int SIZE = sizeof(tproducto);
void mostrar(tproducto &pro){
    cout<<"Nombre: "<<pro.nombre<<endl;
    cout<<"Cantidad: "<<pro.unidades<<endl;
}

struct tcliente
{
   	char nombre[20];
	char correo[13];
   	int celular;
   	int dni;
};
int SIZE = sizeof(tcliente);


struct proveedores
{
   	char nombre[20];
	char direccion[13];
	char correo[13];
   	int celular;
   	int codigo;
}pro[50];




struct factura
{
   	char nombre[20];
	char fecha[13];
   	int codigo;
   	char producto[13];
   	int cantidad;
}fact[50];








int main() {
	
	system ("COLOR B1"); 
	int n, to=0, to2=0, m=0, m2=0, l, numero=1, numero1=1, numero2=1, n1, n2, n3, idp, idp1, idp2, toa, tob, i;
	char op, op1, op2, op3, op4, o; 
	string bj;
	
	string b;
	
	
for(int i=1; i<=100; i++)
	{
		
		cout<<endl<<"          Sistema de facturacion para supermercado"<<endl;	
		cout<<endl<<"                  Super Mercado Peruano                "<<endl;		
		cout<<endl<<"                       Version 1.0              "<<endl;		
		cout<<endl<<"                       GermanApaza"<<endl;
		
		
		
		
		cout<<endl<<"----------MENU PRINCIPAL----------"<<endl;
	    cout<<"a.-Productos."<<endl;
		cout<<"b.-Clientes"<<endl;
		cout<<"c.-Proveedores."<<endl;
		cout<<"d.-Facturacion."<<endl;
		cout<<"f.-Salir"<<endl;
		cout<<endl<<"elija una opcion : ";
		cin>>op;
		cout<<endl;
		cout<<"------------------------------------------------------"<<endl;
		system("CLS");
		
		
		
//------------------------------------OPCION a:  PRODUCTOS	
		
		if(op=='a') 
		{
				
				while(numero!=0) 
			{  			
			
				cout<<endl<<"----------MENU PRODUCTOS----------"<<endl;
				cout<<"a.-Registrar producto."<<endl;
		        cout<<"b.-Modificar producto."<<endl;
		        cout<<"c.-Ver productos."<<endl;
				cout<<"f.-Salir"<<endl;
				cout<<"elija una opcion : ";
		        cin>>op1;
		    		cout<<endl;
					cout<<"------------------------------------------------------"<<endl;
					system("CLS");	        
				

					if(op1=='a') 						
				{
				   	tproducto producto; 	
									
					fstream archivo;
    				archivo.open("bd.dat", ios::out | ios::binary);
    				bool seguir = true;
    				while (seguir) {
    				
        			cout <<"\nIngresa el nombre del producto: ";
        			cin.sync();
       				cin.getline(producto.nombre,20);
        			cout <<"\nIngresa el nombre del proveedor de este producto: ";
        			cin.sync();
        			cin.getline(producto.proveedor,13);	
        			cout << "\nIngresa la fecha de caducidad(//): ";
        			cin.sync();
        			cin.getline(producto.fechacaduca,13);        		      			
					cout<<"\nIngrese la cantidad de unidades: ";
					cin.sync();
					cin>>producto.unidades;				
					cout<<"\nIngresa su precio costo en soles: ";
					cin.sync();
					cin>>producto.preciocoste;				
					cout<<"\nIngrese el ID del producto: ";
					cin.sync();
					cin>>producto.id;
       			
        			archivo.write((char *) &producto, SIZE);
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
					system("CLS");
			}
	
				else
				{
					if(op1 == 'b')
					{
			
					cout<<"Modificacion de informacion de un  producto: ";
				    cout<<"\n"<<endl;
//------------------------------------- ------------------------------S
                       	tRegistro registro;
						fstream archivo;
						archivo.open("bd.dat", ios::in | ios::out | ios::binary);
						archivo.seekg(0, ios::end);
						int pos = archivo.tellg();
						int numReg = pos / SIZE;
						cout << "Numero de registros: " << numReg << endl;
						int num;
						cout << "Registro numero? ";
						cin >> num;
						if ((num > 0) && (num <= numReg)) {
						archivo.seekg((num - 1) * SIZE, ios::beg);
						archivo.read( (char *) &registro, SIZE);
						mostrar(registro);
						cout << endl << "Cambiar nombre [S/N]? ";
						char c;
						cin.sync();
						cin >> c;
						if ((c == 's') || (c == 'S')) {
						cout << "Nombre: ";
						cin.sync();
						cin.getline(registro.nombre, 80);
						}
						cout << endl << "Cambiar promedio [S/N]? ";
						cin.sync();
						cin >> c;
						if ((c == 's') || (c == 'S')) {
						cout << "Precio: ";
						cin >> registro.promedio;
						}
						archivo.seekg((num - 1) * SIZE, ios::beg);
						archivo.write( (char *) &registro, SIZE);
						cout << endl << "Registro actualizado:" << endl;
						archivo.seekg((num - 1) * SIZE, ios::beg);
						archivo.read( (char *) &registro, SIZE);
						mostrar(registro);
						}
					archivo.close();
					return 0;


				    cout<<"Ingrese el ID del producto: ";
				    cin>>idp;
				    cout<<"\n"<<endl;
				    for(int i=1; i<=n1; i++)
					{
						if(pr[i].id == idp)
	 					{
	 					
	 						fflush(stdin);   
   							cout<<"\nIngresa el nombre del producto: ";
   							cin.getline(pr[i].nombre,20);
   							cout<<"\nIngresa el nombre del proveedor de este producto: ";
   							cin.getline(pr[i].proveedor,13);				
				
   							cout<<"\nIngresa la fecha de caducidad(//): ";
   							fflush(stdin);
							cin.getline(pr[i].fechacaduca,13);
				
							cout<<"\nIngrese la cantidad de unidades: ";
							cin>>pr[i].unidades;
				
							cout<<"\nIngresa su precio costo en soles: ";
							cin>>pr[i].preciocoste;
				
	 						cout<<"\nIngrese el ID del producto: ";
				            cin>>pr[i].id;
				 		}
    				}
    				cout<<"\n"<<endl;

					system("pause");
//------------------------------------- ------------------------------S
					}
				    system("CLS");
					}
					else
					{
						if(op1=='c')
						{	
					         cout<<"\n"<<endl;
							 cout<<"   nombre  proveedor  fech.cadu.   unidades    precio    id    "<<endl;
					         cout<<"\n"<<endl;
					    
					    	for(int i=1; i<=n1; i++)
			    				{
								fflush(stdin);   
								cout<<"  "<<pr[i].nombre;
   							
   							    cout<<"  "<<pr[i].proveedor;
				
   								cout<<"    "<<pr[i].fechacaduca;
				 
				                cout<<"         "<<pr[i].unidades;
				                          
								cout<<"         "<<pr[i].preciocoste;
								
								cout<<"       "<<pr[i].id;
				
				                cout<<"\n"<<endl;
				                
								
					    
								}
								
						system("pause");
						system("CLS");
						}		
						else
						{
							if(op1=='f')
							{
						     numero=0;
							}
						}
    				
					}
 				}	
			
			}
		}
//------------------------------------- OPCION b CLIENTES
			
		else
		{
			if(op == 'b')
			{
				
			   while(numero1!=0) 
				{  			
					cout<<endl<<"----------MENU CLIENTES----------"<<endl;
				cout<<"a.-Registrar cliente."<<endl;
		        cout<<"b.-Modificar cliente."<<endl;
		        cout<<"c.-Ver clientes."<<endl;
				cout<<"f.-Salir"<<endl;
				cout<<"elija una opcion : ";
		        cin>>op2;
					cout<<endl;
					cout<<"------------------------------------------------------"<<endl;
					system("CLS");	
				
				
				
					if(op2=='a') 
				{
					tcliente cliente; 	
									
					fstream archivo;
    				archivo.open("bd.dat", ios::out | ios::binary);
    				bool seguir = true;
    				while (seguir) {
    				
        			cout <<"\nIngresa el nombre del cliente: ";
        			cin.sync();
       				cin.getline(cliente.nombre,20);
        			cout<<"\nIngrese el DNI del cliente: ";
        			cin.sync();
        			cin>>cliente.dni;        		      					
        			cout <<"\nIngresa el ruc del cliente: ";
        			cin.sync();
       				cin.getline(cliente.ruc,20);				
					
       			
        			archivo.write((char *) &producto, SIZE);
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
					system("CLS");
					

				}
				else
				{
					if(op2 == 'b')
					{
				  
				  	cout<<"Modificacion de informacion de un  cliente: ";
				    cout<<"\n"<<endl;
				    cout<<"Ingrese el DNI del cliente: ";
				    cin>>idp1;
				    cout<<"\n"<<endl;
				    for(int i=1; i<=n2; i++)
					{
						if(cl[i].dni == idp1)
	 					{
	 					
	 						fflush(stdin);   
   							cout<<"\nIngresa el nombre del cliente: ";
   							cin.getline(cl[i].nombre,20);
   						
				
   							cout<<"\nIngresa el correo del cliente: ";
   							fflush(stdin);
							cin.getline(cl[i].correo,13);
				
							cout<<"\nIngrese el numero de telefono del cliente: ";
							cin>>cl[i].celular;
				
							cout<<"\nIngrese el DNI del cliente: ";
							cin>>cl[i].dni;
				
   			 				cout<<"\n\n"<<endl;
   							cout<<"--------------------------------------"<<endl;
   							cout<<"\n"<<endl;
   							system("CLS");
				  
				  
				  
				  			}
						}
					}
					
					else
					{
						if(op2=='c')
						{	
					  
					  
					 	 cout<<"\n"<<endl;
							 	cout<<"   nombre  correo   celular     dni    "<<endl;
					         	cout<<"\n"<<endl;
					    
					    		for(int i=1; i<=n2; i++)
			    					{
									fflush(stdin);   
									cout<<"  "<<cl[i].nombre;
   							
   							    	cout<<"  "<<cl[i].correo;
				
   									cout<<"    "<<cl[i].celular;
				 
				               	 	cout<<"        "<<cl[i].dni;
				                          

				                	cout<<"\n"<<endl;
				                
								
					  
								}
								
						system("pause");
						system("CLS");
						}					
						else
						{
							if(op2=='f')
							{
						     numero1=0;
							}
						}
    				
					}
 				}	
				
				
				
				}
				
			}
			
//------------------------------------- OPCION c PROVEEDORES			
			else
			{
				if(op=='c')
				{	
				
				
					while(numero2!=0){
				
					cout<<endl<<"----------MENU PROEEVEDORES----------"<<endl;
					cout<<"a.-Registrar proveedor."<<endl;
		        	cout<<"b.-Modificar proveedor."<<endl;
		        	cout<<"c.-Ver proveedor."<<endl;
					cout<<"f.-Salir"<<endl;
					cout<<"elija una opcion : ";
		        	cin>>op3;
		        	cout<<endl;
					cout<<"------------------------------------------------------"<<endl;
					system("CLS");	
		        	
		        	
		        			        	
		        	
						if(op3=='a') 
					{
			
			    		    cout<<"Ingrese cuantos proveedores va a registrar: ";
    		    			 cin>>n3;
    		     			cout<<"\n"<<endl;
    		     
    		    			for(int i=1; i<=n3; i++)
			    			{
							fflush(stdin);   
   							cout<<"\nIngresa el nombre del proveedor: ";
   							cin.getline(pro[i].nombre,20);
   						
				
   							cout<<"\nIngresa el correo del proveedor: ";
   							fflush(stdin);
							cin.getline(pro[i].correo,13);
							
							cout<<"\nIngresa la direccion del proveedor: ";
   							cin.getline(pro[i].direccion,13);
				
							cout<<"\nIngrese el numero de telefono del proveedor: ";
							cin>>pro[i].celular;
				
							cout<<"\nIngrese el codigo del proveedor: ";
							cin>>pro[i].codigo;
				
   			 				cout<<"\n\n"<<endl;
   							cout<<"--------------------------------------"<<endl;
   							cout<<"\n"<<endl;
   							system("CLS");
			    			}
									
			    			system("CLS");  
			    		  
			    	  
			    	  

			    	  
			
					}
					else
					{
						if(op3 == 'b')
						{
					  
					  
					  		
				    		cout<<"Ingrese el codigo del proveedor: ";
				    		cin>>idp2;
				    		cout<<"\n"<<endl;
				    		for(int i=1; i<=n3; i++)
							{
								if(pro[i].codigo == idp2)
	 							{
	 					
	 								fflush(stdin);   
   										cout<<"\nIngresa el nombre del proveedor: ";
   										cin.getline(pro[i].nombre,20);
   						
				
   										cout<<"\nIngresa el correo del proveedor: ";
   										fflush(stdin);
										cin.getline(pro[i].correo,13);
							
										cout<<"\nIngresa la direccion del proveedor: ";
   										cin.getline(pro[i].direccion,13);
				
										cout<<"\nIngrese el numero de telefono del proveedor: ";
										cin>>pro[i].celular;
				
										cout<<"\nIngrese el codigo del proveedor: ";
										cin>>pro[i].codigo;
									
									
				
   			 						cout<<"\n\n"<<endl;
   									cout<<"--------------------------------------"<<endl;
   									cout<<"\n"<<endl;
   									system("CLS");
				  
				  
				  
				  				}
							}
					  
					  
					  

					  
						}
						else
						{
							if(op3=='c')
							{	

					 	 			cout<<"\n"<<endl;
							 			cout<<"   nombre  correo   celular     codigo   direccion  "<<endl;
					         			cout<<"\n"<<endl;
					    
					    				for(int i=1; i<=n3; i++)
			    						{
										fflush(stdin);   
										cout<<"  "<<pro[i].nombre;
   							
   							    		cout<<"  "<<pro[i].correo;
				
				
   										cout<<"    "<<pro[i].celular;
				 
				               	 		cout<<"          "<<pro[i].codigo;
				                        
				                        cout<<"           "<<pro[i].direccion;
				                        

				                		cout<<"\n"<<endl;
				                
								
					  
										}
								
								system("pause");
								system("CLS");
						  
						  

							}			
							else
							{
								if(op3=='f')
								{
							     numero2=0;
								}
							}
    				
						}
 					}		
				
				
                  
                  }
				
				}
				
//------------------------------------- OPCION d Facturacion 				
			   else
			   {
					if(op=='d')
					{
						

							while(numero2!=0){
				            cout<<"\n"<<endl;
							cout<<endl<<"----------MENU FACTURA----------"<<endl;
							cout<<"a.-Generar factura."<<endl;
		        			cout<<"b.-Ver facturas."<<endl;
							cout<<"f.-Salir"<<endl;
							cout<<"elija una opcion : ";
		        			cin>>op4;
		        			cout<<endl;
							cout<<"------------------------------------------------------"<<endl;
							system("CLS");	
		        	
		        	
		        			        	
		        	
								if(op4=='a') 
							{
			
			    		    	cout<<"Ingrese cuantas facturas va a registrar: ";
    		    			 	cin>>n3;
    		     				cout<<"\n"<<endl;
    		     
    		    				for(int i=1; i<=n3; i++)
			    				{	
								fflush(stdin);   
   								cout<<"\nIngresa el nombre del cliente: ";
   								cin.getline(fact[i].nombre,20);
   						
				
   								cout<<"\nIngresa la fecha: ";
   								fflush(stdin);
								cin.getline(fact[i].fecha,13);
											
												
								cout<<"\nIngrese el codigo de la factura: ";
								cin>>fact[i].codigo;
								
								cout<<"\nIngrese el producto: ";
   								fflush(stdin);
								cin.getline(fact[i].producto,13);
								
								
								cout<<"\nIngrese la cantidad del producto: ";
								cin>>fact[i].cantidad;
								

   			 					cout<<"\n\n"<<endl;
   								cout<<"--------------------------------------"<<endl;
   								cout<<"\n"<<endl;
   								system("CLS");
			    				}
									
			    				system("CLS");  

							}
								else
							{
							if(op4 == 'b')
							{
					  
					  
					  		cout<<"\n"<<endl;
					  		
					  		
					  		
							 			
					    
					    				for(int i=1; i<=n3; i++)
			    						{
										fflush(stdin);   

				                        
				                        
				                  		cout<<"         "<<"SUPERMERCADO EL GRANO"<<endl;
					  		
					  		
							
										cout<<"\n"<<endl;
  										cout<<" FECHA  "<<fact[i].fecha;
										
										cout<<"\n"<<endl;
  										cout<<" FACTURA   "<<fact[i].codigo;
										cout<<"\n"<<endl;
										cout<<"\n"<<endl;
										 cout<<" NOMBRE:  "<<fact[i].nombre;
							  

					  		
					  					cout<<"\n"<<endl; 
				                   
				                   

				               
				                        bj = fact[i].producto;
				                		for(int i=1; i<=n1; i++)
										{
										if(producto.nombre == bj)
	 										{
	 										producto.unidades=pr[i].unidades-fact[i].cantidad;
	 										toa=fact[i].cantidad*pr[i].preciocoste;
	 										tob=pr[i].preciocoste;
	 										
				 							}
    									}
    									cout<<"\n"<<endl;

                                        cout<<"    producto      cantidad       Valor  "<<endl;
					         			cout<<"\n"<<endl;
										cout<<"-------------------------------------------"<<endl;
										cout<<"\n"<<endl;

   										cout<<"    "<<fact[i].producto;
				 
				               	 		cout<<"           "<<fact[i].cantidad;
				                        
				                        cout<<"             "<<toa;


										}
								        cout<<"\n"<<endl;
										cout<<"-------------------------------------------"<<endl;
										cout<<"\n"<<endl;
										cout<<"Precio final                     : "<<toa<<endl;
										cout<<"\n"<<endl;
										
										
										
								system("pause");
								system("CLS");
							}
								else
								{
							
										if(op4=='f')
										{
							    		 numero2=0;
										}
									
    				
							    }
 							}		
				
				
                  
                  		}
									
					
					
//------------------------------------- OPCION f Salir 					
						
						
					}
					else
					{
						
						if(op=='f')
						{
							i=100;
						}
						
    				}
			   }
            }	
     	}
	}


