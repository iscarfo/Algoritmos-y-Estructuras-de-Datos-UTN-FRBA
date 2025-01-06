/*Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor de
sus nodos y la retorne. Solo se deben usar pilas. (Definir parámetros y codificar).*/
#include<iostream>
#include<cstring>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void push (nodo*&,int);
int pop (nodo*&);
void burbuja(int[],int);
void ordenarPila(nodo*&);

int main()
{
	
	return 0;
}

void push(nodo*&pila,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=pila;
	pila=nuevo;
}

int pop (nodo*&pila)
{
	int ret;
	ret=pila->info;
	nodo*aux=pila;
	pila=aux->sgte;
	delete(aux);
	return ret;
}

void burbuja(int v[],int n)
{
	int i,j,aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(v[j-1]>v[j])
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]=aux;
			}
		}
	}
}

void ordenarPila(nodo*&pila)
{
	int n,i=0;
	cout<<"Indique la cantidad de nodos de la pila: ";
	cin>>n;
	int vec[n];
	while(pila!=NULL)
	{
		vec[i]=pop(pila);
		i++;
	}
	burbuja(vec,n);
	for(int j=0;j<n;j++)
	{
		push(pila,vec[i]);
	}
}
