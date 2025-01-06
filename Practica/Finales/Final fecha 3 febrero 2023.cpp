//FINAL fecha3

/*Punto 1:
La estructura que utilizare sera un vector de listas, elegí un vector debido a que existen 20 operadores de buceo (n) y al saber la cantidad es mejor usar un vector
y elegi las listas debido a que no sabes cuantos viajes puede haber por operador*/

struct regArchivo
{
	char operadoraBuceo[20+1];
	int dniBuzo;
	int edad;
	char paisOrigen[20+1];
	int diaSalida;
	int mesSalida;
	int anioSalida;
    char sitioBuceo[20+1];
    char nivelDificultad[6+1]; //ALTA MEDIA O BAJA
	int profundidadMax; //Metros
	int tiempoBuceo; //Mins
    int horaInicio; //a partir de las 19.00hs se considera buceo nocturno

};

struct infoNodo
{
	char paisOrigen[20+1];
	int profundidadMax; 
    int horaInicio;
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

struct regVector
{
	char operadoraBuceo[20+1];
	nodo*lista;
};

//Punto 2:
void cargarEstructura(FILE*archivo,regVector v[])
{
	regArchivo aux1;
	infoNodo aux2;
	int i=0,j;
	archivo=fopen("buceosGalápagos2022.dat","rb");
	while(fread(&aux1,sizeof(regArchivo),1,archivo))
	{
		if(busquedaBinaria(v,20,aux1.operadoraBuceo)==-1)
		{
			v[i].operadoraBuceo=aux1.operadoraBuceo;
			i++;
			aux2.profundidadMax=aux1.profundidadMax;
			aux2.horaInicio=aux1.horaInicio;
			strcpy(aux2.paisOrigen,aux1.paisOrigen);
			insertarOrdenado(v[i].lista,aux2);
		}
		else
		{
			j=busquedaBinaria(v,20,aux1.operadoraBuceo);
			aux2.profundidadMax=aux1.profundidadMax;
			aux2.horaInicio=aux1.horaInicio;
			strcpy(aux2.paisOrigen,aux1.paisOrigen);
			insertarOrdenado(v[j].lista,aux2);
		}
	}
	fclose(archivo);
}

//Punto 3:
void listarEstadisticas(regVector v[])
{
	int i,cantBuceosP,cantBuceosNoct;
	for(i=0;i<20;i++)
	{
		cantBuceosP=0;
		cantBuceosNoct=0;
		cout<<v[i].operadoraBuceo<<endl;
		cout<<"Recibio buzos de: "<<endl;
		while(v[i].lista!=NULL)
		{
			cout<<mostrarSinRepetir(v[i].lista,v[i].lista->info.paisOrigen)<<endl;
			if(v[i].lista->info.horaInicio>=1900)
			{
				cantBuceosNoct++;
			}
			if(v[i].lista->info.profundidadMax>=30)
			{
				cantBuceosP++;
			}
		}
		cout<<"Cantidad de buceos nocturnos: "<<cantBuceosNoct<<endl;
		cout<<"Cantidad de buceos a mas de 30 metros: "<<cantBuceosP<<endl;
	}
}
