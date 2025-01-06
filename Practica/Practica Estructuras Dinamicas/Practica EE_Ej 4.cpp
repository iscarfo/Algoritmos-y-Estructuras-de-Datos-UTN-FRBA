/*Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada valor
igual a X que se encuentre en la pila por el valor Y retornando la pila modificada. En caso
de no haber ningún valor igual a X retornar la pila sin cambio. (Definir parámetros y
codificar).*/
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
	int x,y;
	cout<<"Indique el valor de x: ";
	cin>>x;
	cout<<"Indique el valor de y: ";
	cin>>y;
	
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

void funcion(nodo*&pila,int x,int y)
{
	nodo*pilaAux=NULL;
	int salida,carga,contador=0;
	
	while(pila!=NULL)
	{
		salida=pop(pila);
		if(salida==x)
		{
			push(pilaAux,y);
			contador++;
		}
		else
		{
			push(pilaAux,salida);
		}
	}
	
	if(contador==0)
	{
		cout<<"La pila no cambio: "<<endl;
		while(pilaAux!=NULL)
		{
			cout<<pop(pilaAux);
		}
	}
	else
	{
		cout<<"La pila cambio: "<<endl;
		while(pilaAux!=NULL)
		{
			cout<<pop(pilaAux);
		}		
	}
}
