/*Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar un
procedimiento que genere otra cola COLAB por apareo del campo ARRIBO del registro
(define orden creciente en ambas).
Nota: COLA y COLB dejan de ser útiles después del apareo*/
#include<iostream>
using namespace std;

struct infoNodo
{
	int arribo;
	int fecha;
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

void queue(nodo*&,nodo*&,infoNodo);
infoNodo unqueue(nodo*&,nodo*&);
void apareo (nodo*&,nodo*&,nodo*&,nodo*&);

int main()
{
	
	
	return 0;
}

void queue(nodo*&cfte,nodo*&cfin,infoNodo valor)
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

infoNodo unqueue(nodo*&cfte,nodo*&cfin)
{
	infoNodo ret;
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

void apareo (nodo*&cfteA,nodo*&cfinA,nodo*&cfteB,nodo*&cfinB)
{
	nodo*cfteAB=NULL;
	nodo*cfinAB=NULL;
	infoNodo salidaA,salidaB;
	salidaA=unqueue(cfteA,cfinA);
	salidaB=unqueue(cfteB,cfinB);
	while(cfteA!=NULL&&cfteB!=NULL)
	{
		if(salidaA.arribo>salidaB.arribo)
		{
			queue(cfteAB,cfinAB,salidaB);
			salidaB=unqueue(cfteB,cfinB);
		}
		else if(salidaA.arribo<salidaB.arribo)
		{
			queue(cfteAB,cfinAB,salidaA);
			salidaA=unqueue(cfteA,cfinA);
		}
		else
		{
			queue(cfteAB,cfinAB,salidaB);
			queue(cfteAB,cfinAB,salidaA);
			salidaA=unqueue(cfteA,cfinA);
	        salidaB=unqueue(cfteB,cfinB);
		}
	}
	while(cfteA!=NULL)
	{
		queue(cfteAB,cfinAB,salidaA);
		salidaA=unqueue(cfteA,cfinA);
	}
	while(cfteB!=NULL)
	{
		queue(cfteAB,cfinAB,salidaB);
		salidaB=unqueue(cfteB,cfinB);
	}
}
