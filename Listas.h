#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <ctime>
#include<locale.h>
#include <iomanip>
#include<sstream>
#include <math.h>
using namespace std;


struct NodoCamion{
	int Codigo_camion;
	int indice;
	string Placa_camion;
	NodoCamion *sgte;
};

struct NodoTrabajador{
	int Codigo_trabajador;
	string Nombresyapellidos_trabajador;
	string cargo_trabajador;
	string usuario_Tb;
	string contrasena_Tb;
	NodoTrabajador *sgte;
};

struct NodoCarga{
	int codigo_Car;
	string contenido_Car;
	string destino_Car;
	string estado_Car;
	string horario_Car;
	double peso_Car;
	double costo_Car;
	NodoCarga *sgte;
};

struct NodoReporteEntrega{
	int codigo_Entrega;
	string codigo_CH;
	string chofer_Entrega;
	string codigo_Carga;
	string contenido_Entrega;
	double costo_Entrega;
	string estado_Entrega;
	NodoReporteEntrega *sgte;
};

int ALEA = 10;
int indiceC = -1;
void insertarListaCamion(NodoCamion *&, int, string,int);
void mostrarListaCamion(NodoCamion *);
void insertarListaTrabajador(NodoTrabajador *&, int, string,string,string,string,string);
void mostrarListaTrabajador(NodoTrabajador *);
void insertarListaCarga(NodoCarga *&, int, string, string, string, string,double,double);
void mostrarListaCarga(NodoCarga *);
bool ingresarSistemaTrabajador(NodoTrabajador *, string, string);


void insertarListaCamion(NodoCamion *&listaCamion, int CodigoC, string PlacaC, int indice){
	NodoCamion *nuevo_nodo  = new NodoCamion();
	NodoCamion *nodo_aux = new NodoCamion();
	nuevo_nodo -> Codigo_camion = CodigoC;
	nuevo_nodo -> Placa_camion = PlacaC;
	nuevo_nodo -> indice = indice;
	nuevo_nodo -> sgte = NULL;
	if(listaCamion == NULL){
		listaCamion = nuevo_nodo;
		indiceC ++;
	}
	else{
		nodo_aux = listaCamion;
		while(nodo_aux->sgte!=NULL){
			nodo_aux = nodo_aux->sgte;
		}
		nodo_aux->sgte = nuevo_nodo;
		indiceC ++;
	}
}

void mostrarListaCamion(NodoCamion *listaCamion){
	NodoCamion *actual = new NodoCamion();
	actual = listaCamion;
	
	while(actual != NULL){
		cout<<actual->Codigo_camion<<"                     "<<actual->Placa_camion<<"          "<<endl<<endl;
		actual = actual->sgte;
	}
	getch();
	return;
}

void ordenarListaCamion(NodoCamion *&listaCamion)//burbuja
{
    NodoCamion *actual = new NodoCamion();
    actual = listaCamion;
    NodoCamion *siguiente = new NodoCamion(); 
     int C;
     string P;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;

          while(siguiente!=NULL)
          {
               if(actual->Codigo_camion > siguiente->Codigo_camion)
               {
                    C = siguiente->Codigo_camion;
                    siguiente->Codigo_camion = actual->Codigo_camion;
                    actual->Codigo_camion = C;
                    P = siguiente->Placa_camion ;
                    siguiente->Placa_camion = actual->Placa_camion ;
                    actual->Placa_camion  = P;
               }
               siguiente = siguiente->sgte;
          }
          actual = actual->sgte;
          siguiente = actual->sgte;

     }
}

NodoCamion* busquedaBinariaCamion(NodoCamion *&listaCamion, int buscar){//busqueda binaria con listas enlazadas
	NodoCamion *aux = new NodoCamion();
	NodoCamion *aux2 = new NodoCamion();
	NodoCamion *devolver = new NodoCamion();
	aux = listaCamion;
	int inferior = 0,mitad,mid,sup,inf;
	sup = indiceC;
    int numitad;
    char band='F';
    inf = 0;
    if(listaCamion!= NULL){
    	
    	
    	while(inf<=sup){
    		mid =(inf+sup)/2;
    		while(aux!= NULL){
    			if(aux->indice == mid){
    			numitad = aux->Codigo_camion;
    			aux2 = aux;
			   }
			   aux = aux->sgte;
			}
			aux = listaCamion;
		    if(numitad == buscar){
			band = 'V';
			devolver = aux2;
			break;
		    }
		
		if(numitad>buscar){
			sup = mid;
			mid =(inf+sup)/2;
			while(aux != NULL){
				if(aux->indice == mid){
					numitad = aux->Codigo_camion;
				}
				aux = aux->sgte;
			}
			aux=listaCamion;
		}
		
		if(numitad<buscar){
			inf = mid;
			mid =(inf+sup)/2;
			while(aux != NULL){
				if(aux->indice == mid){
					numitad = aux->Codigo_camion;
				}
				aux = aux->sgte;
			}
			aux=listaCamion;
		}
			 
	} 
			if(band == 'V'){
            return devolver;
	}else{
			return NULL;
	}
	}

}

void insertarListaTrabajador(NodoTrabajador *&listaTrabajador, int codigoTb, string nombreTb,string apellidoTb, string cargoTb,string usu_Tb, string contra_Tb){
	
	NodoTrabajador *nuevo_nodo  = new NodoTrabajador();
	nuevo_nodo -> Codigo_trabajador =  codigoTb;
	nuevo_nodo -> Nombresyapellidos_trabajador = nombreTb+" "+apellidoTb;
	nuevo_nodo -> usuario_Tb = usu_Tb;
	nuevo_nodo -> contrasena_Tb = contra_Tb;
	nuevo_nodo -> cargo_trabajador = cargoTb;
	nuevo_nodo -> sgte = listaTrabajador;
	listaTrabajador = nuevo_nodo;
    //cout<<endl<<"---------Se ingreso correctamente el trabajador"<<endl;
}

void mostrarListaTrabajador(NodoTrabajador *listaTrabajador){
	NodoTrabajador *actual = new NodoTrabajador();
	
	actual = listaTrabajador;
	 
	while(actual!=NULL){
		//if(actual -> cargo_trabajador == "chofer"){
				    cout<<actual-> Codigo_trabajador<<"                     "<<actual->Nombresyapellidos_trabajador<<"              "<<actual ->cargo_trabajador<<"                "<<actual -> usuario_Tb<<"   "<<actual -> contrasena_Tb<<endl<<endl;		
		//}
	    actual = actual->sgte;
	 }				 				 			
	getch();
	return;
}

void mostrarListaChofer(NodoTrabajador *listaTrabajador){
	NodoTrabajador *actual = new NodoTrabajador();
	
	actual = listaTrabajador;
	 
	while(actual!=NULL){
		if(actual -> cargo_trabajador == "chofer"){
				    cout<<actual-> Codigo_trabajador<<"                     "<<actual->Nombresyapellidos_trabajador<<"              "<<actual ->cargo_trabajador<<"                "<<actual -> usuario_Tb<<"   "<<actual -> contrasena_Tb<<endl<<endl;		
		}
	    actual = actual->sgte;
	 }				 				 			
	getch();
	return;
}

void mostrarListaAdministrador(NodoTrabajador *listaTrabajador){
	NodoTrabajador *actual = new NodoTrabajador();
	
	actual = listaTrabajador;
	 
	while(actual!=NULL){
		if(actual -> cargo_trabajador == "administrador"){
				    cout<<actual-> Codigo_trabajador<<"                     "<<actual->Nombresyapellidos_trabajador<<"              "<<actual ->cargo_trabajador<<"                "<<actual -> usuario_Tb<<"   "<<actual -> contrasena_Tb<<endl<<endl;		
		}
	    actual = actual->sgte;
	 }				 				 			
	getch();
}

void mostrarListaSecretario(NodoTrabajador *listaTrabajador){
	NodoTrabajador *actual = new NodoTrabajador();
	
	actual = listaTrabajador;
	 
	while(actual!=NULL){
		if(actual -> cargo_trabajador == "secretario"){
				    cout<<actual-> Codigo_trabajador<<"                     "<<actual->Nombresyapellidos_trabajador<<"              "<<actual ->cargo_trabajador<<"                "<<actual -> usuario_Tb<<"   "<<actual -> contrasena_Tb<<endl<<endl;		
		}
	    actual = actual->sgte;
	 }				 				 			
	getch();
	
}

void ordenarListaTrabajador(NodoTrabajador *&listaTrabajador)//burbuja
{
     NodoTrabajador *actual = new NodoTrabajador();
    actual = listaTrabajador;
    NodoTrabajador *siguiente = new NodoTrabajador(); 
     int C;
     string NA;
     string usu;
     string contra;
     string cartra;
     while(actual->sgte != NULL)
    {
    	siguiente = actual->sgte;
    	
          while(siguiente!=NULL)
          {				   
               if(actual->Codigo_trabajador > siguiente->Codigo_trabajador)
               {
                    C = siguiente->Codigo_trabajador;
                    siguiente->Codigo_trabajador = actual->Codigo_trabajador;
                    actual->Codigo_trabajador = C;                    
                    NA = siguiente->Nombresyapellidos_trabajador;
                    siguiente->Nombresyapellidos_trabajador = actual->Nombresyapellidos_trabajador ;
                    actual->Nombresyapellidos_trabajador  = NA;                    
                    usu = siguiente->usuario_Tb;
                    siguiente->usuario_Tb = actual->usuario_Tb ;
                    actual->usuario_Tb  = usu;
                    contra = siguiente->contrasena_Tb;
                    siguiente->contrasena_Tb = actual->contrasena_Tb ;
                    actual->contrasena_Tb  = contra;
                    cartra = siguiente->cargo_trabajador ;
                    siguiente->cargo_trabajador = actual->cargo_trabajador ;
                    actual->cargo_trabajador  = cartra;
                    
               }
               siguiente = siguiente->sgte;
          }
           actual = actual->sgte;
          siguiente = actual->sgte;
     }             
}

bool ingresarSistemaTrabajador(NodoTrabajador *listaTrabajador, string us, string contra){
	NodoTrabajador *actual = new NodoTrabajador();
	actual = listaTrabajador;
	
	while(actual != NULL){
	    if(actual ->usuario_Tb == us && actual -> contrasena_Tb == contra){
	    	return true;
		}
		actual = actual->sgte;
    };
	    return false;
}

void insertarListaCarga(NodoCarga *&listaCarga, int codigoCar, string contCar, string destCar, string estCar, string horaCar, double peso, double costo){
	NodoCarga *nuevo_nodo = new NodoCarga();
	nuevo_nodo -> codigo_Car = codigoCar;
	nuevo_nodo -> contenido_Car = contCar;
	nuevo_nodo -> destino_Car = destCar;
	nuevo_nodo -> estado_Car = estCar;
	nuevo_nodo -> horario_Car = horaCar;
	nuevo_nodo -> peso_Car = peso;
	nuevo_nodo -> costo_Car = costo;
	nuevo_nodo -> sgte = listaCarga;
	listaCarga = nuevo_nodo;
	
}

void buscarListaChoferes(NodoTrabajador *listaTrabajador){//busqueda lineal
    int codigo;
    cout<<"\nDigite el codigo del chofer a buscar";
    cin>>codigo;

    NodoTrabajador *actual = new NodoTrabajador();

    actual = listaTrabajador;

    while(actual!=NULL){
        if(actual -> cargo_trabajador == "Chofer"){
            if(actual->Codigo_trabajador == codigo){
                cout<<endl<<actual-> Codigo_trabajador<<"                     "<<actual->Nombresyapellidos_trabajador<<"              "<<actual ->cargo_trabajador<<"                "<<actual -> usuario_Tb<<"   "<<actual -> contrasena_Tb<<endl<<endl;
                return;
            }
        }
        actual = actual->sgte;
     }
    cout<<"\nNo se encontre el chofer";
    return;
}
void buscarCarga(NodoCarga *listaCarga){
	int codigo;
    cout<<"\nDigite el codigo de la carga a buscar...";
    cin>>codigo;

    NodoCarga *actual = new NodoCarga();

    actual = listaCarga;

    while(actual != NULL){
        if(codigo == actual->codigo_Car){
            cout<<actual->codigo_Car<<"                       "<<actual->contenido_Car<<"                       "<<actual->destino_Car<<"                       "<<actual->estado_Car<<"                     "<<actual->horario_Car<<"          "<<actual->peso_Car<<"              "<<actual->costo_Car<<endl<<endl;
            cout<<"\nSe encontro el codigo";
            return;
        }
        actual = actual->sgte;
    }
    cout<<"\nNo se encontro la carga";
    return;
}

void ordenarListaCarga(NodoCarga *&listaCarga)//burbuja
{
    NodoCarga *actual = new NodoCarga();
    actual = listaCarga;
    NodoCarga *siguiente = new NodoCarga(); 
     int C;
     string Cont;
     string D;
     string E;
     string H;
     double P;
     double F;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;

          while(siguiente!=NULL)
          {
               if(actual->codigo_Car > siguiente->codigo_Car)
               {
                    C = siguiente->codigo_Car ;
                    siguiente->codigo_Car = actual->codigo_Car ;
                    actual->codigo_Car = C;
                    
                    Cont = siguiente->contenido_Car;
                    siguiente->contenido_Car = actual->contenido_Car ;
                    actual->contenido_Car = Cont;
                    
                    D = siguiente->destino_Car;
                    siguiente->destino_Car = actual->destino_Car ;
                    actual->destino_Car = D;
                    
                    E = siguiente->estado_Car;
                    siguiente->estado_Car = actual->estado_Car ;
                    actual->estado_Car = E;   
					                
                    H = siguiente->horario_Car;
                    siguiente->horario_Car = actual->horario_Car ;
                    actual->horario_Car = H;
                    
                    P = siguiente->peso_Car;
                    siguiente->peso_Car=actual->peso_Car;
                    actual->peso_Car = P;
                    
                    F = siguiente->costo_Car;
                    siguiente->costo_Car=actual->costo_Car;
                    actual->costo_Car=F;
               }
               siguiente = siguiente->sgte;
          }
          actual = actual->sgte;
          siguiente = actual->sgte;

     }
}


void mostrarListaCarga(NodoCarga *listaCarga){
	NodoCarga *actual = new NodoCarga();
	
	actual = listaCarga;
	
	while(actual != NULL){
		cout<<actual->codigo_Car<<"                       "<<actual->contenido_Car<<"                       "<<actual->destino_Car<<"                       "<<actual->estado_Car<<"                     "<<actual->horario_Car<<"          "<<actual->peso_Car<<"              "<<actual->costo_Car<<endl<<endl;
		actual = actual->sgte;
	}
	getch();
	return;
}

void pagarCarga(double precio){//voraz
	const int TAM=14;
    float Monedas [TAM]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};
    int Acumulado[TAM]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float saldo;
    int indice=0;
    double pago_actual;
    float vuelto;
    cout<<"El precio a pagar es de "<<precio<<" desearia pagar con cuanto?"<<endl;
    cin>>pago_actual;

    vuelto = pago_actual-precio;
	if(vuelto>0){
    //se imprime los datos del precio por paquete y el monto que pago el usuario
    cout<<"\nEl pago del usuario fue de: S/. "<<pago_actual<<endl;
    cout<<"Precio de la Carga: S/. "<<precio<<endl;
    cout<<"\n Vuelto "<<vuelto<<endl;
        while(vuelto>0){
                if(vuelto>=Monedas[indice]){
                    Acumulado[indice]++;
                    vuelto=round((vuelto-Monedas[indice])*100)/100;
                } else{ indice++; }
        }


        for(int i=0; i<TAM;i++){
            if(Acumulado[i]>0){
            	if(Monedas [i]==10 || Monedas [i]==20 || Monedas [i]==50 || Monedas [i]==100 || Monedas [i]==200){
            		cout<<"Billete de "<<Monedas [i]<<"\t => "<<Acumulado[i]<<endl;
				}
				else{
					cout<<"Monedas de "<<Monedas [i]<<"\t => "<<Acumulado[i]<<endl;	
				}
               	
            }
        }
    }
    else{
        cout<<"\nERROR";
    }
	getch();
}


void modificarListaCamion(NodoCamion *listaCamion,int auxcodigo){
    NodoCamion *recorrido= new NodoCamion();
    recorrido=listaCamion;
    bool encontrado=false;

        while(recorrido!= NULL){
            if(auxcodigo==recorrido->Codigo_camion){
                cout<<"\nCodigo de Camion: "<<recorrido->Codigo_camion;
                cout<<"\nPlaca: "<<recorrido->Placa_camion;

                cout<<"\n----------------NUEVOS DATOS----------------"<<endl;
                cout<<"\nCodigo de Camion: "<<recorrido->Codigo_camion;
                cout<<"\nPlaca: ";
                cin>>recorrido->Placa_camion;
                encontrado=true;
            }
            recorrido= recorrido->sgte;

    }
    getch();
    return;
}
void modificarListaTRabajador(NodoTrabajador *listaTrabajador,int auxtrabajador){
        NodoTrabajador *recorrido=new NodoTrabajador();
        recorrido = listaTrabajador;
        bool encontrado=false;

            while(recorrido!= NULL){
            if(auxtrabajador==recorrido->Codigo_trabajador){

                cout<<"Codigo Trabajador: "<<recorrido->Codigo_trabajador<<endl;
                cout<<"Nombre y Apellido: "<<recorrido->Nombresyapellidos_trabajador<<endl;
                cout<<"Cargo: "<<recorrido->cargo_trabajador<<endl;
                cout<<"Usuario: "<<recorrido->usuario_Tb<<endl;
                cout<<"Contraseña: "<<recorrido->contrasena_Tb<<endl;


                cout<<"\n----------------NUEVOS DATOS----------------"<<endl;
                cout<<"\nCodigo Trabajador: "<<recorrido->Codigo_trabajador;
                cout<<"\nNombre y Apellido: ";
                cin>>recorrido->Nombresyapellidos_trabajador;
                cout<<"\nCargo: ";
                cin>>recorrido->cargo_trabajador;
                cout<<"\nUsuario: ";
                cin>>recorrido->usuario_Tb;
                cout<<"\nContraseña: ";
                cin>>recorrido->contrasena_Tb;
                encontrado=true;
            }
            recorrido= recorrido->sgte;

    }
    getch();
    return;
}
void modificarListaCarga(NodoCarga *listaCarga,int auxCarga){
        NodoCarga *recorrido=new NodoCarga();
        recorrido = listaCarga;
        bool encontrado=false;

        while(recorrido!= NULL){
            if(auxCarga==recorrido->codigo_Car){

                cout<<"Codigo Carga: "<<recorrido->codigo_Car<<endl;
                cout<<"Contenido: "<<recorrido->contenido_Car<<endl;
                cout<<"Destino: "<<recorrido->destino_Car<<endl;
                cout<<"Estado: "<<recorrido->estado_Car<<endl;
                cout<<"Horario: "<<recorrido->horario_Car<<endl;


                cout<<"\n----------------NUEVOS DATOS----------------"<<endl;
                cout<<"\nCodigo Carga: "<<recorrido->codigo_Car;
                cout<<"\nContenido: ";
                cin>>recorrido->contenido_Car;
                cout<<"\nDestino: ";
                cin>>recorrido->destino_Car;
                cout<<"\nEstado: ";
                cin>>recorrido->estado_Car;
                cout<<"\nHorario: ";
                cin>>recorrido->horario_Car;
                encontrado=true;
            }
            recorrido= recorrido->sgte;

    }
    getch();
    return;
}


bool insertarListaEntrega(NodoReporteEntrega *&listaEntrega, int codigo_E, string codigo_Ch, string ch_Entrega, string codigo_Car, string contenido_Car, double costo, string estado){
	NodoReporteEntrega *nuevo_nodo  = new NodoReporteEntrega();
	nuevo_nodo -> codigo_Entrega = codigo_E;
	nuevo_nodo -> codigo_CH = codigo_Ch;
	nuevo_nodo -> chofer_Entrega = ch_Entrega;
	nuevo_nodo -> codigo_Carga = codigo_Car;
	nuevo_nodo -> contenido_Entrega = contenido_Car;
	nuevo_nodo -> costo_Entrega = costo;
	nuevo_nodo -> estado_Entrega = estado;
	nuevo_nodo -> sgte = listaEntrega;
	listaEntrega = nuevo_nodo;
	return true;
}

void mostrarListaEntregas(NodoReporteEntrega *listaEntrega){
	NodoReporteEntrega *actual = new NodoReporteEntrega();
	actual = listaEntrega;
	system("cls");
	cout<<"-------------------ENTREGAS-------------------"<<endl;
	while(actual != NULL){
		cout<<actual->codigo_Entrega<<"                       "<<actual-> codigo_CH<<"                       "<<actual->chofer_Entrega<<"                       "<<actual->codigo_Carga<<"                     "<<actual->contenido_Entrega<<"                     "<<actual->costo_Entrega<<"           "<<actual->estado_Entrega<<endl;
		actual = actual->sgte;
	}
	getch();
	
}

string* aleatorioListaEntrega(NodoTrabajador *listaTrabajador, int auxcod_Ch){ //aleatorios
	  NodoTrabajador *actual = new NodoTrabajador();
	  actual = listaTrabajador;
      static string valores[5];
      int cont=0;
      if(listaTrabajador != NULL){
      while(actual -> sgte != NULL){
	  if(auxcod_Ch == actual -> Codigo_trabajador){

	  	ostringstream o;
	  	o << auxcod_Ch;
	  	valores[cont] = o.str();
	  	cont++;
	  	valores[cont] = actual -> Nombresyapellidos_trabajador; 
	  	cont++;  
	  	return valores;
	    }
		actual = actual->sgte;
	   }
    }
	  
}

