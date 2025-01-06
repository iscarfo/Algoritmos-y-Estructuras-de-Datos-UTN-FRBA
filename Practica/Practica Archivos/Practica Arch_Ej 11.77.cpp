/*77) Un negocio de ropa, vende sus artículos en distintos talles. Para realizar la facturación
dispone de los siguientes archivos:
Un archivo ‘Articulos.dat’, con los precios de cada artículo y talle que vende, con el
siguiente diseño
de registro:
1) código de articulo (1..100) a.2) talle (1..5) a.3) precio (real)
También se dispone de un conjunto de ventas a facturar, que se ingresan por teclado con
los siguientes
datos: código de artículo, talle y unidades (1 digito). Las ventas finalizan con un código de
articulo
negativo.
Desarrollar un algoritmo que:
a. informe el precio de la venta, considerando un descuento del 10% si las unidades
vendidas son
superiores a tres mas el 21% del IVA.
b. al final del proceso emita el siguiente listado, ordenado por articulo y talle ascendente:
Codigo de Articulo 999
Talle Unidades Vendidas
Total unidades vendidas artículo 9999999
Total general de unidades vendidas 9999999*/
#include <iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct articulos
{
	int codArt;
	int talle;
	float precio;
};

void puntoAyB(FILE*);

int main()
{
	FILE*articulos;
	
	return 0;
}

void puntoAyB(FILE*a)
{
	articulos aux;
	int codArtAux=0,talleAux=0,unidadesAux=0,total=0,matriz[100][5];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<5;j++)
		{
			matriz[i][j]=0;
		}
	}
	cout<<"Indique el codigo de articulo: ";
	cin>>codArtAux;
	while(codArtAux>0)
	{
		fseek(a,0,SEEK_SET);
		int precio=0;
		cout<<"Indique el talle: ";
		cin>>talleAux;
		cout<<"Indique las unidades: ";
		cin>>unidadesAux;
		total+=unidadesAux;
		matriz[codArtAux-1][talleAux-1]+=unidadesAux;
		fread(&aux,sizeof(articulos),1,a);
	    while(aux.codArt!=codArtAux||aux.talle!=talleAux)
		{
            fread(&aux,sizeof(articulos),1,a);
	    }    
		if(unidadesAux>3)
		{
			precio=aux.precio+(aux.precio*0.21)-(aux.precio*0.10);
		}
		else
		{
			precio=aux.precio+(aux.precio*0.21);
		}
		cout<<"Precio: "<<precio<<endl;
		cout<<"Indique el codigo de articulo: ";
	    cin>>codArtAux;
	}
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<"Articulo "<<i+1<<" talle "<<j+1<<" se vendieron "<<matriz[i][j]<<endl;
		}
	}
	cout<<"En total se vendieron "<<total<<" unidades"<<endl;
}
