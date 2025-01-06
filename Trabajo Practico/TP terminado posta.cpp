#include <iostream>
#include <stdlib.h> 
#include <ctime>  //Para sacar el numero aleatorio
#include <cstring>
using namespace std;

//Estructuras:
struct Carta
{
    int num; 
    char palo[7];
};

struct nodo
{
	Carta info;
	nodo*sgte;
};

struct Jugador
{
    Carta mano[3];
    int puntaje;
    nodo*cartasLlevadas;
};

//Prototipos de funciones:
Carta pop(nodo*&);
void insertarPrimero(nodo*&,Carta);
void repartir1 (Carta[], Jugador&, Jugador&, nodo*&); //Al inicio (con 4 cartas para la mesa)
void repartir2 (Carta[], Jugador&, Jugador&); //Despues (solo 3 cartas para cada jugador)
void buscarYeliminar(nodo*&,Carta);
int buscarPuntos(Jugador&, nodo*&);
void contarPuntos(Jugador&,Jugador&);


int main()
{
    srand(time(NULL));

    //Inicializaciones para el juego:
	
	Jugador uno,dos;
	nodo *Mesa= NULL;
    int ronda = 0;
    uno.puntaje = 0;
	dos.puntaje =0;
	uno.cartasLlevadas = NULL;
	dos.cartasLlevadas = NULL;
	
	
	//Arranca el algoritmo
    while(uno.puntaje < 15 && dos.puntaje < 15)
	{
		//Inicializamos la baraja de cartas para jugar.-->el 8, 9 y 10 representarian el 10,11 y 12
        Carta Baraja[] = {{1,"ORO"},{2,"ORO"},{3,"ORO"},{4,"ORO"},{5,"ORO"},{6,"ORO"},{7,"ORO"},
        {8,"ORO"},{9,"ORO"},{10,"ORO"},{1,"COPA"},{2,"COPA"},{3,"COPA"},{4,"COPA"},{5,"COPA"},
        {6,"COPA"},{7,"COPA"},{8,"COPA"},{9,"COPA"},{10,"COPA"},{1,"BASTO"},{2,"BASTO"},{3,"BASTO"},
        {4,"BASTO"},{5,"BASTO"},{6,"BASTO"},{7,"BASTO"},{8,"BASTO"},{9,"BASTO"},{10,"BASTO"},{1,"ESPADA"},
        {2,"ESPADA"},{3,"ESPADA"},{4,"ESPADA"},{5,"ESPADA"},{6,"ESPADA"},{7,"ESPADA"},{8,"ESPADA"},
        {9,"ESPADA"},{10,"ESPADA"}};

		repartir1(Baraja, uno, dos, Mesa);
		while(ronda < 6)
		{
			buscarPuntos(uno, Mesa);
			buscarPuntos(dos, Mesa);
			buscarPuntos(uno, Mesa);
			buscarPuntos(dos, Mesa);
			buscarPuntos(uno, Mesa);
			buscarPuntos(dos, Mesa);
			ronda++;
			if(ronda != 6)
			{
				repartir2(Baraja, uno, dos);
			}
		}
		//Hacer que las ultimas cartas de la mesa se las lleve el ultimo que levanto
		Carta salida;
		if(buscarPuntos(dos, Mesa) == -1)
		{
			while(Mesa != NULL)
			{
				salida = pop(Mesa);
				insertarPrimero(uno.cartasLlevadas, salida);
			}
		}
		else
		{
			while(Mesa != NULL)
			{
				salida = pop(Mesa);
				insertarPrimero(dos.cartasLlevadas, salida);
			}
		}
		contarPuntos(uno, dos);
		ronda = 0;
    }
    
	//Definir Ganador
	if(uno.puntaje >= 15)
	{
		cout<<"Ganador: Jugador 1"<<endl;
    }
    else if (dos.puntaje >= 15)
	{
		cout<<"Ganador: Jugador 2"<<endl;
    }
    
    return 0;

}

//Funciones deasrrolladas:
Carta pop(nodo*&lista)
{
	if(lista != NULL){
		Carta ret;
		ret.num = lista -> info.num;
		strcpy(ret.palo, lista -> info.palo);
		nodo *aux = lista;
		lista = aux -> sgte;
		delete (aux);
		return ret;
	}
}

void insertarPrimero(nodo*&lista, Carta valor)
{
	nodo* nuevo = new nodo();
	nuevo -> info.num = valor.num;
	strcpy(nuevo -> info.palo, valor.palo);
	nuevo -> sgte = lista;
	lista = nuevo;
}


void repartir1 (Carta Mazo[], Jugador &primero, Jugador &segundo, nodo*& Mesa){
    int num_random = 0, i = 0, j = 0, k = 0;
    
    while(i < 3 || j < 3 || k < 4)
	{
        num_random = rand()%40; //Un numero random desde 0-39 (los indices del vector)
	
		//Le repartis las cartas al primer jugador
    	while(Mazo[num_random].num != 0 && i < 3)
		{
        	primero.mano[i] = Mazo[num_random];
        	Mazo[num_random].num = 0;
        	i++;
    	}
    
    	//Le repartis las cartas al segundo jugador
    	while(Mazo[num_random].num !=0 && j < 3)
		{
        	segundo.mano[j] = Mazo[num_random];
        	Mazo[num_random].num = 0;
        	j++;
    	}
    	//Le repartis las cartas a la mesa
    	while(Mazo[num_random].num !=0 && k < 4)
		{
        	insertarPrimero(Mesa,Mazo[num_random]);
        	Mazo[num_random].num = 0;
			k++;
    	}
    }
}

void repartir2 (Carta Mazo[], Jugador &primero, Jugador &segundo){
    int num_random = 0, i = 0, j = 0;
    
    while(i < 3 || j < 3 )
	{
        num_random = rand()%40;
        
		//Le repartis las cartas al primer jugador
    	while(Mazo[num_random].num != 0 && i < 3 )
		{
        	primero.mano[i] = Mazo[num_random];
        	Mazo[num_random].num = 0;
        	i++;
    	}
    
    	//Le repartis las cartas al segundo jugador
    	while(Mazo[num_random].num != 0 && j < 3)
		{
        	segundo.mano[j] = Mazo[num_random];
        	Mazo[num_random].num = 0;
        	j++;
    	}
    }
}

void buscarYeliminar(nodo*& Mesa, Carta sacada)
{
    nodo* aux = Mesa;
    nodo* anterior = NULL;

    while ( (aux != NULL)  &&  (sacada.num != aux -> info.num || strcmp(sacada.palo, aux->info.palo) != 0) )
    {
        anterior = aux;
        aux = aux -> sgte;
    }

    if (aux != NULL)
    {
        if (anterior == NULL)
        {
            Mesa = aux -> sgte;
        }
        else
        {
            anterior -> sgte = aux -> sgte;
        }

        delete aux;
    }
}

int buscarPuntos(Jugador &primero, nodo*& Mesa)
{
	int i, j, agarre = 0;
	nodo*aux;
	for( i=0 ; i<3 ; i++)
	{
	  aux=Mesa;
	  while(aux!=NULL)
	  {
		if( (aux->sgte != NULL && aux->sgte->sgte != NULL) && (aux->sgte->sgte->sgte != NULL && aux->info.num + aux->sgte->info.num + aux->sgte->sgte->info.num
		+ aux->sgte->sgte->sgte->info.num + primero.mano[i].num == 15 && primero.mano[i].num != 0)) //combinatoria de cinco cartas
		{
			insertarPrimero(primero.cartasLlevadas, aux->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->sgte->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->sgte->sgte->info);
			insertarPrimero(primero.cartasLlevadas, primero.mano[i]);
			buscarYeliminar(Mesa, aux->info);
			buscarYeliminar(Mesa, aux->sgte->info);
			buscarYeliminar(Mesa, aux->sgte->sgte->info);
			buscarYeliminar(Mesa, aux->sgte->sgte->sgte->info); //sacas las cartas de la mesa
			primero.mano[i].num = 0; //descartas la carta de tu mano
			agarre = 1;
		}
		else if ( aux->sgte != NULL && aux->sgte->sgte != NULL && aux->info.num + aux->sgte->info.num + aux->sgte->sgte->info.num
		+ primero.mano[i].num == 15 && primero.mano[i].num != 0) //combinatoria de cuatro cartas
		{
			insertarPrimero(primero.cartasLlevadas, aux->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->sgte->info);
			insertarPrimero(primero.cartasLlevadas, primero.mano[i]);
			buscarYeliminar(Mesa, aux->info);
			buscarYeliminar(Mesa, aux->sgte->info);
			buscarYeliminar(Mesa, aux->sgte->sgte->info); //sacas las cartas de la mesa
			primero.mano[i].num = 0; //descartas la carta de tu mano
			agarre = 1;
		}
		else if ( aux->sgte != NULL && aux->info.num + aux->sgte->info.num + primero.mano[i].num == 15 && primero.mano[i].num != 0) //combinatoria de tres cartas
		{
			insertarPrimero(primero.cartasLlevadas, aux->info);
			insertarPrimero(primero.cartasLlevadas, aux->sgte->info);
			insertarPrimero(primero.cartasLlevadas, primero.mano[i]);
			buscarYeliminar(Mesa, aux->info);
			buscarYeliminar(Mesa, aux->sgte->info); //sacas las cartas de la mesa
			primero.mano[i].num = 0; //descartas la carta de tu mano
			agarre = 1;
		}
		else if ( aux->info.num + primero.mano[i].num == 15 && primero.mano[i].num != 0 ) //combinatoria de dos cartas (no se como hacer mas)
		{
			insertarPrimero(primero.cartasLlevadas, aux->info);
			insertarPrimero(primero.cartasLlevadas, primero.mano[i]);
			buscarYeliminar(Mesa, aux->info); //sacas la carta de la mesa
			primero.mano[i].num = 0; //descartas la carta de tu mano
			agarre = 1;
		}
		if (aux == NULL)
		{
			primero.puntaje++; //escoba
		}
		if (agarre == 1)
		{
			return 0; //Para saber si se agarro carta y cerrar la funcion
		}
		aux = aux->sgte;
	  }
	}
	
	//Descarte
	for(j=0; j<3; j++)
	{
		if(primero.mano[j].num != 0)
		{
			insertarPrimero(Mesa,primero.mano[j]);
	        primero.mano[j].num = 0;
	        return -1;
		}
	}
}

void contarPuntos(Jugador&primero, Jugador&segundo)
{
	int cantSietes = 0, cantCartas = 0, cantOros = 0;
	int cantSietes2 = 0, cantCartas2 = 0, cantOros2 = 0;
	Carta aux;
	while(primero.cartasLlevadas != NULL)
	{
		aux = pop(primero.cartasLlevadas);
		if (aux.num == 7)
		{
			cantSietes++;
			if ( strcmp(aux.palo, "ORO") == 0 )
			{
				primero.puntaje++;
				cantOros++;
			}
		}
		else if ( strcmp(aux.palo, "ORO") == 0  &&  aux.num != 7 )
		{
			cantOros++;
		}
		cantCartas++;
	}
	while (segundo.cartasLlevadas != NULL)
	{
		aux = pop(segundo.cartasLlevadas);
		if (aux.num == 7)
		{
			cantSietes2++;
			if ( strcmp(aux.palo, "ORO") == 0 )
			{
				segundo.puntaje++;
				cantOros2++;
			}
		}
		else if ( strcmp(aux.palo,"ORO") == 0  &&  aux.num != 7)
		{
			cantOros2++;
		}
		cantCartas2++;
	}
	
	if ( cantSietes > cantSietes2 )
	{
		primero.puntaje++;
	}
	else if ( cantSietes < cantSietes2 )
	{
		segundo.puntaje++;
	}
	
	if ( cantCartas > cantCartas2 )
	{
		primero.puntaje++;
	}
	else if ( cantCartas < cantCartas2 )
	{
		segundo.puntaje++;
	}
	
	if ( cantOros > cantOros2 )
	{
		primero.puntaje++;
	}
	else if ( cantOros < cantOros2 )
	{
		segundo.puntaje++;
	}
}
