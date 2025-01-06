//Integrador 2023 (recu 1)

/*Teoria: 
1-Un vector es una estructura que almacena datos del mismo tipo en espacios contiguos en memoria en donde se sabe la cantidad (maxima al menos) de espacios a utilizar
Un archivo es una estructura que contiene diferentes registros uno al lado del otro sin saber cuantos contiene ni cual es el siguiente, se puede leer y escribir
2-Una funcion es una invocacion a una accion en específico mientras que un procedimiento es un conjunto de acciones o funciones que generan un programa*/
//3-Estructura:
struct infoNodo
{
	char nombreEquipo[20+1];
	int puntos;
	int cantPartidosJugados;
	int GR;
	int GM;
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

//Parte practica:
//Punto 1:
float determinarPromedio(int& nota1,int& nota2,int& nota3)
{
	float promedio=(nota1+nota2+nota3)/3;
	return promedio;
}

struct nodo
{
	int info;
	nodo*sgte;
};

int generarVector()
{
	nodo*lista=NULL;
	int aux,n=0,i=0;
	cout<<"Ingrese un valor: ";
	cin>>aux;
	while(aux!=0)
	{
		insertarOrdenado(lista,aux);
		n++;
		cout<<"Ingrese un valor: ";
	    cin>>aux;
	}
	int vector[n];
	while(lista!=NULL)
	{
		aux=pop(lista);
		vector[i]=aux;
		i++;
	}
}

//Punto 2:
struct nodoLista
{
	int info;
	nodoLista*sgte;
};

struct nodoCola
{
	int info;
	nodoCola*sgte;
};

nodoLista*unionColas(nodoCola*&cfteA,nodoCola*&cfinA,nodoCola*&cfteB,nodoCola*&cfinB)
{
	nodoLista*lista=NULL;
	int aux1=unqueue(cfteA,cfinA);
	int aux2=unqueue(cfteB,cfinB);
	while(cfteA!=NULL && cfinB!=NULL)
	{
		if(aux1==aux2)
		{
			insertarOrdenado(lista,aux1);
		    aux1=unqueue(cfteA,cfinA);
	        aux2=unqueue(cfteB,cfinB);
		}
		else if(aux1>aux2)
		{
			insertarOrdenado(lista,aux2);
			aux2=unqueue(cfteB,cfinB);
		}
		else
		{
			insertarOrdenado(lista,aux1);
			aux1=unqueue(cfteA,cfinA);
		}
	}
	while(lista!=NULL)
	{
		insertarOrdenado(lista,aux1);
		aux1=unqueue(cfteA,cfinA);
	}
	while(pila!=NULL)
	{
		insertarOrdenado(lista,aux2);
		aux2=unqueue(cfteB,cfinB);
	}
}

nodoLista*crearLista(nodoLista*&lista,nodoCola*&cfte,nodoCola*&cfin)
{
	nodo*listaFinal=NULL;
	int aux1,aux2;
	aux1=pop(lista);
	aux2=unqueue(cfte,cfin);
	while(lista!=NULL && cfte!=NULL)
	{
		if(aux1==aux2)
		{
			insertarDelante(listaFinal,aux1);
			aux1=pop(lista);
		    aux2=unqueue(cfte,cfin);
		}
		else if(aux1<aux2)
		{
			aux1=pop(lista);
		}
		else
		{
			aux2=unqueue(cfte,cfin);
		}
	}
	return listaFinal;
} 

//Punto 3:
struct regVector
{
	int codProvincia;
	int cantVotos;
	char partido;
};

struct prom
{
	int codProvincia;
	float votos;
};

void informe(regVector v[])
{
	int i,j,votosA=0,votosB=0,contador=0,max=v[0].cantVotos,codMax=v[0].codProvincia;
	char maxP=v[0].partido;
	prom promedios[24];
	for(i=0;i<48;i++)
	{
		if(v[i].cantVotos>max)
		{
			max=v[i].cantVotos;
			maxP=v[i].partido;
			codMax=v[i].codProvincia;
		}
		
		if(v[i].partido=="A")
		{
			votosA+=v[i].cantVotos;
		}
		else
		{
			votosB+=v[i].cantVotos;
		}
		
		if(contador%2==0)
		{
			promedio[j].codProvincia=v[i].codProvincia;
			promedio[j].votos+=votosB;
		}
		contador++;
	}
	cout<<"Votos del partido A: "<<votosA<<endl;
	cout<<"Promedio de votos por provincia del partido B: "<<endl;
	for(int k=0;k<24;k++)
	{
		cout<<"Provincia: "<<promedio[k].codProvincia<<" "<<(promedio[k].votos/votosB)*100<<endl;
	}
	cout<<"Mayor cantidad de votos: "<<max<<" provincia: "<<codMax<<" partido: "<<maxP;
}


