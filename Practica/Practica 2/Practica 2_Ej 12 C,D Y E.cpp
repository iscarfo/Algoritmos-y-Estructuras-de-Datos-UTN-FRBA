/*12.	Dados los siguientes registros crear un vector de 20 posiciones sin orden. Para el caso a imprimir:
c. La posición del LEGAJO 456789 y sus calificaciones
d. La posición del primer apellido "xxxxx", el legajo, el nombre y las notas, para lo cual se le pide que programe una función.
e. considere que el vector se encuentra ordenado, utilice la función de búsqueda binaria para encontrar el legajo del punto c, utilice los parámetros correctamente.*/
#include<iostream>
#include<cstring>
using namespace std;

struct ApellidoNombre
{
	char nombre[20+1];
	char apellido[20+1];
	
};

struct nota
{
	int nota1;
	int nota2;
	int nota3;
};

struct alumno
{
	ApellidoNombre fecha;
	int legajo;
	nota calificaciones;
};

void rellenarVector(alumno[]);
void puntoC(alumno[]);
void puntoD(alumno[]);

int main()
{
	alumno curso[20];
	rellenarVector(curso);
	puntoC(curso);
	puntoD(curso);
	
	return 0;
}

void rellenarVector(alumno c[20])
{
	for(int i=0;i<20;i++)
	{
		cout<<"Indique legajo: ";
		cin>>c[i].legajo;
		cout<<"Indique nombre: ";
		cin>>c[i].fecha.nombre;
		cout<<"Indique su apellido: ";
		cin>>c[i].fecha.apellido;
		cout<<"Indique su primer nota: ";
		cin>>c[i].calificaciones.nota1;
		cout<<"Indique su segunda nota: ";
		cin>>c[i].calificaciones.nota2;
		cout<<"Indique su tercer nota: ";
		cin>>c[i].calificaciones.nota3;
	}
}

void puntoC(alumno c[20])
{
	int pos;
	for(int i=0;i<20;i++)
	{
		if(c[i].legajo==456789)
		{
			pos=i;
		}
	}
	cout<<"La persona de legajo 456789 esta en la posicion "<<pos<<" y sus notas son "<<c[pos].calificaciones.nota1<<", "<<c[pos].calificaciones.nota2<<" y "<<c[pos].calificaciones.nota3<<endl;
}

void puntoD(alumno c[20])
{
	int pos;
	for(int i=0;i<20;i++)
	{
		if(strcmp(c[i].fecha.apellido,"xxxxx")==0)
		{
			pos=i;
		}
	}
	cout<<"La persona de apellido xxxxx se encuentra en la posicion: "<<pos<<"con legajo "<<c[pos].legajo<<endl;
	cout<<"Su nombre es "<<c[pos].fecha.nombre<<" y sus notas son "<<c[pos].calificaciones.nota1<<", "<<c[pos].calificaciones.nota2<<" y "<<c[pos].calificaciones.nota3<<endl;
}


