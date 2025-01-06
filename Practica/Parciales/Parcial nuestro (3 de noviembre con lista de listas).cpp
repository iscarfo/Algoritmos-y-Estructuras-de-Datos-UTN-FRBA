/*Primer parcial curso K1023*/

//Punto 1:

struct regArchivo //(sin orden)
{
	int horaInicio;
	int horaFin;
	int idEstacion;
	int dia;
	int mes;
	int idLocalidad;
};

struct regVector
{
	char nombreLocalidad[30+1];
	int cantHabitantes;
};

struct infoLS
{
	char nombreLocalidad[30+1];
	int horasCorte;
	int unidadesMulta;
};

struct nodoLS
{
	infoLS info;
	nodoLS*sgte;
};

struct infoLP
{
	int mes;
	float horasPromedioCorte;
	nodoLS*sublista;
};

struct nodoLP
{
	infoLP info;
	nodoLP*sgte;
};

//Punto 2:
void enlistar(FILE*archivo,regVector v[])
{
	nodoLP*lista=NULL;
	regArchivo aux1;
	infoLP aux2;
	int suma[12];
	int cantCortes[12];
	for(int i=0;i<12;i++)
	{
		suma[i]=0;
		cantHoras[i]=0;
	}
	while(fread(&aux1,sizeof(regArchivo),1,archivo))
	{
		aux2.mes=aux1.mes;
		aux2.sublista->info.horasCorte=(aux1.horaFin-aux1.horaInicio)/100;
		suma[aux2.mes-1]+=aux2.sublista->info.horasCorte;
		cantCortes[aux2.mes-1]++;
		strcpy(aux2.sublista->info.nombreLocacalidad,v[aux1.idLocalidad].nombreLocalidad);
		insertarOrdenado(lista,aux2); //Ordenado por id localidad
	}
	float promedioCorte[12];
	for(int i=0;i<12;i++)
	{
		promedioCorte[i]=suma[i]/cantCortes[i];
	}
	
	nodoLP*auxListado=lista;
	int i=0;
	while(auxListado!=NULL)
	{
		cout<<"Mes: "<<auxListado->info.mes<<endl;
		cout<<"Promedio corte: "<<promedioCorte[i]<<endl;
		while(auxListado->info.sublista!=NULL)
		{
			cout<<"Nombre de la Localidad: "<<auxListado->info.sublista->info.nombreLocalidad<<endl;
			cout<<"Total de horas de corte: "<<auxListado->info.sublista->info.horasCorte<<endl;
		if(auxListado->info.sublista.horasCorte<3)
		{
			cout<<"No se calcula multa"<<endl;
		}
		else if(auxListado->info.sublista.horasCorte>=3&&auxListado->info.sublista.horasCorte<=6)
		{
			cout<<"Unidades de multa: "<<auxListado->info.sublista.horasCorte*8<<endl;
		}
		else if(auxListado->info.sublista.horasCorte>6)
		{
			cout<<"Unidades de multa: "<<auxListado->info.sublista.horasCorte*12<<endl;
		}
		auxListado->info.sublista=auxListado->info.sublista->sgte;
		}
		i++;
		auxListado=auxListado->sgte;
	}
}
