/*12.	Dados los siguientes registros crear un vector de 20 posiciones sin orden. Para el caso a imprimir:
a. La posición 8 del vector, campo dia
b. La posición 0 del vector campo nombre*/
#include<iostream>
using namespace std;

struct fecha
{
	int anio;
	int mes;
	int dia;
};

struct vector
{
	char nombre[20+1];
	fecha fechaNacimiento;
};

void rellenarVector(vector[20]);

int main()
{
	vector v[20];
	rellenarVector(v);
	cout<<v[8].fechaNacimiento.dia;
	cout<<v[0].nombre;
	
	return 0;
}

void rellenarVector(vector v[20])
{
	for(int i=0;i<20;i++)
	{
		cout<<"Indique su nombre: ";
		cin>>v[i].nombre;
		cout<<"Indique su fecha de nacimiento: "<<endl;
		cout<<"Dia: "; cin>>v[i].fechaNacimiento.dia;
		cout<<"Mes: "; cin>>v[i].fechaNacimiento.mes;
		cout<<"Anio: "; cin>>v[i].fechaNacimiento.anio;
	}
}
