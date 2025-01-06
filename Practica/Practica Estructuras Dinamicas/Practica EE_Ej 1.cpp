/*Dada una pila y un valor X colocar el vañor x en la tercera posicion se la pila, retornando
un parámetro con valor 'S' o 'N' según haya sido exitoso o no el requerimiento. (Definir
parámetros y codificar).*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* sgte;
};

void push(nodo*&,int);
int pop(nodo*&);

int main()
{
	nodo*pila=NULL;
	int contador=0,X,posicion;
	int salida;
	
	cout<<"Indique el valor X: ";
	cin>>X;
	
	push(pila,X);
	push(pila,5);
	push(pila,6);



	while(pila!=NULL)
	{
		salida=pop(pila);
		contador++;
		if(salida==X)
		{
			posicion=contador;
		}
	
	}
	
	if(posicion==3)
	{
		cout<<"S"<<endl;
	}
	else
	{
		cout<<"N"<<endl;
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
