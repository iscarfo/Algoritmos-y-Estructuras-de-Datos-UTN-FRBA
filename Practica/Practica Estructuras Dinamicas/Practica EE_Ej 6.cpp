/*Desarrollar un procedimiento que ingrese por teclado un conjunto de Apellidos y Nombre
de alumnos y los imprima en orden inverso al de ingreso. (Definir parámetros y codificar).*/
#include<iostream>
#include<cstring>
using namespace std;

struct nodo
{
	char info[20+1];
	nodo*sgte;
};

void push(nodo*&,char[20+1]);
char pop(nodo*&);
void funcion(nodo*&);

int main()
{
	nodo*pila=NULL;
	
	return 0;
}

void push(nodo*&pila,char valor[20+1])
{
	nodo*nuevo=new nodo();
	strcpy(nuevo->info,valor);
	nuevo->sgte=pila;
	pila=nuevo;
}

char pop(nodo*&pila)
{
	char ret[20+1];
	strcpy(ret,pila->info);
	nodo*aux=pila;
	pila=aux->sgte;
	delete(aux);
	return ret[20+1];
}

void funcion(nodo*&pila)
{
	char carga[20+1];
	cout<<"Indique el nombre y apellido (finalice con 'FIN'): ";
	cin>>carga;
	while(strcmp(carga,"FIN")!=0)
	{
		push(pila,carga);
		cout<<"Indique el nombre y apellido (finalice con 'FIN'): ";
	    cin>>carga;
	}
	cout<<"Pila: "<<endl;
	while(pila!=NULL)
	{
		cout<<pop(pila);
	}
}
