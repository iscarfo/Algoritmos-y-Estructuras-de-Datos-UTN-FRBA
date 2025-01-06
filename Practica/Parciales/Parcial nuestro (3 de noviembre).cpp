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

struct nodoArchivo //para ordenar el archivo
{
	regArchivo info;
	nodoArchivo*sgte;
};

struct regVector
{
	char nombreLocalidad[30+1];
	int cantHabitantes;
};

//Punto 2:

void enlistar(FILE*archivo,regVector v[])
{
	archivo=fopen("cortes.dat","rb");
	regArchivo auxOrden;
	nodoArchivo*orden=NULL;
	while(fread(&auxOrden,sizeof(regArchivo),1,archivo))
	{
		insertarOrdenado(orden,auxOrden); //Ordenas el archivo por idLocalidad y mes
	}
	fclose(archivo);
	
	
	float promedioCorte[12];
	int suma[12];
	int cantCortes[12];
	for(int i=0;i<12;i++)
	{
		cantCortes[i]=0;
		suma[i]=0;
	}
	int horasXmes=720;
	nodoArchivo*auxListadoProm=orden;
	
	while(auxListadoProm!=NULL)
	{
		suma[auxListadoProm->info.mes-1]+=auxListadoProm->info.horasCorte;
		cantCortes[auxListadoProm->info.mes-1]++;
		auxListadoProm=auxListadoProm->sgte;
	}
	liberar(auxListadoProm);
	
	for(int i=0;i<12;i++)
	{
		promedioCorte[i]=suma[i]/cantCortes[i];
	}
	
	
	
	nodoArchivo*auxListado=orden;
	while(auxListado!=NULL)
	{
		cout<<"Mes: "<<auxListado->info.mes<<endl;
		cout<<"Horas promedio de corte de este mes: "<<promedioCorte[auxListado->info.mes-1]<<endl;
		cout<<"Localidad: "<<v[auxListado->info.idLocalidad].nombreLocalidad<<endl;
		cout<<"Total de horas de corte: "<<(auxListado->info.horaFin-auxListado->info.horaInicio)/100<<endl;
		if(auxListado->info.horaFin-auxListado->info.horaInicio<3000)
		{
			cout<<"No se calcula multa"<<endl;
		}
		else if(auxListado->info.horaFin-auxListado->info.horaInicio>=3000&&auxListado->info.horaFin-auxListado->info.horaInicio<=6000)
		{
			cout<<"Unidades de multa: "<<((auxListado->info.horaFin-auxListado->info.horaInicio)/100)*8<<endl;
		}
		else if(auxListado->info.horaFin-auxListado->info.horaInicio>6000)
		{
			cout<<"Unidades de multa: "<<((auxListado->info.horaFin-auxListado->info.horaInicio)/100)*12<<endl;
		}
		auxListado=auxListado->sgte;
	}
	liberar(auxListado);
}
