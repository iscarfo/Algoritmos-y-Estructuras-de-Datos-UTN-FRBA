//FINAL 11/12/2023

//Punto 1A: 
struct nodo
{
	int info;
	nodo*sgte;
};

nodo*crearLista(nodo*&pila,nodo*&cfte,nodo*&cfin)
{
	nodo*lista=NULL;
	int aux;
	while(pila!=NULL)
	{
		aux=pop(pila);
		insertarSinRepetir(lista,aux);
	}
	while(cfte!=NULL)
	{
		aux=unqueue(cfte,cfin);
		insertarSinRepetir(lista,aux);
	}

	return lista;
}

//Punto 1B:

struct nodo
{
	int info;
	nodo*sgte;
};

//Supongo lista1 y lista2 ordenadas

nodo*crearLista(nodo*&lista1,nodo*&lista2)
{
	nodo*lista=NULL;
	nodo*aux1=lista1;
	nodo*aux2=lista2;
	while(aux1!=NULL&&aux2!=NULL)
	{
		if(aux1->info==aux2->info)
		{
			insertarOrdenado(lista,aux1);
			aux2=aux2->sgte;
			aux1=aux1->sgte;
		}
		else if(aux1->info>aux2->info)
		{
			aux2=aux2->sgte;
		}
		else
		{
			aux1=aux1->sgte;
		}
	}
	liberar(aux1);
	liberar(aux2);
	return lista;
}

//Punto 2:
struct regVector
{
	int codHotel;
	int cantReservas;
	int diasDisponibles;
};

struct infoNodo
{
	int codHotel;
	int diasReservados;
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

void actualizarVector(regVector v[],nodo*&lista)
{
	infoNodo aux;
	int i;
	while(lista!=NULL)
	{
		aux=pop(lista);
		i=busquedaBinaria(v,50,aux.codHotel);
		v[i].cantReservas++;
		v[i].diasDisponibles-=aux.diasReservados;
	}
}

/*Punto Bonus: considero que es la mas eficiente debido a que la busqueda binaria es la busqueda mas eficiente de todas al saber la cantidad de registros del vector
Otra alternativa podría ser pasar los registros del vector a una lista y usar la funcion buscarNodo, pero esto significaría utilizar memoria dinamica en una nueva lista innecesaria,
aunque ayudaría si no se supiese la cantidad de registros*/

//Punto 3:
struct infoLista
{
	double codProducto;
	int peso;
	char tipo;
	double cantStock;
};

struct nodo
{
	infoLista info;
	nodo*sgte;
};

void punto3(FILE*archivo)
{
	nodo*listaOrden=NULL;
	nodo*listaSinStock=NULL;
	nodo*listaPesados=NULL;
	infoLista aux;
	fopen("STOCK.DAT","rb+");
	while(fread(&aux,sizeof(infoLista),1,archivo))
	{
		insertarOrdenado(listaOrden,aux); //por codProducto
	}
	nodo*aux1=listaOrden;
	while(aux1!=NULL)
	{
		if(aux1->info.cantStock==0)
		{
			insertarOrdenado(listaSinStock,aux1->info);
		}
		aux1=aux1->sgte;
	}
	aux1=listaOrden;
	while(aux1!=NULL)
	{
		if(aux1->info.peso>100||aux1->info.tipo=="B")
		{
			insertarOrdenado(listaPesados,aux1->info);
		}
		aux1=aux1->sgte;
	}
	aux1=listaSinStock;
	while(aux1!=NULL)
	{
		cout<<"...."
		aux1=aux1->sgte;
	}
	aux1=listaPesados;
	while(aux1!=NULL)
	{
		cout<<"...."
		aux1=aux1->sgte;
	}
	fseek(archivo,0,SEEK_SET);
	while(listaOrden!=NULL)
	{
		aux.codProducto=listaOrden->info.codProducto;
	    aux.peso=listaOrden->info.peso;
	    aux.tipo=listaOrden->info.tipo;
	    aux.cantStock=listaOrden->info.cantStock;
	    fwrite(&aux,sizeof(infoLista),1,archivo);
	    listaOrden=listaOrden->sgte;
	}
	liberar(aux1);
	liberar(listaOrden);
	fclose(archivo);
}

//Punto Bonus: para ordenar el archivo podria haber utilizado un vector, pero para eso deberia utilizar la funcion cantReg y asi saber la cantidad de registros del archivo
