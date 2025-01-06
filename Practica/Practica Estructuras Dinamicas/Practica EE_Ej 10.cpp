/*Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere una única cola COLAB a partir de ellas. (Primero los nodos de
COLA y luego los de COLB).*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo*sgte;
};

void queue(nodo*&,nodo*&,int);
int unqueue(nodo*&,nodo*&);
void generarCola(nodo*&,nodo*&,nodo*&,nodo*&);


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
	cfte=aux->sgte;
	ret=aux->info;
	
	if(cfte==NULL)
	{
		cfin=NULL;
	}
	delete(aux);
	return ret;
}

void generarCola(nodo*&cfteA,nodo*&cfinA,nodo*&cfteB,nodo*&cfinB)
{
	nodo*cfteAB=NULL;
	nodo*cfinAB=NULL;
	int salida;
	while(cfteA!=NULL)
	{
		salida=unqueue(cfteA,cfinA);
		queue(cfteAB,cfinAB,salida);
	}
	while(cfteB!=NULL)
	{
		salida=unqueue(cfteB,cfinB);
		queue(cfteAB,cfinAB,salida);
	}

}
