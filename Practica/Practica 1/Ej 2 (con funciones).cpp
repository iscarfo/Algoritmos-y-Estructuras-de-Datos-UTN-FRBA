//2.	Dado un numero entero de la forma (AAAAMMDD), que representa una fecha valida mostrar el dia, mes y año que representa 
#include<iostream>
using namespace std;

void convertir (int);

int main()
{
	int fecha;
	cout<<"Indique una fecha de la forma AAAAMMDD: ";
	cin>>fecha;
	convertir(fecha);
	
	return 0;
}

void convertir (int fecha)
{
	int dia,mes,anio;
	
	dia = fecha % 100; fecha /= 100;
	mes = fecha % 100; fecha /= 100;
	anio = fecha % 10000; fecha /= 10000;
	
	cout<<"Tu numero representa a la siguiente fecha: (dia): "<<dia<<" / (mes): "<<mes<<" / (anio): "<<anio;
}
