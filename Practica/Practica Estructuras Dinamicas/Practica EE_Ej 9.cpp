/*Dada una cola (nodo = registro + puntero), desarrollar y codificar una función que devuelva
la cantidad de nodos que tiene.*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void queue(nodo*&,nodo*&,int);
int unqueue(nodo*&,nodo*&);
int cantidadDeNodos(nodo*&,nodo*&);

int main()
{
	
	return 0;
}

void queue(nodo*&cfte,nodo*&cfin,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=NULL;
	
	if(cfte==NULL)
	{
		cfte=nuevo;
	}
	else
	{
		cfin->sgte=nuevo;
	}
	cfin=nuevo;
}

int unqueue(nodo*&cfte,nodo*&cfin)
{
	int ret;
	ret=cfte->info;
	nodo*aux=cfte;
	cfte=aux->sgte;
	
	if(cfte==NULL)
	{
		cfin=NULL;
	}
	
	delete(aux);
	return ret;
}

int cantidadDeNodos(nodo*&cfte,nodo*&cfin)
{
	int contador=0;
	while(cfte!=NULL)
	{
		unqueue(cfte,cfin);
		contador++;
	}
	return contador;
}
