/*2do Recu Algoritmos*/

struct infoArchivo
{
	int numSector;
	int dia;
	char detalle[20+1];
	int importe;
};

struct infoNodo
{
	int importe;
	char detalle[20+1];
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

//Punto 1:

void cargarEstructura(FILE*archivo,nodo* m[15][31])
{
	archivo=fopen("Gastos.dat","rb");
	infoArchivo aux;
	infoNodo aux2;
	while(fread(&aux,sizeof(infoArchivo),1,archivo))
	{
		aux2.importe=aux.importe;
		strcpy(aux2.detalle,aux.detalle);
		insertarOrdenado(m[aux.numSector-1][aux.dia-1],aux2); //ordenado por importe
	}
	fclose(archivo);
}

//Punto 2:

void mostrarGastos(nodo* m[15][31])
{
	int i,j;
	nodo*aux=m;
	for(i=0;i<15;i++)
	{
		cout<<"Sector "<<i+1<<endl;
		for(j=0;j<31;j++)
		{
			cout<<"Dia "<<j+1<<endl;
			while(aux[i][j]!=NULL)
			{
				cout<<"Detalle: "<<aux[i][j]->info.detalle<<endl;
				cout<<"Importe: "<<aux[i][j]->info.importe<<endl;
				aux=aux->sgte;
			}
		}
	}
	liberar(aux);
}

//Punto 3:

void mayorGasto(nodo* m[15][31])
{
	int mayor=m[0][0]->info.importe,i,j;
	int sec,dia;
	nodo*aux=m;
	for(i=0;i<15;i++)
	{
		for(j=1;j<31;j++)
		{
			while(aux[i][j]!=NULL)
			{
				if(aux[i][j]->info.importe>mayor)
				{
					mayor=aux[i][j]->info.importe;
					sec=i;
					dia=j;
				}
				aux=aux->sgte;
			}
		}
	}
	liberar(aux);
	cout<<"Sector "<<sec+1<<" en el dia "<<dia+1<<endl;
}
