/*Final GPS*/

//Punto 1:
struct coord
{
	int alt;
	int lat;
	int lon;
};

struct recorrido
{
	coord inicioTramo;
	coord finTramo;
	int ruta;
	int tramo;
	int velocidad; //KM/H
	int minDemora;
};

//se tiene:
int distancia (int,int,int,int,int,int); //-->calcula la distancia entre dos puntos

//Punto 2:
int calcularTiempoDeLlegada(recorrido v[],int N,coord salida,coord destino)
{
	int distanciaObj=distancia(salida.alt,salida.lat,salida.lon,destino.alt,destino.lat,destino.lon);
	int posicionBuscada=busquedaBinaria(v,N,salida,destino);
	return (distanciaObj/v[posicionBuscada].velocidad)+v[posicionBuscada].minDemora;
}

//Punto 3:
//A- Para hacerlo, sacaría la distancia entre esos puntos con la funciones "distancia" y a partir de eso ya podría usar la funcion calcularTiempoDeLlegada
//B- Estando en una estructura enlazada, si en el caso de la lista podría hacer el mismo procedimiento recorriendola pero en vez de usar busquedaBin usaria "buscar"
//C-Si estaria con un archivo sin orden sería mas dificil ya que se podría recorrer al archivo de forma secuencial, pero lo mas facil sería ordenar el archivo con una lista
//(insertarOrdenado) y a partir de ahí maniobrarlo ya sea desde la lista o a partir del archivo ya ordenado
