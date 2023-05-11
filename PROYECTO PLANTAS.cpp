#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
using namespace std;

void apariencia();
void gotoxy(int,int);
void cuadro(int,int,int,int);
void cuadrod(int,int,int,int);
void flor();
int convierte(string);
void menu();
void menu_busqueda();
string reemplazo(string);
string devuelta(string);
string minuscula(string);

class planta{
	public: 
		string nombre;
		string tipo;
		string propiedades;
		string usos;
		
	public:
		void rellenar_datos();
		void busqueda_nombre();
		void actualizar_nombre();
		void eliminar_nombre();
		void ver_plantas();
};

void planta :: rellenar_datos(){
	ofstream archivo;
	archivo.open("datos.txt",ios::app|ios::out);
	if (archivo.fail()){
		exit(1);
	}
	else{
		gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA:"<<endl; 
		gotoxy(2,9); cout<<"TIPO DE PLANTA: "<<endl;
		gotoxy(2,11); cout<<"PROPIEDAD DE LA PLANTA: "<<endl;
		gotoxy(2,13); cout<<"USO DE LA PLANTA: "<<endl;
		gotoxy(30,7); cout<<">>"; 
		gotoxy(30,9); cout<<">>"; 
		gotoxy(30,11); cout<<">>"; 
		gotoxy(30,13); cout<<">>"; 
		fflush(stdin);
		gotoxy(35,7); getline(cin,nombre);
		gotoxy(35,9); getline(cin,tipo);
		gotoxy(35,11); getline(cin,propiedades);
		gotoxy(35,13); getline(cin,usos);
		archivo<<reemplazo(nombre)<<"\n";
		archivo<<reemplazo(tipo)<<"\n";
		archivo<<reemplazo(propiedades)<<"\n";
		archivo<<reemplazo(usos)<<"\n\n";
		flor();
		gotoxy(30,23); system("PAUSE>NUL");
	}
	archivo.close();
};

void planta :: busqueda_nombre(){
	fflush(stdin);
	bool aux=false;
	ifstream archivo;
	string nombre_b;
	string nombre_a;
	archivo.open("datos.txt",ios::in);
	if (archivo.fail()){
		exit(1);
	}
	else{
		gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA A BUSCAR: ";getline(cin,nombre_b);
		
		archivo>>nombre;
	
		while(!archivo.eof()){
			if ( minuscula(devuelta(nombre)) == minuscula(nombre_b)){
				system("cls");
				apariencia();
				gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA:";gotoxy(35,7); cout<<">> "<<devuelta(nombre);
				archivo>>tipo;
				gotoxy(2,9); cout<<"TIPO DE PLANTA: ";gotoxy(35,9); cout<<">> "<<devuelta(tipo);
				archivo>>propiedades;
				gotoxy(2,11); cout<<"PROPIEDAD DE LA PLANTA: ";gotoxy(35,11); cout<<">> "<<devuelta(propiedades);
				archivo>>usos;
				gotoxy(2,13); cout<<"USO DE LA PLANTA: ";gotoxy(35,13); cout<<">> "<<devuelta(usos);
				aux=true;
				gotoxy(30,23); system("PAUSE");
				break;
			}
			archivo>>nombre;
		}
		if (aux==false){
			system("cls");
			apariencia();
			gotoxy(26,14); cout<<"NO SE ENCONTRO ESA PLANTA."<<endl;
			gotoxy(22,23); system("PAUSE");
		}
	}
	archivo.close();
};

void planta :: actualizar_nombre(){
	fflush(stdin);
	int opcion;
	bool aux=false;
	string nombre_aux;
	ifstream archivo;
	archivo.open("datos.txt",ios::in);
	ofstream archivo_aux("temp.txt",ios::out);
	if (archivo.fail()){
		exit(1);
	}
	else{
		gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA A ACTUALIZAR: ";getline(cin,nombre_aux);
		archivo>>nombre;
		while(!archivo.eof()){
			archivo>>tipo;
			archivo>>propiedades;
			archivo>>usos;
			if (minuscula(devuelta(nombre)) == minuscula(nombre_aux)){
				system("cls");
				apariencia();
				gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA:";gotoxy(35,7); cout<<">> "<<devuelta(nombre)<<endl;
				archivo>>tipo;
				gotoxy(2,9); cout<<"TIPO DE PLANTA: ";gotoxy(35,9); cout<<">> "<<devuelta(tipo)<<endl;
				archivo>>propiedades;
				gotoxy(2,11); cout<<"PROPIEDAD DE LA PLANTA: ";gotoxy(35,11); cout<<">> "<<devuelta(propiedades)<<endl;
				archivo>>usos;
				gotoxy(2,13); cout<<"USO DE LA PLANTA: ";gotoxy(35,13); cout<<">> "<<devuelta(usos)<<endl;
				archivo>>nombre;
				gotoxy(2,23); system("PAUSE");			
				system("cls");
				apariencia();
				gotoxy(2,7); cout<<"NUEVO NOMBRE DE LA PLANTA:";
				gotoxy(30,7); cout<<">> ";
				fflush(stdin);
				gotoxy(35,7); getline(cin,nombre_aux);
				archivo_aux<<reemplazo(nombre_aux)<<"\n"<<tipo<<"\n"<<propiedades<<"\n"<<usos<<"\n\n";
				gotoxy(2,23); system("PAUSE");
				aux=true;			
			}
			else{
				archivo_aux<<nombre<<"\n"<<tipo<<"\n"<<propiedades<<"\n"<<usos<<"\n\n";
			}
			archivo>>nombre;
		}
		if(aux==false){
			system("cls");
			apariencia();
			gotoxy(26,14); cout<<"NO SE ENCONTRO ESA PLANTA."<<endl;
			gotoxy(22,23); system("PAUSE");
		}
		archivo.close();
		archivo_aux.close();
		remove("datos.txt");
		rename("temp.txt","datos.txt");
	}
};

void planta :: eliminar_nombre(){
	fflush(stdin);
	bool aux=false;
	ifstream archivo;
	string nombre_aux;
	archivo.open("datos.txt",ios::in);
	ofstream archivo_aux("temp.txt",ios::out);
	if (archivo.fail()){
		exit(1);
	}
	else{
		gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA A ELIMINAR: ";getline(cin,nombre_aux);
		archivo>>nombre;
		while(!archivo.eof()){
			archivo>>tipo;
			archivo>>propiedades;
			archivo>>usos;
			if (minuscula(devuelta(nombre)) == minuscula(nombre_aux)){
				system("cls");
				apariencia();
				archivo>>tipo;
				archivo>>propiedades;
				archivo>>usos;
				gotoxy(19,14); cout<<"SE HA ELIMINADO ESA PLANTA CORRECTAMENTE."<<endl;
				gotoxy(2,23); system("PAUSE");
				aux=true;			
			}
			else{
				archivo_aux<<nombre<<"\n"<<tipo<<"\n"<<propiedades<<"\n"<<usos<<"\n\n";
			}
			archivo>>nombre;
		}
		if(aux==false){
			system("cls");
			apariencia();
			gotoxy(26,14); cout<<"NO SE ENCONTRO ESA PLANTA."<<endl;
			gotoxy(22,23); system("PAUSE");
		}
		archivo.close();
		archivo_aux.close();
		remove("datos.txt");
		rename("temp.txt","datos.txt");
	}
};

void planta :: ver_plantas(){
	ifstream archivo;
	int contador = 1;
	archivo.open("datos.txt",ios::in);
	if (archivo.fail()){
		exit(1);
	}
	else{
		archivo>>nombre;
		while(!archivo.eof()){
			fflush(stdin);
			system("cls");
			apariencia();
			gotoxy(2,7); cout<<"NOMBRE DE LA PLANTA:";gotoxy(35,7); cout<<">> "<<devuelta(nombre)<<endl;
			archivo>>tipo;
			gotoxy(2,9); cout<<"TIPO DE PLANTA: ";gotoxy(35,9); cout<<">> "<<devuelta(tipo)<<endl;
			archivo>>propiedades;	
			gotoxy(2,11); cout<<"PROPIEDAD DE LA PLANTA: ";gotoxy(35,11); cout<<">> "<<devuelta(propiedades)<<endl;
			archivo>>usos;
			gotoxy(2,13); cout<<"USO DE LA PLANTA: ";gotoxy(35,13); cout<<">> "<<devuelta(usos)<<endl;
			gotoxy(68,23); cout<<"PLANTA "<<contador<<endl;
			gotoxy(2,23); system("PAUSE");
			archivo>>nombre;
			contador++;
		}
		system("cls");
		apariencia();
		gotoxy(21,14); cout<<"NO HAY MAS PLANTAS PARA MOSTRAR..."<<endl;
		gotoxy(2,23); system("PAUSE");
		archivo.close();
	}
};

int main(){
	system("mode con: cols=80 lines=25");
	system("COLOR 80");
	cuadrod(0,0,78,24);
	cuadrod(1,1,77,3);
	system("cls");
	apariencia();
	Sleep(30);
	gotoxy(30,14); cout<<"SISTEMA INICIADO..."<<endl;
	gotoxy(27,15); cout<<"PRESIONE CUALQUIER TECLA";
	system("PAUSE>NUL");
	Sleep(30);
	menu();
	gotoxy(2,23); system("PAUSE>NULL");
	gotoxy(9,16); return 0;
}

void apariencia(){
	system("mode con: cols=80 lines=25");
	system("COLOR 80");
	cuadro(0,0,78,24);
	cuadro(1,1,77,3);
	gotoxy(28,2); cout<<"P L A N T   S T O R A G E"<<endl;
	gotoxy(5,5); cout<<"ALMACEN DE PLANTA"<<endl;
}

void gotoxy(int x, int y){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}

void cuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}

void cuadrod(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
    	Sleep(20);
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
    	Sleep(20);
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
    
    gotoxy(29,14); cout<<"SISTEMA INICIANDO...";
    
}

int convierte(string valor){
	int n = atoi(valor.c_str());
	return n;
}

void menu(){
	
	planta plantas;
	string op;
	int opcion;
	
	do{
		
		apariencia();
		gotoxy(2,7); cout<<"1 <> REGISTRAR UNA PLANTA."<<endl;
		gotoxy(2,9); cout<<"2 <> BUSCAR UNA PLANTA POR NOMBRE."<<endl;
		gotoxy(2,11); cout<<"3 <> ACTUALIZAR NOMBRE DE UNA PLANTA."<<endl;
		gotoxy(2,13); cout<<"4 <> ELIMINAR UNA PLANTA."<<endl;
		gotoxy(2,15); cout<<"5 <> VER PLANTAS ALMACENADAS."<<endl;
		gotoxy(2,17); cout<<"6 <> SALIR."<<endl;
		gotoxy(2,23); cout<<"RESPUESTA (NUMERO) : "; 
		fflush(stdin);
		gotoxy(23,23);getline(cin,op);
		
		while(!isdigit(op[0])){
			fflush(stdin);
			gotoxy(35,23); cout<<"NO ES UN NUMERO.";
			gotoxy(23,23); getline(cin,op);
		}
		
		opcion = convierte(op);
		
		switch(opcion){
			
			case 1:
				system("cls");
				apariencia();
				plantas.rellenar_datos();
				break;
			case 2:
				system("cls");
				apariencia();
				plantas.busqueda_nombre();
				break;
			case 3:
				system("cls");
				apariencia();
				plantas.actualizar_nombre();
				break;
			case 4:
				system("cls");
				apariencia();
				plantas.eliminar_nombre();
				break;
			case 5:
				system("cls");
				apariencia();
				plantas.ver_plantas();
				break;
			case 6:
				exit(1);
				break;		
		}
	}while(opcion!=6);
}

string reemplazo(string cadena){
	string b=" ";
	string c="_";
	int i=0;
	while(i==0){
		string::size_type pos=cadena.find(b,0);
		if (pos==string::npos){
			break;
		}
		else{
			cadena.replace(pos,1,c);
		}
	}
	return cadena;
}

string devuelta(string cadena){
	string b=" ";
	string c="_";
	int i=0;
	while(i==0){
		string::size_type pos=cadena.find(c,0);
		if (pos==string::npos){
			break;
		}
		else{
			cadena.replace(pos,1,b);
		}
	}
	return cadena;
}

string minuscula(string cadena){
	for (int i = 0; i < cadena.length(); i++) 
		cadena[i] = tolower(cadena[i]);
	return cadena;
}

void flor(){
	apariencia();
	string w="h";
	w[0]=w[0]+115;
	
	Sleep(75);
	gotoxy(38,23); cout<<w;
	Sleep(75);
	gotoxy(38,22); cout<<w;
	Sleep(75);
	gotoxy(37,21); cout<<w;
	gotoxy(38,21); cout<<w;
	Sleep(75);
	gotoxy(35,20); cout<<w;
	gotoxy(36,20); cout<<w;
	gotoxy(38,20); cout<<w;
	gotoxy(39,20); cout<<w;
	gotoxy(41,20); cout<<w;
	Sleep(75);
	gotoxy(35,19); cout<<w;
	gotoxy(39,19); cout<<w;
	Sleep(75);
	gotoxy(33,18); cout<<w;
	gotoxy(34,18); cout<<w;
	gotoxy(38,18); cout<<w;
	gotoxy(40,18); cout<<w;
	Sleep(75);
	gotoxy(37,17); cout<<w;
	gotoxy(38,17); cout<<w;
	Sleep(75);
	gotoxy(37,16); cout<<w;
	gotoxy(39,16); cout<<w;
	Sleep(75);
	gotoxy(36,15); cout<<w;
	gotoxy(40,15); cout<<w;
	gotoxy(41,15); cout<<w;
	Sleep(75);
	gotoxy(34,14); cout<<w;
	gotoxy(35,14); cout<<w;
	gotoxy(43,14); cout<<w;
	gotoxy(44,14); cout<<w;
	gotoxy(32,13); cout<<w;
	gotoxy(33,13); cout<<w;
	gotoxy(34,13); cout<<w;
	gotoxy(35,13); cout<<w;
	gotoxy(36,13); cout<<w;
	gotoxy(37,13); cout<<w;
	gotoxy(38,13); cout<<w;
	gotoxy(39,13); cout<<w;
	gotoxy(46,13); cout<<w;
	Sleep(75);
	gotoxy(31,12); cout<<w;
	gotoxy(32,12); cout<<w;
	gotoxy(33,12); cout<<w;
	gotoxy(34,12); cout<<w;
	gotoxy(35,12); cout<<w;
	gotoxy(36,12); cout<<w;
	gotoxy(42,12); cout<<w;
	gotoxy(47,12); cout<<w;
	Sleep(75);
	gotoxy(29,11); cout<<w;
	gotoxy(30,11); cout<<w;
	gotoxy(31,11); cout<<w;
	gotoxy(32,11); cout<<w;
	gotoxy(33,11); cout<<w;
	gotoxy(34,11); cout<<w;
	gotoxy(41,11); cout<<w;
	gotoxy(48,11); cout<<w;
	Sleep(75);
	gotoxy(29,10); cout<<w;
	gotoxy(30,10); cout<<w;
	gotoxy(31,10); cout<<w;
	gotoxy(32,10); cout<<w;
	gotoxy(33,10); cout<<w;
	gotoxy(41,10); cout<<w;
	gotoxy(48,10); cout<<w;
	Sleep(75);
	gotoxy(29,9); cout<<w;
	gotoxy(30,9); cout<<w;
	gotoxy(31,9); cout<<w;
	gotoxy(32,9); cout<<w;
	gotoxy(33,9); cout<<w;
	gotoxy(41,9); cout<<w;
	gotoxy(42,9); cout<<w;
	gotoxy(47,9); cout<<w;
	gotoxy(49,9); cout<<w;
	gotoxy(50,9); cout<<w;
	Sleep(75);
	gotoxy(31,8); cout<<w;
	gotoxy(32,8); cout<<w;
	gotoxy(33,8); cout<<w;
	gotoxy(34,8); cout<<w;
	gotoxy(35,8); cout<<w;
	gotoxy(42,8); cout<<w;
	gotoxy(43,8); cout<<w;
	gotoxy(45,8); cout<<w;
	gotoxy(47,8); cout<<w;
	gotoxy(50,8); cout<<w;
	gotoxy(51,8); cout<<w;
	Sleep(75);
	gotoxy(32,7); cout<<w;
	gotoxy(33,7); cout<<w;
	gotoxy(34,7); cout<<w;
	gotoxy(35,7); cout<<w;
	gotoxy(41,7); cout<<w;
	gotoxy(42,7); cout<<w;
	gotoxy(46,7); cout<<w;
	gotoxy(48,7); cout<<w;
	gotoxy(50,7); cout<<w;
	Sleep(75);
	gotoxy(33,6); cout<<w;
	gotoxy(34,6); cout<<w;
	gotoxy(35,6); cout<<w;
	gotoxy(37,6); cout<<w;
	gotoxy(40,6); cout<<w;
	gotoxy(46,6); cout<<w;
	gotoxy(49,6); cout<<w;
	Sleep(75);
	gotoxy(34,5); cout<<w;
	gotoxy(35,5); cout<<w;
	gotoxy(39,5); cout<<w;
	gotoxy(40,5); cout<<w;
	gotoxy(47,5); cout<<w;
	gotoxy(44,5); cout<<w;
	Sleep(75);
	gotoxy(32,4); cout<<w;
	gotoxy(33,4); cout<<w;
	gotoxy(34,4); cout<<w;
	gotoxy(37,4); cout<<w;
	gotoxy(39,4); cout<<w;
	gotoxy(40,4); cout<<w;
	gotoxy(41,4); cout<<w;
	gotoxy(42,4); cout<<w;
	Sleep(75);
	gotoxy(11,18); cout<<"P L A N T A";
	gotoxy(50,18); cout<<"R E G I S T R A D A";
}