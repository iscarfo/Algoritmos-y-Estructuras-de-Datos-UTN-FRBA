/*Dada una cola (nodo = registro + puntero), desarrollar y codificar un procedimiento que
elimine 2 nodos de la misma (indicar con un parámetro 'S'/'N' si ello fue‚ o no posible)*/
#include<iostream>
#include<cstring>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void queue(nodo*&,nodo*&,int);
int unqueue(nodo*&,nodo*&);

int main()
{
	nodo*colafte=NULL;
	nodo*colafin=NULL;
	
	return 0;
}

void queue(nodo*&colafte,nodo*colafin,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=NULL;
	
	if(colafte==NULL)
	{
		colafte=nuevo;
	}
	else
	{
		colafin->sgte=nuevo;
	}
	colafin=nuevo;
}

int unqueue(nodo*&colafte,nodo*&colafin)
{
	int ret;
	ret=colafte->info;
	nodo*aux=colafte;
	colafte=aux->sgte;
	if(colafte==NULL)
	{
		colafin=NULL;
	}
	delete(aux);
	return ret;
}

char funcion (nodo*&colafte,nodo*&colafin)
{
	int contador=0;
	while(colafte!=NULL&&contador<2)
	{
		unqueue(colafte,colafin);
		contador++;
	}
	if(contador==2)
	{
		return 'S';
	}
	else
	{
		return 'N';
	}
}
