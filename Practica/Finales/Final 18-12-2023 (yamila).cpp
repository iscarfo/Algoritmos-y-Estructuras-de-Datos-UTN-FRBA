//FINAL yamila 18/12/2023

//Punto 1:
//Precondicion: pila y cola ordenadas inversamente
struct nodo
{
	int info;
	nodo*sgte;
};

nodo*crearLista(nodo*&pila,nodo*&cfte,nodo*&cfin)
{
	nodo*lista=NULL;
	int aux1,aux2;
	aux1=pop(pila);
	aux2=unqueue(cfte,cfin);
	while(pila!=NULL&&cfte!=NULL)
	{
		if(aux1==aux2)
		{
			insertarOrdenado(lista,aux1);
			aux1=pop(pila);
		    aux2=unqueue(cfte,cfin);
		}
		else if(aux1<aux2)
		{
			aux1=pop(pila);
		}
		else
		{
			aux2=unqueue(cfte,cfin);
		}
	}
	return lista;
}

//Punto 2:
struct alumno
{
	int legajo;
	int nota1;
	int nota2;
};

struct infoLista
{
	int legajo;
	int nota;
};

struct nodo
{
	infoLista info;
	nodo*sgte;
};

void actualizarNotas(nodo*&lista,alumno vec[])
{
	infoLista aux1;
	int i;
	while(lista!=NULL)
	{
		aux1=pop(lista);
	
	    if(aux1.nota>=6)
	    {
		    i=busquedaBinaria(vec,1500,aux1.legajo);
		    vec[i].nota2=aux1.nota;
	    }
	}
}

/*Punto 3:

1-muestra: 2 3 1
2-muestra: 31*/

/*Punto 4:
1-V, el apareo es un algoritmo que permite generar un tercer conjunto juntando dos conjuntos sin perder el orden de ambos, por ende, los elementos unicos de cada conj tambien se incluyen
2-V, el corte de control necesita de un orden previo para agrupar sin claves repetidas para que no cambie el control*/


