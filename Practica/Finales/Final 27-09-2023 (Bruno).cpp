//FINAL 27-09-2023

//Estructuras dadas:
struct archVotos
{
    int provincia; 
    int partido;
	int localidad;
	int padron; 
	int blancos; 
	int impugnados; 
	int listas[5]; // listas contiene los votos validos de cada una de ellas.
};            

struct matrizVotos
{
    int padron; 
	int blancos; 
	int impugnados; 
	int listas[5];
};

matrizVotos Votos[24][10][20];      

//Punto 1:
void presidente(matrizVotos[][10][20]);
void gobernador(matrizVotos[][10][20]);    
void cargarEstructura(matrizVotos[][10][20],FILE*);

//Punto 2:
//cargarEstructura:
void cargarEstructura(matrizVotos Votos[][10][20],FILE*archivo)
{
	int i;
	archivo=fopen("VOTOS.DAT","rb");
	archVotos aux1;
	while(fread(&aux1,sizeof(archVotos),1,archivo))
	{
		Votos[aux1.provincia-1][aux1.partido-1][aux1.localidad-1].padron=aux1.padron;
		Votos[aux1.provincia-1][aux1.partido-1][aux1.localidad-1].blancos=aux1.blancos;
		Votos[aux1.provincia-1][aux1.partido-1][aux1.localidad-1].impignados=aux1.impugnados;
		for(i=0;i<5;i++)
		{
			Votos[aux1.provincia-1][aux1.partido-1][aux1.localidad-1].listas[i]=aux1.listas[i];
		}
	}
	fclose(archivo);
}

//Gobernador:
void gobernador(matrizVotos Votos[][10][20])
{
	int i,j,k,mayor,provMayor,cantVotos[5];

	for(i=0;i<24;i++)
	{
	    for(int z=0;z<5;z++)
	    {
		    cantVotos[z]=0;
	    }
		for(j=0;j<10;j++)
		{
			for(k=0;k<20;k++)
			{
				for(int y=0;y<5;y++)
				{
					cantVotos[y]+=Votos[i][j][k].lista[y];
				}
			}
		}
		mayor=cantVotos[0];
		cout<<"Gandor de la provincia "<<i+1<<": lista ";
		for(int z=1;z<5;z++)
	    {
		    if(cantVotos[z]>mayor)
			{
				mayor=cantVotos[z];
				provMayor=z;
		    }
	    }
	    cout<<provMayor+1<<endl;
	}
}

//Presidente: 
void presidente(matrizVotos Votos[][10][20])
{
	int i,j,k,listaMayor,listaSeg,cantVotosTotal;
	float cantVotos[5],mayor,segundo;

	for(int z=0;z<5;z++)
	{
		cantVotos[z]=0;
	}
	for(i=0;i<24;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<20;k++)
			{
				for(int y=0;y<5;y++)
				{
					cantVotos[y]+=Votos[i][j][k].lista[y];
					cantVotosTotal+=Votos[i][j][k].lista[y];
				}
			}
		}
	}
	//Saco porcentajes:
	for(int h=0;h<5;h++)
	{
		cantVotos[h]=(cantVotos[h]/cantVotosTotal)*100;
	}
	mayor=cantVotos[0];
	listaMayor=0;
	segundo=cantVotos[1];
	listaSeg=1;
	for(int z=0;z<5;z++)
	{
		if(cantVotos[z]>45)
		{
			cout<<"Lista ganadora: "<<z+1<<endl;
		}
		else if(cantVotos[z]>mayor)
		{
			segundo=mayor;
			listaSeg=listaMayor;
			mayor=cantVotos[z];
			listaMayor=z;
		}
		else if(cantVotos[z]<mayor && cantVotos[z]>segundo)
		{
			segundo=cantVotos[z];
			listaSeg=z;
		}
	}
	
	if(mayor>40 && segundo<(mayor-10))
	{
		cout<<"Lista Ganadora: "<<listaMayor+1<<endl;
	}
	else
	{
		cout<<"Segunda vuelta entre "<<listaMayor+1<<" y "<<listaSeg+1<<endl;
	}

}
