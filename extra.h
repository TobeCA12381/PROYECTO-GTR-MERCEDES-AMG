//1°Funciones extra para el diseño del codigo
//-------------------------------------------
void limpiar_parcialmente(){
	system("color F0");
	int i,j;
	for(i=5;i<29;i++){ //y
		for(j=2;j<103;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void limpiar_w(){
	system("color F0");
	int i,j;
	for(i=3;i<29;i++){ //y
		for(j=2;j<108;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void limpiar_parcialmente_mitad(){
	color(244);
	int i,j;
	for(i=7;i<26;i++){ //y
		for(j=2;j<103;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void borrar_registrar(){
	gotoxy(37,10); cout<<"                                 ";
	gotoxy(37,14); cout<<"                                 ";
	gotoxy(37,18); cout<<"                                 ";
	gotoxy(37,24); cout<<"                                 ";
}
void borrar_cls(){
				gotoxy(80,2);  cout<<" ";
				gotoxy(99,2); cout<<" ";
				gotoxy(4,27);cout<<" ";
				gotoxy(13,27);cout<<" ";	
}
void borar_opciones_sesion(){
	gotoxy(34,7);  cout<<" ";
	gotoxy(49,7);  cout<<" ";
	gotoxy(34,19); cout<<" ";
	gotoxy(53,19); cout<<" ";
	gotoxy(40,25); cout<<" ";
	gotoxy(66,25); cout<<" ";
	gotoxy(47,14); cout<<" ";
	gotoxy(57,14); cout<<" ";
				gotoxy(2,2);cout<<" ";
				gotoxy(4,2);cout<<" ";
}
void borar_opciones_tocs(){
	gotoxy(5,5);  cout<<" ";
	gotoxy(23,5); cout<<" ";
	gotoxy(35,5); cout<<" ";
	gotoxy(43,5); cout<<" ";	
	gotoxy(57,5); cout<<" ";
	gotoxy(71,5); cout<<" ";	
	gotoxy(81,5); cout<<" ";
	gotoxy(97,5); cout<<" ";
	gotoxy(3,27); cout<<" ";
	gotoxy(12,27);cout<<" ";
}
void borar_crearx(){
	gotoxy(34,6); cout<<" ";
	gotoxy(47,6); cout<<" ";
				gotoxy(2,2);cout<<" ";
				gotoxy(4,2);cout<<" ";
}
void borar_opciones_edit(){
	gotoxy(41,11); cout<<" ";
	gotoxy(48,11); cout<<" ";
	
	gotoxy(41,14); cout<<" ";
	gotoxy(48,14); cout<<" ";
	
	gotoxy(41,17); cout<<" ";
	gotoxy(48,17); cout<<" ";
	
	gotoxy(41,20); cout<<" ";
	gotoxy(48,20); cout<<" ";
	
	gotoxy(3,27);  cout<<" ";
	gotoxy(12,27); cout<<" ";
}
void borar_elim(){
	gotoxy(64,16); cout<<" ";
	gotoxy(67,16); cout<<" ";
	gotoxy(64,17); cout<<" ";
	gotoxy(67,17); cout<<" ";
	
	gotoxy(3,27);  cout<<" ";
	gotoxy(12,27); cout<<" ";
}
void borrar_nombre(){
	gotoxy(37,12);cout<<"                                 ";
}

void limpiar_parw(){
	color(244);
	int i,j;
	for(i=10;i<29;i++){ //y
		for(j=2;j<103;j++){  //x
			gotoxy(j,i); printf("A");
			}
	}
}


void borrar_to_categorias(){
	color(244);
	gotoxy(5,5);   cout<<" ";
	gotoxy(18,5);  cout<<" ";
			
	gotoxy(33,5);  cout<<" ";
	gotoxy(44,5);  cout<<" ";
		
	gotoxy(55,5);cout<<" ";
	gotoxy(65,5);cout<<" ";
			        
	gotoxy(80,5);cout<<" ";
	gotoxy(96,5);cout<<" ";
				    
	gotoxy(6,8);cout<<" ";
	gotoxy(18,8);cout<<" ";
			        
	gotoxy(32,8);cout<<" ";
	gotoxy(40,8);cout<<" ";
			       	
	gotoxy(78,27);cout<<" ";
	gotoxy(101,27);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";
	
		
}

/////////////////////////// WENDEL ////////////////////////////////


void borrar_categorias1(){	
	gotoxy(3,5);   cout<<" ";
	gotoxy(28,5);  cout<<" ";
			
	gotoxy(31,5);  cout<<" ";
	gotoxy(55,5);  cout<<" ";
		
	gotoxy(58,5);cout<<" ";
	gotoxy(80,5);cout<<" ";
			        
	gotoxy(83,5);cout<<" ";
	gotoxy(94,5);cout<<" ";
				    
	gotoxy(3,8);cout<<" ";
	gotoxy(31,8);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";	
}

void borrar_categorias2(){	
	gotoxy(3,5);   cout<<" ";
	gotoxy(12,5);  cout<<" ";
			
	gotoxy(16,5);  cout<<" ";
	gotoxy(24,5);  cout<<" ";
		
	gotoxy(28,5);cout<<" ";
	gotoxy(40,5);cout<<" ";
			        
	gotoxy(44,5);cout<<" ";
	gotoxy(61,5);cout<<" ";
				    
	gotoxy(65,5);cout<<" ";
	gotoxy(86,5);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";	
}

void borrar_categorias3(){	
	gotoxy(3,5);   cout<<" ";
	gotoxy(25,5);  cout<<" ";
			
	gotoxy(29,5);  cout<<" ";
	gotoxy(47,5);  cout<<" ";
		
	gotoxy(51,5);cout<<" ";
	gotoxy(71,5);cout<<" ";
			        
	gotoxy(75,5);cout<<" ";
	gotoxy(99,5);cout<<" ";
				    
	gotoxy(3,8);cout<<" ";
	gotoxy(10,8);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";	
}

void borrar_categorias4(){
	gotoxy(3,5);   cout<<" ";
	gotoxy(28,5);  cout<<" ";
			
	gotoxy(31,5);  cout<<" ";
	gotoxy(52,5);  cout<<" ";
		
	gotoxy(56,5);cout<<" ";
	gotoxy(79,5);cout<<" ";
			        
	gotoxy(83,5);cout<<" ";
	gotoxy(93,5);cout<<" ";
				    
	gotoxy(3,8);cout<<" ";
	gotoxy(27,8);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";	
}

void borrar_categorias5(){	
	gotoxy(3,5);   cout<<" ";
	gotoxy(17,5);  cout<<" ";
			
	gotoxy(21,5);  cout<<" ";
	gotoxy(30,5);  cout<<" ";
		
	gotoxy(34,5);cout<<" ";
	gotoxy(38,5);cout<<" ";
			        
	gotoxy(42,5);cout<<" ";
	gotoxy(45,5);cout<<" ";
				    
	gotoxy(49,5);cout<<" ";
	gotoxy(65,5);cout<<" ";
				
	gotoxy(5,27);cout<<" ";
	gotoxy(11,27);cout<<" ";	
}


void limpiar_perfiles(){
	int i,j;
	for(i=6;i<=19;i++){ //y
		for(j=2;j<=81;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void limpiar_opciones(){
	int i;
	for(i=5;i<=19;i++){ //y
		gotoxy(8,i); cout<<"  ";
	}
}
void limpiar_opciones_ord(){
	gotoxy(6,17); cout<<"  ";
	gotoxy(6,18); cout<<"  ";
	gotoxy(6,19); cout<<"  ";
}
void limpiar_valores(){
	int i,j;
	for(i=4;i<=15;i++){
		gotoxy(14,i); printf("      ");
		gotoxy(35,i); printf("   ");
		gotoxy(54,i); printf("      ");
		gotoxy(75,i); printf("   ");
	}
}
void limpiar_tar_ord(){
	gotoxy(6,4); cout<<"  ";
	gotoxy(6,5); cout<<"  ";
	gotoxy(6,6); cout<<"  ";
}
void limpiar_valores_tar(){
	int i,j;
	for(i=10;i<=18;i++){ //y
		for(j=10;j<=74;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void limpiar_xtr(){
	int i,j;
	for(i=17;i<=19;i++){ //y
		for(j=2;j<=81;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
//-------------------------
void limpiar_wko(){
	int i,j;
	for(i=9;i<=17;i++){ //y
		for(j=12;j<=71;j++){  //x
			gotoxy(j,i); printf(" ");
			}
	}
}
void limpiar_1457(){
	gotoxy(32,5);
	cout<<"            ";
	gotoxy(32,6);
	cout<<"            ";
	gotoxy(54,19);
	cout<<" ";
}
