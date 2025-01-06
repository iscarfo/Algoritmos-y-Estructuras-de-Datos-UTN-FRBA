/*Dada una lista (nodo = registro + puntero), desarrollar y codificar una función que devuelva
la cantidad de nodos que tiene.*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* sgte;
};

nodo*&insertarOrdenado(nodo*&,int);

int main()
{
	nodo*lista=NULL;
	
	
	return 0;
}

nodo*insertarOrdenando(nodo*&lista,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=NULL;
	if(lista==NULL||valor<lista->info)
	{
		nuevo->sgte=lista;
		lista=nuevo;
	}
	else
	{
		nodo*aux=lista;
		while(aux->sgte->info<valor&&aux->sgte!=NULL)
		{
			aux=aux->sgte;
		}
		nuevo->sgte=aux->sgte;
		aux->sgte=nuevo;
	}
	return nuevo;
}

int funcion(nodo*&lista)
{
	nodo*aux=lista;
	int contador=0;
	while(lista!=NULL)
	{
		contador++;
		aux=aux->sgte;
	}
	return contador;
}
