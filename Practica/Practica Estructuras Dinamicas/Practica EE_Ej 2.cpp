/*Dada una pila y dos valores X e I, desarrollar un procedimiento que inserte el valor X en la
posición I de la pila si es posible. (Definir parámetros y codificar).*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void push(nodo*&,int);
int pop(nodo*&);
void funcion(nodo*&,int,int);

int main()
{
	nodo*pila=NULL;
	int X,I;
	cout<<"Indique el valor de X: "<<endl;
	cin>>X;
	cout<<"Indique el valor de I: "<<endl;
	cin>>I;
	

	
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
	delete (aux);
	return ret;
}

void funcion(nodo*&pila,int I,int X)
{
	int salida,contador=0;
	push(pila,X);
	while(pila!=NULL)
	{
		salida=pop(pila);
		contador++;
	}
	if(contador==I)
	{
		cout<<"Se pudo"<<endl;
	}
	else
	{
		cout<<"No se pudo"<<endl;
	}

}
