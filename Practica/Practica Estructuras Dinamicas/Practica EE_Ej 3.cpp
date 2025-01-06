/*Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la última
posición de la pila y la retorne. (Definir parámetros y codificar).*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void push(nodo*&,int);
int pop(nodo*&);

int main()
{
	nodo*pila=NULL;
	int x;
	cout<<"Indique: ";
	cin>>x;
	push(pila,x);
	cout<<"Pila: "<<endl;
	while(pila!=NULL)
	{
		cout<<pop(pila)<<endl;
	}
	
	return 0;
}

void push(nodo*&pila,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=pila;
	pila=nuevo;
}

int pop(nodo*&pila)
{
	int ret;
	ret=pila->info;
	nodo*aux=pila;
	pila=aux->sgte;
	delete(aux);
	return ret;
}

