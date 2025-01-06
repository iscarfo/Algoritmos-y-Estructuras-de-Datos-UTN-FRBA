/*Dado un archivo PRECIOS (desordenado) con los precios de cada articulo, donde cada
registro contiene:
a. Nro. de articulo (5 digitos)
b. Descripcion del articulo (19 c)
c. Precio por unidad (real)
d. Cantidad en stock (5 e)
e. Nro. de proveedor (4 digitos)

7. Desarrollar el programa que imprima el contenido del archivo ordenado por:
1) Nro. de articulo creciente
2) Descripcion del articulo (alfabetico creciente)
3) Nro. de proveedor creciente y dentro del mismo por Nro. de articulo creciente
4) Nro. de proveedor creciente y dentro del mismo por Nro. de articulo decreciente.*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstring>
using namespace std;

struct estructura
{
	int numArticulo;
	char descripcion[19+1];
	float precioXunidad;
	int cantStock;
	int numProveedor;
};

int cantidadReg(FILE*);
void guardarVec(FILE*,estructura [],int);
void burbuja1(estructura [],int);
void burbuja2(estructura [],int);
void burbuja3(estructura [],int);
void burbuja4(estructura [],int);


int main()
{
	FILE*precios;
	int tam=cantidadReg(precios);
	estructura vec[tam];
	guardarVec(precios,vec,tam);
	
	
	return 0;
}

int cantidadReg(FILE*a)
{
	estructura aux;
	int posActual=ftell(a),cantReg;
	fseek(a,0,SEEK_END);
	cantReg=ftell(a)/sizeof(aux);
	fseek(a,posActual,SEEK_SET);
	return cantReg;
}

void guardarVec(FILE*a,estructura vec[],int n)
{
	estructura aux;
	a=fopen("PRECIOS.BIN","rb");
	for(int i=0;i<n;i++)
	{
		fread(&aux,sizeof(estructura),1,a);
		vec[i].numArticulo=aux.numArticulo;
		vec[i].precioXunidad=aux.precioXunidad;
		vec[i].cantStock=aux.cantStock;
		vec[i].numProveedor=aux.numProveedor;
		strcpy(vec[i].descripcion,aux.descripcion);
	}
	fclose(a);
}

void burbuja1(estructura vec[],int n)
{
	estructura aux;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(vec[j-1].numArticulo>vec[j].numArticulo)
			{
				aux=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=aux;
			}
		}
	}
	for(int z=0;z<n;z++)
	{
		cout<<"Numero de articulo: "<<vec[z].numArticulo<<endl;
		cout<<"Precio por unidad: "<<vec[z].precioXunidad<<endl;
		cout<<"Cantidad de stock: "<<vec[z].cantStock<<endl;
		cout<<"Numero de Proveedor: "<<vec[z].numProveedor<<endl;
		cout<<"Descripcion: "<<vec[z].descripcion<<endl;
	}
}

void burbuja2(estructura vec[],int n)
{
	estructura aux;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(strcmp(vec[j-1].descripcion,vec[j].descripcion)==1)
			{
				aux=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=aux;
			}
		}
	}
	for(int z=0;z<n;z++)
	{
		cout<<"Descripcion: "<<vec[z].descripcion<<endl;
		cout<<"Numero de articulo: "<<vec[z].numArticulo<<endl;
		cout<<"Precio por unidad: "<<vec[z].precioXunidad<<endl;
		cout<<"Cantidad de stock: "<<vec[z].cantStock<<endl;
		cout<<"Numero de Proveedor: "<<vec[z].numProveedor<<endl;
	}
}

void burbuja3(estructura vec[],int n)
{
	estructura aux;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(vec[j-1].numProveedor>vec[j].numProveedor||((vec[j-1].numProveedor==vec[j].numProveedor)&&vec[j-1].numArticulo>vec[j].numArticulo))
			{
				aux=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=aux;
			}
		}
	}
	for(int z=0;z<n;z++)
	{
		cout<<"Numero de Proveedor: "<<vec[z].numProveedor<<endl;
		cout<<"Numero de articulo: "<<vec[z].numArticulo<<endl;
		cout<<"Descripcion: "<<vec[z].descripcion<<endl;
		cout<<"Precio por unidad: "<<vec[z].precioXunidad<<endl;
		cout<<"Cantidad de stock: "<<vec[z].cantStock<<endl;

	}
}

void burbuja4(estructura vec[],int n)
{
	estructura aux;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(vec[j-1].numProveedor>vec[j].numProveedor||((vec[j-1].numProveedor==vec[j].numProveedor)&&vec[j-1].numArticulo<vec[j].numArticulo))
			{
				aux=vec[j-1];
				vec[j-1]=vec[j];
				vec[j]=aux;
			}
		}
	}
	for(int z=0;z<n;z++)
	{
		cout<<"Numero de Proveedor: "<<vec[z].numProveedor<<endl;
		cout<<"Numero de articulo: "<<vec[z].numArticulo<<endl;
		cout<<"Descripcion: "<<vec[z].descripcion<<endl;
		cout<<"Precio por unidad: "<<vec[z].precioXunidad<<endl;
		cout<<"Cantidad de stock: "<<vec[z].cantStock<<endl;

	}
}
