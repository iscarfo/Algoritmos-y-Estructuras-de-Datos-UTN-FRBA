/*Parcial de Yamila (video 16):
Se tiene un archivo de disponibilidad para las habitaciones de un hotel en la costa "VERANO2021.DAT" (sin orden)
- Numero de habitacion: 999999
- Tipo: 's','d','t' o 'c' (singles, dobles, triples, cuadruples)
- Dias disponibles de la temporada: 999
- Precio por dia de la habitacion: 999
a)Ordenar el archivo "VERANO2021.DAT" por numero de habitacion
b)Armar una lista ordenada por numero de habitacion y mostrarla por pantalla si el numero de dias disponibles es menor a 50 y son habitaciones singles o dobles*/
#include<iostream>
#include<cstring>
using namespace std;

struct infoNodo
{
	int numHabitacion;
	char tipo;
	int diasDisponibles;
	int precio;
	
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

nodo*insertarOrdenado(nodo*&,infoNodo);
void puntoA(FILE*);
void puntoB(FILE*);


int main()
{
	
	
	
	return 0;
}

nodo*insertarOrdenado(nodo*&lista,infoNodo valor)
{
	nodo*nuevo=new nodo();
	nuevo->info.numHabitacion=valor.numHabitacion;
	nuevo->info.tipo=valor.tipo;
	nuevo->info.diasDisponibles=valor.diasDisponibles;
	nuevo->info.precio=valor.precio;
	nuevo->sgte=NULL;
	if(lista==NULL||valor.numHabitacion<lista->info.numHabitacion)
	{
		nuevo->sgte=lista;
		lista=nuevo;
	}
	else
	{
		nodo*aux=lista;
		while(aux->sgte->info.numHabitacion<valor.numHabitacion&&aux->sgte!=NULL)
		{
			aux=aux->sgte;
		}
		nuevo->sgte=aux->sgte;
		aux->sgte=nuevo;
	}
	return nuevo;
}

void puntoA(FILE*archivo)
{
	nodo*lista=NULL;
	archivo=fopen("VERANO2021.DAT","rb");
	infoNodo auxr;
	while(fread(&auxr,sizeof(infoNodo),1,archivo))
	{
		insertarOrdenado(lista,auxr);
	}
	fclose(archivo);
	archivo=fopen("VERANO2021.DAT","wb");
	nodo*aux1=lista;
	while(aux1!=NULL)
	{
		fwrite(&aux1->info,sizeof(infoNodo),1,archivo);
		aux1=aux1->sgte;
	}
	fclose(archivo);
	
}

void puntoB(FILE*archivo)
{
	nodo*lista=NULL;
	archivo=fopen("VERANO2021.DAT","rb");
	infoNodo auxr;
	while(fread(&auxr,sizeof(infoNodo),1,archivo))
	{
		insertarOrdenado(lista,auxr);
		if(auxr.diasDisponibles<50&&auxr.tipo=='s'||auxr.tipo=='d')
		{
			cout<<"Habitacion numero: "<<auxr.numHabitacion<<endl;
			cout<<"Tipo: "<<auxr.tipo<<endl;
			cout<<"Dias disponibles: "<<auxr.diasDisponibles<<endl;
			cout<<"Precio por Dia: "<<auxr.precio<<endl;
		}
	}
	fclose(archivo);
}
