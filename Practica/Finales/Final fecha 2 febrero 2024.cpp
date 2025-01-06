//FINAL febrero 2024

//Punto 1:
struct nodoLista
{
	int info;
	nodoLista*sgte;
};

struct nodoPila
{
	int info;
	nodoPila*sgte;
};

//PILA Y LISTA ORDENADAS

nodoLista*crearListaOrdenada(nodoLista*lista,nodoPila*pila)
{
	nodoLista*listaFinal=NULL;
	int aux1,aux2;
	aux1=pop(pila);
	aux2=pop(lista);
	while(lista!=NULL && pila!=NULL)
	{
		if(aux1==aux2)
		{
			insertarOrdenado(listaFinal,aux1);
			aux1=pop(pila);
			aux2=pop(lista);
		}
		else if(aux1<aux2)
		{
			aux1=pop(pila);
		}
		else
		{
			aux2=pop(lista);
		}
	}
}

//Punto 2:
struct vecSaldos
{
	int numCuenta;
	int cantTransacciones;
	int saldo;
};

struct infoNodo
{
	int numCuenta;
	int monto;
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

void actualizarVector(vecSaldos v[],nodo*&lista)
{
	int i;
	infoNodo aux;
	while(lista!=NULL)
	{
		aux=pop(lista);
		i=busquedaBinaria(v,150,aux.numCuenta);
		v[i].cantTransacciones++;
		v[i].saldo-=aux.monto;
	}
}

//Punto 3:
//1- Muestra 10 31 43
//2- Muestra 24

/*Punto 4:
1-FALSO, la forma de pasar por referencia alguna estructura de datos es con el &, sin emabrgo el vector siempre pasa por referencia: int vector[]
2-FALSO, el apareo se puede utilizar en todas las estructuras de datos como estrategia para crear una tercera estructura a partir de otras dos manteniendo el criterio de orden*/
