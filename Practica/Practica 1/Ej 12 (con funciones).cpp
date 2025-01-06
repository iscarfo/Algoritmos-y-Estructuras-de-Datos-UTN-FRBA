//12.	 Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre= "FIN", 
//informar el nombre de la persona con mayor edad y el de la mas joven. Utilizar la función strcmp (<cstring>) para evaluar fin de datos.
#include<iostream>
#include<cstring>
using namespace std;

void informe ();

int main()
{
	
	informe();
	
	return 0;
}

void informe ()
{
	char nombre [50+1], nombreMay [50+1], nombreMen [50+1];
	int edad, edadMay,edadMen;
	cout<<"Inroduzca el nombre: ";
	cin>>nombre;
	while(strcmp(nombre,"FIN")!=0)
	{
		cout<<"Indique la edad: ";
		cin>>edad;
		if(edad<edadMay)
		{
			edadMay=edad;
			strcpy(nombreMay,nombre);
		}
		else if (edad>edadMen)
		{
			edadMen=edad;
			strcpy(nombreMen,nombre);
		}
		cout<<"Indique el nombre: ";
		cin>>nombre;
	}
	
}
