/*Una empresa que distribuye mercadería hacia distintas localidades del interior dispone de
dos archivos de registros:
Uno denominado DESTINOS con información de la distancia a cada uno de los destinos: a)
Nro. De destino (3 dígitos) b) Distancia en kilómetros (NNN.NNN)
Otro denominado VIAJES con los viajes realizados por cada camión (< 200), donde cada
registro contiene:
a) Patente del camión (6 caracteres)
b) Nro. de destino
c) Nro. de chofer (1 a 150)
Desarrollar estrategia, algoritmo y codificación del programa que determine e imprima:
1) Cantidad de viajes realizados a cada destino (solo si > 0).
2) Nro. de chofer con menor cantidad de Km (entre los que viajaron).
3) Patente de los camiones que viajaron al destino 116 sin repeticiones de las mismas.*/
#include <iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct destino
{
	int numDestino;
	int distancia;
};

struct viajes
{
	char patente[6+1];
	int numDestino;
	int numChofer;
};

void punto1y2(FILE*,FILE*);
void punto3 (FILE*);

int main()
{
	FILE*destinos;
	FILE*viajes;
	
	return 0;
}


void punto1y2(FILE*a,FILE*b)
{
	a=fopen("DESTINOS.DAT","rb");
	b=fopen("VIAJES.DAT","rb");
	viajes aux;
	destino aux2;
	int n;
	cout<<"Indique la cantidad de destinos: ";
	cin>>n;
	int destinos[n];
	for(int i=0;i<n;i++)
	{
		destinos[i]=0;
	}
	int chofer[150];
	int menor=0, nummenor=0;
	while(fread(&aux,sizeof(viajes),1,b))
	{
		fread(&aux2,sizeof(destino),1,a);
        chofer[aux.numChofer]+=aux2.distancia;
        destinos[aux.numDestino]++;
	}
	for(int i=0;i<150;i++)
	{
		if(menor==0&&chofer[i]>0)
		{
			menor=chofer[i];
			nummenor=i;
		}
		if(menor<chofer[i]&&chofer[i]!=0)
		{
			menor=chofer[i];
			nummenor=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(destinos[i]>0)
		{
			cout<<"Destino "<<i+1<<": "<<"se viajo "<<destinos[i]<<" veces"<<endl;
		}
	}
	cout<<"El chofer con menos KM recorridos es el numero: "<<nummenor<<endl;

	fclose(a);
	fclose(b);
}

void punto3 (FILE*a)
{
	char patenteEn[6+1]="Cero";
	//int tam=cantReg(a);
	//guardarVector(a,vec[],tam);
	//burbujaPorPatente(vec[],tam);
	//guardarArchivo(vec[],tam,a);
	a=fopen("VIAJES.DAT","rb");
	viajes aux1;
	cout<<"La patente de los autos que viajaron al destino 116 son: "<<endl;
	while(fread(&aux1,sizeof(viajes),1,a))
	{
		if(aux1.numDestino==116&&strcmp(aux1.patente,patenteEn)!=0)
		{
			cout<<aux1.patente<<endl;
			strcpy(patenteEn,aux1.patente);
		}
	}
	if(strcmp(patenteEn,"Cero")==0)
	{
		cout<<"Ningun camion paso por ese destino"<<endl;
	}
	fclose(a);
}
