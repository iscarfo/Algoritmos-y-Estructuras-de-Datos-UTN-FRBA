//FINAL 23/09/2021

/*El partido está dividido en cuatro localidades: Pinamar, Carilo, Ostende y Valeria del mar. Se presentan cinco listas [1..5]. 
Los votos para cada par [partido, numero de lista] están en un archivo binario de 20 registros cada uno de los cuales con:  
localidad: 20 caracteres, numero de lista: 1..5, votos validos: entero.*/

//Punto 1:
struct vec
{
	char localidad[20+1];
};
int matriz[4][5];

vec vector[4];
strcpy(vector[0].localidad,"Pinamar");
strcpy(vector[1].localidad,"Carilo");
strcpy(vector[2].localidad,"Ostende");
strcpy(vector[3].localidad,"Valeria del Mar");

struct regArchivo
{
	char localidad[20+1];
	int votosValidos;
	int lista;
};
FILE*datos=fopen("VOTOS.DAT","rb"); //Archivo declarado

//Punto 2:
void imprimir(FILE*datos,int matriz[][5]);

//Punto 3:
void imprimir(FILE*datos,int matriz[][5],vector[])
{
	//Inicializo la matriz en 0...
	regArchivo aux;
	int cantVotos[4]=0;
	while(fread(&aux,sizeof(regArchivo),1,datos))
	{
		if(strcmp(aux.localidad,"Pinamar")==0)
		{
			matriz[0][aux.lista-1]=aux.votosValidos;
			cantVotos[0]+=aux.votosValidos;
		}
		else if(strcmp(aux.localidad,"Carilo")==0)
		{
			matriz[1][aux.lista-1]=aux.votosValidos;
			cantVotos[1]+=aux.votosValidos;
		}
		else if(strcmp(aux.localidad,"Ostende")==0)
		{
			matriz[2][aux.lista-1]=aux.votosValidos;
			cantVotos[2]+=aux.votosValidos;
		}
		else
		{
			matriz[3][aux.lista-1]=aux.votosValidos;
			cantVotos[3]+=aux.votosValidos;
		}
	}
	fclose(datos);
	int i,j;
	float porcentaje[5];
	for(i=0;i<4;i++)
	{
		cout<<"Localidad: "<<vector[i].localidad<<endl;
		for(j=0;j<5;j++)
		{
			porcentaje[j]=(matriz[i][j]/cantVotos[i])*100;
			cout<<"Lista: "<<j+1<<" "<<(matriz[i][j]/cantVotos[i])*100;
			if(porcentaje[j]>50)
			{
				cout<<"Lista ganadora"<<endl;
			}
		}
		
	}
	
}

/*Parte teorica:
A-SI, ya que se podria hacer PUP con el indice de la localidad
B-vector de listas de 4 posiciones 
C-lista de listas*/
