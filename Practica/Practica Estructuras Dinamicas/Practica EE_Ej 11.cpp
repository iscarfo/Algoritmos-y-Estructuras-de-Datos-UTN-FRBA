/*Dada una cola (nodo = registro + puntero), imprimirla en orden natural si tiene más de 100
nodos, caso contrario imprimirla en orden inverso.*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void queue(nodo*&,nodo*&,int);
int unqueue(nodo*&,nodo*&);
void push(nodo*&,int);
int pop(nodo*&);
void funcion(nodo*&cfte,nodo*&cfin);

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
	nodo*aux=cfte;
	ret=aux->info;
	cfte=aux->sgte;
	
	if(cfte==NULL)
	{
		cfin=NULL;
	}
	delete(aux);
	return ret;
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

void funcion(nodo*&cfte,nodo*&cfin)
{
	nodo*cfteAux=NULL;
	nodo*cfinAux=NULL;
	nodo*pilaAux=NULL;
	int contador=0,salida;
	while(cfte!=NULL)
	{
		salida=unqueue(cfte,cfin);
		queue(cfteAux,cfinAux,salida);
		push(pilaAux,salida);
		contador++;
	}
	if(contador>100)
	{
		cout<<"Cola: "<<endl;
		while(cfteAux!=NULL)
		{
			cout<<unqueue(cfteAux,cfinAux)<<endl;
		}
	}
	else
	{
		cout<<"Cola: "<<endl;
		while(pilaAux!=NULL)
		{
			cout<<pop(pilaAux)<<endl;
		}
	}
}
