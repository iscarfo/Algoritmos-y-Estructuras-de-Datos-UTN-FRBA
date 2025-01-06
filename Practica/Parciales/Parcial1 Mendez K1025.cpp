/*Parcial Mendez K1025*/

//Estructura que te dan:
struct Ataque //-->registro del archivo
{
int tipo; //0- Tanque, 1 - Tropas, 2 - Caza, 3 - Bombardero, 4 - Destructor, 5 - Acorazado, 6 - Submarino
int intensidad;
int resistencia;
int IDAtacante;
};

//Punto A-

struct infoCola
{
	int tipo;
    int intensidad;
    int resistencia;
    int idAtacante;
};

struct nodoCola
{
	infoCola info;
	nodoCola*cola;
};

struct zonaAtaque
{
	int tipoTerreno;
	nodoCola*colaAtaques;
};

zonaAtaque matriz[100][100];

//Punto B-
void queue(nodoCola*&fte,nodoCola*&fin,infoCola valor)
{
	.... //procedimiento
}

//Punto C-
void cargarAtaques(FILE*archivo,int i,int j,int tipoAtaque,zonaAtaque matriz[100][100])
{
	archivo=fopen("ATAQUES.DAT","rb");
	Ataque aux1;
	while(fread(&aux1,sizeof(Ataque),1,archivo))
	{
		if(aux1.tipo==tipoAtaque)
		{
			queue(matriz[i][j].colaAtaques,aux1);
		}
	}
	fclose(archivo);
	
}

//Punto D-
Ataque lanzarAtaque(ZonaAtaque matriz[][100], int fila, int columna)
{
	Ataque aux=unqueue(matriz[fila][columna].colaAtaques);
	return aux;
}
