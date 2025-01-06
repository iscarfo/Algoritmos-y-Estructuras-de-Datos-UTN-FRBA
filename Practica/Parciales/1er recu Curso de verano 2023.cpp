/*1er Recu Curso de Verano 2023*/

//Estructuras que te dan:

struct regArchivo //-->ordenado por idUsuario (usuarios)
{
   int idUsuario;
   char nombreUsuario[250+1]; 
   char mail[100+1];
};

struct infoCola //-->Cola de visualizaciones
{
	int idPelicula;
	char nombrePelicula[100+1];
	int  idUsuario;
};

//Punto 1:

struct infoNodoLS
{
	int idPelicula;
	char nombrePelicula[100+1];
};

struct nodoLS
{
	infoNodoLS info;
	nodoLS*sgte;
};

struct infoNodoLP
{
	int idUsuario;
	char nombreUsuario[250+1];
	int cantPelisVistas;
	nodoLS*sublista;
};

struct nodoLP
{
	infoNodoLP info;
	nodoLP*sgte;
};


//Punto 2:
nodoLP*obtenerListaUsuarios(FILE*archivo)
{
	nodoLP*lista=NULL;
	regArchivo aux;
	infoNodoLP aux2;
	while(fread(&aux,sizeof(regArchivo),1,archivo))
	{
		aux2.idUsuario=aux.idUsuario;
		strcpy(aux2.nombreUsuario,aux.nombreUsuario);
		aux2.cantPelisVistas=0;
		aux2.sublista=NULL;
		insertarOrdenado(lista,aux2);
	}
	fclose(archivo);
	return lista;
}

//Punto 3:
void cargarLista(nodoLP*&lista,infoCola pelicula)
{
	nodoLP*aux=buscar(lista,pelicula.idUsuario);
	infoNodoLS aux2;
	aux2.idPelicula=pelicula.idPelicula;
	strcpy(aux2.nombrePelicula,pelicula.nombrePelicula);
	insertarOrdenado(aux->info.sublista,aux2); //ordenado por idPelicula
	aux->info.cantPelisVistas++;
}

//Punto 4
bool tienenGustosSimilares(nodoLS*&usuario1,nodoLS*&usuario2)
{
	nodoLS*aux1=usuario1;
	nodoLS*aux2=usuario2;
	int contador=0;
	while(aux1!=NULL&&aux2!=NULL)
	{
		if(aux1->info.idPelicula==aux2->info.idPelicula)
		{
			contador++;
			aux1=aux1->sgte;
			aux2=aux2->sgte;
		}
		else if(aux1->info.idPelicula<aux2->info.idPelicula)
		{
			aux1=aux1->sgte;			
		}
		else
		{
			aux2=aux2->sgte;			
		}
	}
	if(contador>=5)
	{
		return true;
	}
	else
	{
		return false;
	}
}
