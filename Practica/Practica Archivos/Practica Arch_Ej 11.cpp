/*Una fábrica de calzados elabora 7 modelos en 5 colores diferentes. Esta fábrica tiene
registradas las ventas realizadas por cada modelo y por cada color en un archivo de ventas,
conteniendo :
a. Nro. modelo (1..7), Color (‘A’..’E’), Cantidad vendida (3 dig.).
Se pide emitir un listado que informe los totales de cada uno de los modelos y por cada
uno de los colores, como asi también los totales por cada modelo, los totales por cada
color y el total general*/
#include <iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct ventas
{
	int numModelo;
	char color;
	int cantVendida;
};

void contador(FILE*);

int main()
{
	FILE*ventas;
	
	return 0;
}

void contador(FILE*a)
{
	a=fopen("VENTAS.DAT","rb");
	ventas aux;
	int total=0;
	int matriz[7][5];
	char letras[5]={'A','B','C','D','E'};
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<5;j++)
		{
			matriz[i][j]=0;
		}
	}
	while(fread(&aux,sizeof(ventas),1,a))
	{
		int color=0;
		switch(aux.color)
		{
			case'A':color=0; break;
			case'B':color=1; break;
			case'C':color=2; break;
			case'D':color=3; break;
			case'E':color=4; break;
			case'F':color=5; break;
		}
		matriz[aux.numModelo-1][color]+=aux.cantVendida;
		total+=aux.cantVendida;
	}
	cout<<"Cantidad vendida: "<<endl;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<"Modelo "<<i+1<<" color "<<letras[j]<<": "<<matriz[i][j];
		}
	}
	cout<<"Total: "<<total;
	fclose(a);

}

