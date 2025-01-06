/*Parcial Mendez K1041*/

//Estructuras que te dan:
struct ataque //-->Registro del archivo
{
   int tipo; //0 - Tanque, 1 - Tropas, 2 - Caza, 3 - Bombardero, 4 - Destructor, 5 - Acorazado, 6 - Submarino
   int intensidad;
   int resistencia;
   int idAtacante;
   float minutoJuego;
};
struct zonaTerreno
{
   int tipoTerreno; //0 - mar, 1 - tierra
   int idZona;
};

//Punto A-

struct nodosublista
{
	ataque info;
	nodosublista*sgte;
};

struct infoNodo
{
	zonaTerreno dato;
	nodosublista*sublista;
};

struct nodoZonaTerreno
{
	infoNodo info;
	nodoZonaTerreno*sgte;
};

//Punto B-

nodoZonaTerreno*buscarZonaTerreno(nodoZonaTerreno*&listaP,int idBuscado)
{
	nodoZonaTerreno*aux=listaP;
	while(aux!=NULL&&aux->info.dato.idZona!=idBuscado)
	{
		aux=aux->sgte;
	}
	return aux;
}

//Punto C-
void cargarAtaques(FILE*archivo,int idBuscado,nodoZonaTerreno*&listaP)
{
	archivo=fopen("ATAQUES.DAT","rb");
	ataque aux1;
	while(fread(&aux1,sizeof(ataque),1,archivo))
	{
		insertarOrdenado(buscar(listaP,idBuscado).info.sublista,aux1); //por min de juego
	}
}

//Punto D-
ataque lanzarAtaque(nodoZonaTerreno *&listaP, int idZona)
{
	ataque aux;
	aux.tipo=-1;
	if(buscar(listaP,idBuscado).info.sublista!=NULL)
	{
		return buscar(listaP,idBuscado)->info.sublista->info;
	}
	else
	{
		return aux;
	}

}
