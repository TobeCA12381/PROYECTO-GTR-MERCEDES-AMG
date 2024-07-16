//1°Funciones extra para el diseño del codigo
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int color(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
void CursorOff(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void CursorOn(bool visible, DWORD size){
	if(size == 0){
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

//------------------------------------------------------------------
void limpiar(int x1,int x2,int y1,int y2){
	int i,j;
	for(i=y1;i<y2;i++){//y
		for(j=x1;j<x2;j++){//x
			gotoxy(j,i); printf(" ");
		}
	}	
}
void cuadro(int x1,int x2,int y1,int y2){
    int i;
    for (i=x1;i<x2;i++)
    {
	gotoxy(i,y1);printf("Ä") ;//linea horizontal superior
	gotoxy(i,y2);printf("Ä") ;//linea horizontal inferior
    }

    for (i=y1;i<y2;i++)
    {
	gotoxy(x1,i);printf("³") ;//linea vertical izquierda
	gotoxy(x2,i);printf("³") ;//linea vertical derecha
    }
    gotoxy(x1,y1);printf("Ú");
    gotoxy(x1,y2);printf("À");
    gotoxy(x2,y1);printf("¿");
    gotoxy(x2,y2);printf("Ù");
}
void linea(int x1,int x2,int y){
	int i;
	for (i=x1;i<x2;i++){
	gotoxy(i,y);printf("Ä") ;//linea horizontal superior
    }
}
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++)
    {
	gotoxy(i,y1);printf("Ä") ;//linea horizontal superior
	gotoxy(i,y2);printf("Ä") ;//linea horizontal inferior
    }

    for (i=y1;i<y2;i++)
    {
	gotoxy(x1,i);printf("³") ;//linea vertical izquierda
	gotoxy(x2,i);printf("³") ;//linea vertical derecha
    }
    gotoxy(x1,y1);printf("Ú");
    gotoxy(x1,y2);printf("À");
    gotoxy(x2,y1);printf("¿");
    gotoxy(x2,y2);printf("Ù");
}
//------------------------------------------------------------------
void borrar_principal(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(2,6);cout<<" Hola, Identificate ";
	gotoxy(121,30);cout<<"Creditos";	
}
void borrar_1(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(119,7);cout<<"Camiones";
	gotoxy(119,9);cout<<"Choferes";
	gotoxy(119,11);cout<<"Cargas";	
	gotoxy(121,19);cout<<"Creditos";
	
	gotoxy(2,9);cout<<"  Consulta Area Optima de carga del camion ";
	gotoxy(2,10);cout<<"  Reporte de Entrega";
		
}
void borrar_2(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(119,7);cout<<"Registrar";
	gotoxy(119,9);cout<<"Mostrar";
	gotoxy(119,11);cout<<"Buscar";
}
void borrar_3(){
	color(240);
	gotoxy(2,2);cout<<" < ";
}
void borrar_4(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(4,8);cout<<"Registrar Camiones";	
	gotoxy(4,9);cout<<"Mostrar Camiones";
	gotoxy(4,10);cout<<"Buscar Camiones";
	gotoxy(4,11);cout<<"Modificar Camiones";
}
void borrar_5(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(4,8);cout<<"Registrar Choferes";	
	gotoxy(4,9);cout<<"Mostrar Choferes";
	gotoxy(4,10);cout<<"Buscar Chofer";
	gotoxy(4,11);cout<<"Modificar Chofer";
}
void borrar_6(){
	color(240);
	gotoxy(2,2);cout<<" < ";
	gotoxy(4,8);cout<<"Registrar Cargas";	
	gotoxy(4,9);cout<<"Mostrar Cargas";
	gotoxy(4,10);cout<<"Buscar Cargas";
	gotoxy(4,11);cout<<"Modificar Cargas";
}

