#include<iostream>
#include<conio.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<sstream>
#define ENTER 13 
#define BACKSPACE 8
#define ARRIBA 72
#define ABAJO 80
using namespace std;

//1°Headers
#include "cmp.h"
#include "Listas.h"
#include "extra.h"
//2°
struct perfil {
	string nombre;
	string correo;
	string contra;
	string verificacion;
	string numero;
	string dni;
	string tarjeta;
	string cod;
	string pais;
	float dinero;
	perfil *sgte;
};
typedef struct perfil *Mercedes;
Mercedes lista=NULL;
//----------------------------
int choferes[10];
int carga[10];
string admi = "ADMIN";
string contra = "SENHA";
int flag = 0;
int indice =0;
NodoCamion *listaCamion = NULL;
NodoTrabajador *listaTrabajador = NULL;
NodoCarga *listaCarga = NULL;
NodoReporteEntrega *listaEntrega = NULL;
//3°
int proyecto(int n);
int proyecto1(int n);
int proyecto2(int n);
int proyecto3(int n);
int proyecto4(int n);
int proyecto5(int n);
void Menu_Cargas();
void registrar_cargas();
void mostrar_cargas();
void buscar_cargas();
void Menu_chofer();
void registrar_chofer();
void mostrar_chofer();
void buscar_chofer();
void Menu_Camiones();
void registro_camiones();
void camiones_almacenados();
void busqueda_camion();
void modificar_camiones();
void imprimir_opciones();
bool iniciar_sesion();
void creditos_imprimir();
void creditos();
void pantalla_inicio();
void pantalla_principal();
void pantalla();
void mercedes();
void amg();
bool comprabacion_datos();
void registrar(Mercedes &lista,string nombre,string correo,string contra);
int proyecto_camiones(int n);
void Menu_Camiones();
//(Johan)
void menu_principal();
void Menu_Loggin();
void Menu_Camiones();
void Menu_Area();
void Menu_Choferes();
void Menu_Cargas();
void GenerarAleatorioCamion();
void GenerarAleatorioTrabajador();
void GenerarAleatorioCarga();

//4°
int main(){
	SetConsoleTitle("Proyecto GTR");
	srand(time(NULL));
	GenerarAleatorioCamion();
    GenerarAleatorioTrabajador();
    GenerarAleatorioCarga();
    //---------------------------------------
	registrar(lista,"admin","admin","admin");
	pantalla();
	return 0;
}
//----------------------------------
void mercedes(){
	int posX=27,posY=13; 
	//color(130);
	gotoxy(posX,posY);  cout<<"_|      _|  _|_|_|_|  _|_|_|      _|_|_|  _|_|_|_|  _|_|_|    _|_|_|_|    _|_|_|";  
	gotoxy(posX,posY+1);cout<<"_|_|  _|_|  _|        _|    _|  _|        _|        _|    _|  _|        _|      ";  
	gotoxy(posX,posY+2);cout<<"_|  _|  _|  _|_|_|    _|_|_|    _|        _|_|_|    _|    _|  _|_|_|      _|_|  ";  
	gotoxy(posX,posY+3);cout<<"_|      _|  _|        _|    _|  _|        _|        _|    _|  _|              _|";  
	gotoxy(posX,posY+4);cout<<"_|      _|  _|_|_|_|  _|    _|    _|_|_|  _|_|_|_|  _|_|_|    _|_|_|_|  _|_|_|  "; 
}
void amg(){
	int posX=2,posY=27; 
	//color(132);
	gotoxy(posX,posY);  cout<<"    ___    __  __ ______";  
	gotoxy(posX,posY+1);cout<<"   /   |  /  |/  / ____/";  
	gotoxy(posX,posY+2);cout<<"  / /| | / /|_/ / / __  ";  
	gotoxy(posX,posY+3);cout<<" / ___ |/ /  / / /_/ /  ";  
	gotoxy(posX,posY+4);cout<<"/_/  |_/_/  /_/_____/   ";
}
void pantalla(){
	system("mode con: cols=136 lines=34");
	CursorOff();
	system("color F0");
	color(248);//XTR
	cuadro(0,135,0,33);//Cuadro grande
	linea(1,135,32);//linea
	color(240);//XTR
	cuadro(1,5,1,3); //Cuadro regresar
	linea(2,5,4);//linea
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,65,3);//linea
	pantalla_inicio();
}

int proyecto1(int n){
	CursorOff();
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,65,3);//linea
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	cuadro(1,22,5,7);//Cuadro titulo
	cuadro(115,134,29,31);//Cuadro creditos
	mercedes();
	amg();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_principal();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(2,6);cout<<" Hola, Identificate ";
				break;
			}
			case 2:{
				color(252);
				gotoxy(121,30);cout<<"Creditos";
				break;
			}
			case 3:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void pantalla_inicio(){
	bool repetidor=true;
	int opcion,n=3;
	do{
		opcion = proyecto1(n);
		switch(opcion){
			case 1:{
				if(iniciar_sesion()){
					pantalla_principal();
				}
				break;
			}
			case 2:{
				creditos();
				break;
			}
			case 3:{
				exit(0);
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}

void registrar(Mercedes &lista,string nombre,string correo,string contra){
	Mercedes escribir;
	escribir = new(perfil);
	escribir->nombre=nombre;
	escribir->correo=correo;
	escribir->contra=contra;
	escribir->verificacion="";
	escribir->numero="";
	escribir->dni="";
	escribir->tarjeta="";
	escribir->cod="";
	escribir->pais="";
	escribir->dinero=0;
	escribir->sgte=lista;
	lista=escribir;
}
int menu_crear_cnt(int n){
	CursorOff();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borar_crearx();
		//color(4);
		switch(selec){
			case 1:{
				gotoxy(34,6); cout<<"[";
				gotoxy(47,6); cout<<"]";
				break;
			}
			case 2:{
				gotoxy(2,2);cout<<"[";
				gotoxy(4,2);cout<<"]";				
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
int menu_sesion(int n){
	CursorOff();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borar_opciones_sesion();

		switch(selec){
			case 1:{
				gotoxy(34,7);  cout<<"[";
				gotoxy(49,7);  cout<<"]";
				break;
			}
			case 2:{
				gotoxy(47,14);cout<<"[";
				gotoxy(57,14);cout<<"]";
				break;
			}
			case 3:{
				gotoxy(34,19);cout<<"[";
				gotoxy(53,19);cout<<"]";
				break;
			}
			case 4:{
				gotoxy(40,25); cout<<"[";
				gotoxy(66,25); cout<<"]";
				break;
			}
			case 5:{
				gotoxy(2,2);cout<<"[";
				gotoxy(4,2);cout<<"]";
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
bool iniciar_sesion(){
	CursorOff();
	//limpiar(1,135,5,32);
	imprimir_opciones();
	bool validacion = false,primero=false,loop=true,contra_si=false,existe=true;
	int pow=3,opcion=0,opcionx=0;
	string dato[2],valor[4];
	dato[0]="";
	do{
	pow=3;
	opcion = menu_sesion(5);
	switch(opcion){
		case 1:{
			borrar_nombre();
			//------------------------
			CursorOn(1,10);	
			fflush(stdin);
			gotoxy(37,9+pow);getline(cin,dato[0]);	
			CursorOff();
			//-----------------------
			primero=true;
			gotoxy(37,9+pow);cout<<dato[0];
			break;
		}
		case 2:{
			if(primero){
				Mercedes leer;
				Mercedes confirmar;
				leer=lista;
				confirmar=lista;
				//---------------------------------------------------------------
				while(confirmar!=NULL){
					if(dato[0] == confirmar->correo || dato[0]== confirmar->numero){
						contra_si=true;
					}
					confirmar=confirmar->sgte;
				}
				if(contra_si){
					limpiar_parcialmente();
					dibujarCuadro(32,2+pow,73,14+pow);//Cuadro sesion
					gotoxy(35,4+pow);cout<<"Iniciar sesion"; 
					gotoxy(35,6+pow);cout<<dato[0];
					gotoxy(35,8+pow);cout<<"Contrase"<<char(164)<<"a";
					dibujarCuadro(35,9+pow,70,11+pow);
					gotoxy(44,12+pow);cout<<"[Iniciar sesion]";
					//------------------------
					CursorOn(1,10);	
					fflush(stdin);
					gotoxy(37,10+pow);getline(cin,dato[1]);	
					CursorOff();
					//------------------------
					while(leer!=NULL){
						if(dato[0] == leer->correo || dato[0] == leer->numero){
							if(leer->contra == dato[1]){
								validacion=true;
								loop=false;
							}
						}
						leer=leer->sgte;
					}	
				}
				if(!validacion){
					gotoxy(37,13);cout<<"  //No se encontro el perfil   ";
					getch();
				}
				//---------------------------------------------------------------
				if(!validacion){
					imprimir_opciones();
				}			
			}else{
				gotoxy(37,12);cout<<"     //Ingrese los valores     ";
				getch();
			}
			gotoxy(37,12);cout<<"                               ";
			break;
		}
		case 3:{
			//Necesitas ayuda
			break;
		}
		case 4:{
			limpiar_parcialmente();
			CursorOff();
			pow=2;
			dibujarCuadro(32,3+pow,73,26+pow);//Cuadro sesion
			gotoxy(35,4+pow);cout<<"Crear Cuenta";
			 
			gotoxy(35,6+pow);cout<<"Tu nombre";
			dibujarCuadro(35,7+pow,70,9+pow);
			gotoxy(35,10+pow);cout<<"Correo electronico";
			dibujarCuadro(35,11+pow,70,13+pow);
			gotoxy(35,14+pow);cout<<"Contraseña";
			dibujarCuadro(35,15+pow,70,17+pow);
			gotoxy(35,18+pow);cout<<char(175)<<"Debe contener al menos 6 caracteres";
			gotoxy(35,20+pow);cout<<"Vuelve a escribir la contrase"<<char(164)<<"a";
			dibujarCuadro(35,21+pow,70,23+pow);
			gotoxy(39,24+pow);cout<<"[Crear tu cuenta de   AMG ]";
			bool continuar_atras =true;
			int option = 0;
			do{
				borrar_registrar();
				gotoxy(57,6);cout<<"             ";
				option=menu_crear_cnt(2);
				switch(option){
					case 1:{
						bool repet=false;
						do{
							borrar_registrar();
							//------------------------
							CursorOn(1,10);	
							fflush(stdin);
							gotoxy(37,8+pow);getline(cin,valor[0]);	
							gotoxy(37,12+pow);getline(cin,valor[1]);
							Mercedes repetir;
							repetir = lista;
							while(repetir!=NULL){
								if(valor[1]==repetir->correo){
									repet=true;	
								}
								repetir=repetir->sgte;
							}	
							gotoxy(37,16+pow);getline(cin,valor[2]);
							//valida contraseña	
							gotoxy(37,22+pow);getline(cin,valor[3]);	
							CursorOff();
							//------------------------
							if(!repet){
								if(valor[2]==valor[3]){
									registrar(lista,valor[0],valor[1],valor[2]);
									gotoxy(57,6);cout<<"Perfil creado";
									getch();
									existe=false;
								}								
							}else{
								gotoxy(50,6);cout<<"Usuario no disponible";
								getch();
							}
						}while(existe);
						break;
					}
					case 2:{
						continuar_atras=false;
						break;
					}
				}
			}while(continuar_atras);
			limpiar_parcialmente();
			imprimir_opciones();		
			break;
		}
		case 5:{
			dato[0]="";
			loop=false;
			validacion=false;
			break;
		}
	}
	}while(loop);
	return validacion;
}
void imprimir_opciones(){
	system("color F0");
	CursorOff();
	limpiar(1,135,5,32);
	dibujarCuadro(32,5,73,21);
	//---------------------------------------------------------------
	gotoxy(35,7);cout<<"Iniciar sesion"; 
	//---------------------------------------------------------------	
	gotoxy(35,9);cout<<"Direccion de correo electronico o"; 
	gotoxy(35,10);cout<<"numero de telefono movil";
	dibujarCuadro(35,11,70,13);
	//---------------------------------------------------------------
	gotoxy(48,14);cout<<"Continuar";
	//---------------------------------------------------------------
	gotoxy(35,16);cout<<"Al continuar,aceptas las condiciones";
	gotoxy(35,17);cout<<"y el Aviso de privacidad de AMG.";
	//---------------------------------------------------------------
	gotoxy(35,19);cout<<char(175)<<char(168)<<"Necesitas ayuda?";
	//---------------------------------------------------------------
	for(int i=0;i<36;i++){
		gotoxy(35+i,23);cout<<char(196);
	}
	gotoxy(43,23);cout<<char(168)<<" Eres nuevo en AMG?";
	dibujarCuadro(35,24,70,26);
	//---------------------------------------------------------------
	gotoxy(41,25);cout<<" Crear tu cuenta de AMG";
	//---------------------------------------------------------------
}

int proyecto2(int n){
	CursorOff();
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,65,3);//linea
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	creditos_imprimir();
	//--------------------------------
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_3();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void creditos(){
	bool repetidor=true;
	int opcion,n=1;
	do{
		opcion = proyecto2(n);
		switch(opcion){
			case 1:{
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}
void creditos_imprimir(){
	int posX=51,posY=10;
	cuadro(48,87,8,28);//Cuadro grande
	 
	gotoxy(posX,posY);   cout<<"   Erick Johan Perales Quispe";
	gotoxy(posX,posY+1); cout<<"       N00204989@upn.com"; 
	
	gotoxy(posX,posY+3); cout<<" Jailene Milagros García Candela";
	gotoxy(posX,posY+4); cout<<"       N00202965@upn.com";
	
	gotoxy(posX,posY+6); cout<<"  Samir Renzo Huamani Quispe";  
	gotoxy(posX,posY+7); cout<<"       N00166838@upn.com"; 
	   
	gotoxy(posX,posY+9); cout<<" Alvaro Sebastian Neciosup Rivera";   
	gotoxy(posX,posY+10);cout<<"       N00115103@upn.com";
	  
	gotoxy(posX,posY+12);cout<<"    Diego Alonso Diestra Vega"; 
	gotoxy(posX,posY+13);cout<<"       N00211342@gmail.com";
	
	gotoxy(posX,posY+15);cout<<" Carlos Alberto Alarcon Quijayte";  
	gotoxy(posX,posY+16);cout<<"       N00000000@gmail.com"; 
}

int proyecto(int n){
	CursorOff();
	limpiar(1,135,5,32);
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"P R U E B A";
	linea(8,22,3);//linea
	gotoxy(1,4);cout<<" ";
	gotoxy(5,4);cout<<" ";
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	cuadro(1,22,5,7);//Cuadro titulo
	cuadro(115,134,5,13);//Cuadro titulo
	cuadro(115,134,18,20);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	cuadro(1,46,8,11);//Cuadro titulo
	//Cambiar colores--------------------------------------------------------------------------
	color(252);
	mercedes();
	color(240);
	//Cambiar colores--------------------------------------------------------------------------
	amg();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_1();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(119,7);cout<<"Camiones";	
				break;
			}
			case 2:{
				color(252);
				gotoxy(119,9);cout<<"Choferes";	
				break;
			}
			case 3:{
				color(252);
				gotoxy(119,11);cout<<"Cargas";	
				break;
			}
			case 4:{
				color(252);
				gotoxy(2,9);cout<<"  Consulta Area Optima de carga del camion ";	
				break;
			}
			case 5:{
				color(252);
				gotoxy(2,10);cout<<"  Reporte de Entrega";	
				break;
			}
			case 6:{
				color(252);
				gotoxy(121,19);cout<<"Creditos";	
				break;
			}
			case 7:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void pantalla_principal(){
	bool repetidor=true;
	int opcion,n=7;
	do{
		opcion = proyecto(n);
		switch(opcion){
			case 1:{
				Menu_Camiones();
				break;
			}
			case 2:{
				Menu_chofer();
				break;
			}
			case 3:{
				Menu_Cargas();
				break;
			}
			case 4:{
				Menu_Area();
				break;
			}
			case 5:{
				mostrarListaEntregas(listaEntrega);
				break;
			}
			case 6:{
				creditos();
				break;
			}
			case 7:{
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}
//---------------------------------

int proyecto3(int n){
	CursorOff();
	system("cls");
	limpiar(1,135,5,32);
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,22,3);//linea
	gotoxy(1,4);cout<<" ";
	gotoxy(5,4);cout<<" ";
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	cuadro(1,24,6,13);//Cuadro titulo
	//Cambiar colores--------------------------------------------------------------------------
	color(252);
	mercedes();
	color(240);
	//Cambiar colores--------------------------------------------------------------------------
	amg();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_4();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(4,8);cout<<"Registrar Camiones";	
				break;
			}
			case 2:{
				color(252);
				gotoxy(4,9);cout<<"Mostrar Camiones";	
				break;
			}
			case 3:{
				color(252);
				gotoxy(4,10);cout<<"Buscar Camiones";
				break;
			}
			case 4:{
				color(252);
				gotoxy(4,11);cout<<"Modificar Camiones";
				break;
			}
			case 5:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void Menu_Camiones(){
	bool repetidor=true;
	int opcion,n=5;
	do{
		opcion = proyecto3(n);
		switch(opcion){
			case 1:{
				registro_camiones();
				break;
			}
			case 2:{
				camiones_almacenados();
				break;
			}
			case 3:{
				busqueda_camion();
				break;
			}
			case 4:{
				system("cls");
                int auxcodigo;
                cout<<"**MODIFICAR CAMIONES**"<<endl;
                cout<<"Codigo del Camion: ";
                cin>>auxcodigo;
                modificarListaCamion(listaCamion,auxcodigo);
				break;
			}
			case 5:{
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}
void registro_camiones(){
	system("cls");
	cout<<"***********Registro de camiones***********"<<endl<<endl;
    int codigo_C;
	string placa_C;
	cout<<"Codigo del Camion: ";
	cin>>codigo_C;
	cout<<"\nPlaca del camion: ";
	cin>>placa_C;
	insertarListaCamion(listaCamion, codigo_C, placa_C,indice);
	indice++;
	getch();	
}
void camiones_almacenados(){
	system("cls");
	cout<<"*****************CAMIONES ALMACENADOS*****************"<<endl;
	cout<<endl<<"---Codigo---                   "<<"----Placa"<<endl;
	ordenarListaCamion(listaCamion);
	mostrarListaCamion(listaCamion);	
}	
void busqueda_camion(){
	int buscar;
	NodoCamion *ss = new NodoCamion();
	system("cls");
	cout<<"***************Busqueda de camion*******************";	
	cout<<endl<<"Digite el codigo del camion a buscar: ";
	cin>>buscar;
	ss =busquedaBinariaCamion(listaCamion, buscar);
    if(ss!=NULL){
		cout<<"Camion con codigo "<<ss->Codigo_camion<<"encontrado con placa "<<ss->Placa_camion;
   		getch();
	}else{
        cout<<"\nEl codigo ingresado no exite....";
        getch();
    }		 
}


int proyecto4(int n){
	CursorOff();
	system("cls");
	limpiar(1,135,5,32);
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,22,3);//linea
	gotoxy(1,4);cout<<" ";
	gotoxy(5,4);cout<<" ";
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	cuadro(1,24,6,13);//Cuadro titulo
	//Cambiar colores--------------------------------------------------------------------------
	color(252);
	mercedes();
	color(240);
	//Cambiar colores--------------------------------------------------------------------------
	amg();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_5();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(4,8);cout<<"Registrar Choferes";	
				break;
			}
			case 2:{
				color(252);
				gotoxy(4,9);cout<<"Mostrar Choferes";	
				break;
			}
			case 3:{
				color(252);
				gotoxy(4,10);cout<<"Buscar Chofer";
				break;
			}
			case 4:{
				color(252);
				gotoxy(4,11);cout<<"Modificar Chofer";
				break;
			}
			case 5:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void Menu_chofer(){
	bool repetidor=true;
	int opcion,n=5;
	do{
		opcion = proyecto4(n);
		switch(opcion){
			case 1:{
				registrar_chofer();
				break;
			}
			case 2:{
				mostrar_chofer();
				break;
			}
			case 3:{
				buscarListaChoferes(listaTrabajador);
				break;
			}
			
			case 4:{
				system("cls");
                int auxtrabajador;
                cout<<"MODIFICAR TRABAJADOR"<<endl;
                cout<<"Codigo del Trabajador: ";
                   cin>>auxtrabajador;
                   modificarListaTRabajador(listaTrabajador,auxtrabajador);
				break;
			}
			case 5:{
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}
void registrar_chofer(){
	int auxCodTb;
	string auxNomTb, auxApellidoTb, auxcargo, auxusu, auxcontra;
	system("cls");
    cout<<"***********Registro de Trabajadores***********"<<endl<<endl;
    cout<<"\nCodigo del trabajador: ";
	cin>> auxCodTb;
	cout<<"\nNombre del trabajador ";
	cin>>auxNomTb;
	cout<<"\nApellido del trabajador: ";
	cin>>auxApellidoTb;
	cout<<"\nIngrese el cargo del trabajador: ";
	cin>>auxcargo;
	cout<<"\nIngrese el usuario del trabajador: ";
	cin>>auxusu;
	cout<<"\nIngresse la contraseña del trabajador: ";
	cin>>auxcontra;
    getch();
    insertarListaTrabajador(listaTrabajador, auxCodTb, auxNomTb, auxApellidoTb, auxcargo, auxusu, auxcontra);	
}
void mostrar_chofer(){
	
	system("cls");
	cout<<"*****************Choferes EN REGISTRO*****************"<<endl;
    cout<<endl<<"---Codigo---                   "<<"----Nombres y apellidos                   "<<"---Cargo---"<<endl;
				
	//	ordenarListaTrabajador(listaTrabajador);
	mostrarListaAdministrador(listaTrabajador);
	getch();
}


int proyecto5(int n){
	CursorOff();
	system("cls");
	limpiar(1,135,5,32);
	limpiar(1,135,5,32);
	color(240);
	system("color F0");
	//--------------------------------
	//SE ELIMINA CUANDO MEJOREN SU PARTE
	cuadro(0,135,0,33);//Cuadro grande
	cuadro(1,5,1,3); //Cuadro regresar
	cuadro(6,134,1,4);//Cuadro titulo
	gotoxy(9,2);cout<<"E M P R E S A  D E  T R A N S P O R T E  Y  C A R G A S";
	gotoxy(116,2);cout<<"GTR-MERCEDES/AMG";
	linea(8,22,3);//linea
	gotoxy(1,4);cout<<" ";
	gotoxy(5,4);cout<<" ";
	linea(2,5,4);//linea
	linea(1,135,32);//linea
	//--------------------------------
	cuadro(1,24,6,13);//Cuadro titulo
	//Cambiar colores--------------------------------------------------------------------------
	color(252);
	mercedes();
	color(240);
	//Cambiar colores--------------------------------------------------------------------------
	amg();
	int selec=1,tecla;
	bool repetidor=true;
	do{
		borrar_6();
		switch(selec){
			case 1:{
				color(252);
				gotoxy(4,8);cout<<"Registrar Cargar";	
				break;
			}
			case 2:{
				color(252);
				gotoxy(4,9);cout<<"Mostrar Cargas";	
				break;
			}
			case 3:{
				color(252);
				gotoxy(4,10);cout<<"Buscar Cargas";
				break;
			}
			case 4:{
				color(252);
				gotoxy(4,11);cout<<"Modificar Cargas";
				break;
			}
			case 5:{
				color(252);
				gotoxy(2,2);cout<<" < ";	
				break;
			}
		}
		do{
			tecla=getch();
			switch(tecla){
				case ARRIBA:{
					selec--;
					if(selec<1){
						selec=n;
					}
					break;
				}
				case ABAJO:{
					selec++;
					if(selec>n){
						selec=1;
					}
					break;
				}
				case ENTER:{
					repetidor=false;
					break;
				}
			}
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=ENTER);
	}while(repetidor);
    return selec;	
}
void Menu_Cargas(){
	bool repetidor=true;
	int opcion,n=5;
	do{
		opcion = proyecto5(n);
		switch(opcion){
			case 1:{
				registrar_cargas();
				break;
			}
			case 2:{
				mostrar_cargas();
				break;
			}
			case 3:{
				buscarCarga(listaCarga);
				break;
			}
			case 4:{
				system("cls");
                int auxcarga;
                cout<<"**MODIFICAR CARGA**"<<endl;
                cout<<"Codigo de la Carga: ";
                   cin>>auxcarga;
                   modificarListaCarga(listaCarga,auxcarga);
				break;
			}
			case 5:{
				repetidor=false;
				break;
			}
		}
	}while(repetidor);
}
void registrar_cargas(){
	int codCar;
	string contCar, destCar, estCar, horarioCar;
	double peso, costo;
	system("cls");
    cout<<"***********Registro de cargas***********"<<endl<<endl;
    cout<<"\nCodigo de la carga: ";
	cin>>codCar;
	cout<<"\nContenido de la carga: ";
	cin>>contCar;
	cout<<"\nDestino de la carga: ";
	cin>>destCar;
	cout<<"\nHorario de entrega: ";
	cin>>horarioCar;
	cout<<"\nPeso de la carga: ";
	cin>>peso;
	costo = peso *4.5;
	cout<<"\nEl costo de la carga seria "<<peso<<" x 4.5 = "<<costo<<endl;
	pagarCarga(costo);
	insertarListaCarga(listaCarga, codCar, contCar, destCar, "Cancelado", horarioCar,peso,costo);
	getch();
}
void mostrar_cargas(){
	system("cls");
    cout<<"*****************CARGAS ALMACENADOS*****************"<<endl;  
    cout<<endl<<"---Codigo---                    "<<"----Contenido---                     "<<"----Destino---                      "<<"----Estado---                    "<<"----Horario---              "<<endl;	
    ordenarListaCarga(listaCarga);
	mostrarListaCarga(listaCarga);
	getch();
}


void Menu_Area(){//metodo de la pared
	system("cls");
	color(240);
	struct combinacion{
	int m;
	int n;
	int resta;
	};

	int L,m,n;
	int tam,resta,cantidadM,cantidadN,restaOptimo,indice;
	cout<<"Ingrese el area total de la caja de carga del camion :  ";
	cin>>L;
	cout<<"Ingrese el area del producto mayor :  ";
    cin>>m;
    cout<<"Ingrese el area del producto menor:  ";
    cin>>n;
    tam=L/m;
    combinacion R[tam];
    
    resta=L;
    cantidadM=tam;
    cantidadN=0;
   
    for(int i=0; i<tam; i++){
    	resta=L-i*m;
    	R[i].m=i;
    	cantidadN=resta/n;
    	R[i].n=cantidadN;
    	resta-=cantidadN*n;
    	R[i].resta=resta;
  
    	
	}

	restaOptimo = R[tam-1].resta;
	indice = tam-1;
	for(int i=tam-1;i>=0;i--){
		if(R[i].resta<restaOptimo){ 
			indice=i;
			restaOptimo=R[i].resta;
		}
	}
	cout<<"\nValor optimo :  "<<endl;
	  cout<<"----------------------------"<<endl;
    cout<<"m \tn \tRESTA"<<endl;
        cout<<"----------------------------"<<endl;
        	cout<<R[indice].m<<"\t"<<R[indice].n<<"\t"<<R[indice].resta<<"\n";
    
	getch();

}

//Metodos para generacion aleatorios
void GenerarAleatorioCamion(){
	srand(time(NULL));
	int auxCodigoCamion;
	string auxPlacaCamion;
	for(int i= 0; i< ALEA; i++){
		string letras[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	    string numeros[9] ={"1","2","3","4","5","6","7","8","9"};
	  		
        auxCodigoCamion =1000+ rand()%(99999);
        auxPlacaCamion=letras[0+rand()%(26)] + letras[0+rand()%(25)] + letras[0+rand()%(25)] + "-"+numeros[0+rand()%(8)] + numeros[0+rand()%(8)] + numeros[0+rand()%(8)];
	    insertarListaCamion(listaCamion, auxCodigoCamion, auxPlacaCamion, indice);
	    indice++;
	}
	return;
}
void GenerarAleatorioTrabajador(){
	srand(time(NULL));
	int auxcodigo_Tb;
	string auxnombre, auxapellido, auxcargo,auxus,auxcontra;
	int cont = 0;
	for(int i = 0; i < ALEA ; i++){
		string nombres[10] = {"Alvaro", "Sebastian","Samir","Renzo","Carlos","Alberto","Diego","Alonso","Jailene","Milagros"};
        string apellidos[10] ={"Neciosup","Rivera","Huamani","Quispe","Diestra","Vega","Alarcon","Quijayte","Garcia","Candela"};
	    string cargos[3] = {"administrador", "chofer", "secretario"};
        string usuario[5] ={"mouse", "luffy", "eren", "flash", "superman"};
        string contra[4] = {"ferrari", "goku", "lima","peru"};
    		
        auxcodigo_Tb = 10000+ rand()%(99999);
        auxnombre = nombres[0+rand()%(10)] +" "+ nombres[0+rand()%(10)] ;
	    auxapellido = apellidos[0+rand()%(10)] + " " +apellidos[0+rand()%(10)];
	    auxcargo = cargos[0+rand()%(3)];
	    auxus = usuario[0+rand()%(4)];
	    auxcontra = contra[0+rand()%(3)];
	    if(auxcargo == "chofer"){
	    	choferes[cont] = auxcodigo_Tb;
	    	cont++;
		}
	    insertarListaTrabajador(listaTrabajador, auxcodigo_Tb, auxnombre, auxapellido, auxcargo, auxus, auxcontra);
	}
	
	
	return;
}
void GenerarAleatorioCarga(){
	srand(time(NULL));	
	int contA = 1;
	int auxcodigo_Car;
	int auxcod_ChE;
	string auxcod_CarE;
	string auxcontenido_Car, auxdestino_Car, auxestado_Car, auxhorario_Car;
	double auxPeso,auxCosto;
	for(int i = 0; i < ALEA ;i++){
		string contenido[8] = {"Carnes","Material de construccion","Telas","Frutas","Muebles","Agua","Autos","Animales"};
    	string destinos[10] ={"Trujillo","Lima","Cuzco","Cuzco","Arequipa","Madre de Dios","Loreto","Puno","Tumbes","Ica"};
    	string horas[24] ={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","00"};
    	string minutos[60]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59"};
		auxcodigo_Car =10000+ rand()%(99999); 
        auxcontenido_Car = contenido[0+rand()%(8)];
        auxdestino_Car = destinos[0+rand()%(10)];
        auxestado_Car = "No se entrego";
        auxhorario_Car = horas[0+rand()%(23)] + ":"+minutos[1+rand()%(60)];
        double decimal = 0+rand()%(58);
        auxPeso = 110+rand()%(1000) + (0.10*decimal);
        auxCosto = auxPeso*4.5;
        carga[i] = auxcodigo_Car;
        
        if(contA % 2 != 0){
        int codigo_Entrega = 10000+ rand()%(99999);

	    auxcod_ChE = 0;
	    do{
	     auxcod_ChE = choferes[0+rand()%(10)];
	    }while(auxcod_ChE == 0);
	    ostringstream o;
	  	o << auxcodigo_Car;
	  	auxcod_CarE = o.str();
	    
	    string *valores = aleatorioListaEntrega(listaTrabajador, auxcod_ChE);
	    if(insertarListaEntrega(listaEntrega, codigo_Entrega,*(valores+0), *(valores+1), auxcod_CarE, auxcontenido_Car, auxCosto,"Se entrego")){
	    	auxestado_Car = "Se entrego"; 	
		}		
		}
           
        insertarListaCarga(listaCarga, auxcodigo_Car, auxcontenido_Car, auxdestino_Car, auxestado_Car, auxhorario_Car,auxPeso,auxCosto);
        contA++;
	}
}
//----------------------------------
