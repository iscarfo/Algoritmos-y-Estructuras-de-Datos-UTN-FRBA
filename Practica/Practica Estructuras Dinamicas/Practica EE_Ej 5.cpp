/*Definir una función INVERSA que evalúe dos conjuntos de caracteres separados por un
punto y retorne True si los conjuntos son inversos (ej: ABcDe.eDcBA) o False si no lo son. Los
conjuntos deben ingresarse por teclado. (Definir parámetros y codificar).*/
#include<iostream>
#include<cstring>
using namespace std;

struct nodo
{
	char info;
	nodo*sgte;
};

void push(nodo*&,char);
char pop(nodo*&);
void entradaDeDatos(nodo*&);

int main()
{
	nodo*pila=NULL;
	
	return 0;
}

void push(nodo*&pila,char valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=pila;
	pila=nuevo;
}

char pop(nodo*&pila)
{
	char ret;
	ret=pila->info;
	nodo*aux=pila;
	pila=aux->sgte;
	delete(aux);
	return ret;
}

void entradaDeDatos(nodo*&pila)
{
	char caracter,salida;
	int i,contador=0,error=0;
	cout<<"Ingrese el siguiente caracter: ";
	cin>>caracter;
	while(caracter!='.')
	{
		contador++;
		push(pila,caracter);
	    cout<<"Ingrese el siguiente caracter: ";
	    cin>>caracter;		
	}
	char conj[contador+1];
	for(i=0;i<contador;i++)
	{
		cout<<"Ingrese el siguiente caracter: ";
		cin>>conj[i];
	}
	for(int j=0;j<contador;j++)
	{
		salida=pop(pila);
		if(conj[i]!=salida)
		{
			error++;
		}
	}
	if(error>0)
	{
		cout<<"No son inversos"<<endl;
	}
	else
	{
		cout<<"Son inversos"<<endl;
	}
}
