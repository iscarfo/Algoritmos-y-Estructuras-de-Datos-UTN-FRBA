#include<iostream>
using namespace std;


struct alumno{
	int legajo;
	char nombre[50+1];
	int cantMatAprobadas;
};
void burbuja (alumno [],int);
int bus_bin (alumno [], int, int);

int main()
{
	int n=6;
	int	buscado=100;
	alumno vector[]={{50,"juan",7},{22,"analia",8},
	{10,"analia",7},{100,"roxana",10},{9,"camila",9},{11,"dario",7}};

	burbuja(vector,n);
	int dato=bus_bin(vector,n,buscado);

	

	
	cout<<"El nombre del alumno con legajo 100 es: "<<vector[dato].nombre;
	
	
}

void burbuja (alumno v[],int n)
{
	int i,j;
	alumno aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if((v[j-1].legajo>v[j].legajo))
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]= aux;
			}
		}
	}
}

int bus_bin (alumno vector[],int n, int buscado)
{
	int primero=0;
	int ultimo=n-1;
	int medio;
	
	while(primero<=ultimo)
	{
		medio=(primero+ultimo)/2;
		
		if(vector[medio].legajo==buscado)
		{
			return medio;
		}
		else
		if(vector[medio].legajo>buscado)
		{
			ultimo=medio-1;
		}
		else
		{
			primero=medio+1;
		}
	}
	
	return -1;
}
