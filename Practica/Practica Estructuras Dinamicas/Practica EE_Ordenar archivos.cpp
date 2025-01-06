/*Ordenar Archivos con listas y tipos de datos enteros*/
#include<iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* sgte;
};

nodo*insertarOrdenado (nodo*&,int);
void ordenarArchivo(FILE*);

int main()
{
	
	
	
	return 0;
}

nodo*insertarOrdenado(nodo*&lista,int valor)
{
	nodo*nuevo=new nodo();
	nuevo->info=valor;
	nuevo->sgte=NULL;
	if(lista==NULL||valor<lista->info)
	{
		nuevo->sgte=lista;
		lista=nuevo;
	}
	else
	{
		nodo*aux=lista;
		while(aux->sgte->info<valor&&aux->sgte!=NULL)
		{
			aux=aux->sgte;
		}
		nuevo->sgte=aux->sgte;
		aux->sgte=nuevo;
	}
	return nuevo;
}

void ordenarArchivo(FILE*arch)
{
	arch=fopen("archivo.dat","rb");
	int auxr;
	nodo*lista=NULL;
	while(fread(&auxr,sizeof(int),1,arch))
	{
		insertarOrdenado(lista,auxr);
	}
	fclose(arch);
	
	arch=fopen("archivo.dat","wb");
	nodo*aux=lista;
	while(lista!=NULL)
	{
		fwrite(&aux->info,sizeof(int),1,arch);
		aux=aux->sgte;
	}
	fclose(arch);
}


