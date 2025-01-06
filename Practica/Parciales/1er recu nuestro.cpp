/*2do Parcial Aloritmos*/

//Estructuras: 

struct infoNodo
{
	char detalle[20+1];
	float importe;
	char otrosDatos[30+1];
};

struct infoArchivo
{
	int sucursal;
	int dia;
	char detalle[20+1];
	float importe;
	char otrosDatos[30+1];
};

struct nodoMatriz
{
	infoNodo info;
	nodoMatriz*sgte;
};

//Punto 1:
void generarEstructura(FILE*archivo,nodoMatriz*matrizfte[][31],nodoMatriz*matrizfin[][31])
{
	archivo=fopen("IMPORTES.DAT","rb");
	infoArchivo aux;
	infoNodo aux2;
	while(fread(&aux,sizeof(infoArchivo),1,archivo))
	{
		strcpy(aux2.detalle,aux.detalle);
		aux2.importe=aux.importe;
		strcpy(aux2.otrosDatos,aux.otrosDatos);
		queue(matrizfte[aux.sucursal-1][aux.dia-1],matrizfin[aux.sucursal-1][aux.dia-1],aux2);
	}

} //En este caso elegi una cola porque me pide que el orden sea igual al que venia y una matriz porque es estatica y de dos dimensiones

//Punto 2:
void mostrarImportesSucursal(nodoMatriz*matrizfte[][31],nodoMatriz*matrizfin[][31])
{
	int total=0,suma=0,i=0,j=0;
	nodoMatriz*auxfte=matrizfte;
	nodoMatriz*auxfin=matrizfin;
	infoNodo aux;
	for(i=0;i<20;i++)
	{
		cout<<"Sucursal "<<i+1<<endl;
		for(j=0;j<31;j++)
		{
			while(auxfte[i][j]!=NULL)
			{
				aux=unqueue(auxfte[i][j],auxfin[i][j]);
				total++;
				suma+=aux.importe;
				auxfte[i][j]=auxfte[i][j]->sgte;
			}
		}
		cout<<"Total de trasacciones: "<<total<<endl;
		cout<<"Importe: "<<suma<<endl;
	}
} //La misma ya que se puede ordenar por sucursal por la matriz

//Punto 3:
float menorImporte(nodoMatriz*matrizfte[][31],nodoMatriz*matrizfin[][31])
{
	int i=0,j=0;
	float menor[20];
	nodoMatriz*auxfte=matrizfte;
	nodoMatriz*auxfin=matrizfin;
	infoNodo aux;
	aux=unqueue(auxfte[i][j],auxfin[i][j]);
	menor=aux.importe;
	for(i=0;i<20;i++)
	{
		aux=unqueue(auxfte[i][j],auxfin[i][j]);
	    menor[i]=aux.importe;
		for(j=1;j<31;j++)
		{
			while(auxfte[i][j]!=NULL)
			{
				aux=unqueue(auxfte[i][j],auxfin[i][j]);
				if(menor[i]<aux.importe)
				{
					menor[i]=aux.importe;
				}
			}
		}
	}
	return menor;
} //un vector ya que se puede hacer PUP con las 20 sucursales
