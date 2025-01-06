//Integrador yamila 2022

//Punto 1:
void determinarPromocion(int& nota1,int& nota2)
{
	if(nota1>8 && nota2>8)
	{
		cout<<"Promociona"<<endl;
	}
	else
	{
		cout<<"No promociona"<<endl;
	}
}

void determinarCuatri(int& mes)
{
	if(mes<=4)
	{
		cout<<"Primer Cuatrimestre"<<endl;
	}
	else if(mes>4 && mes<=8)
	{
		cout<<"Segundo Cuatrimestre"<<endl;
	}
	else if(mes>8 && mes<=12)
	{
		cout<<"Tercer Cuatrimestre"<<endl;
	}
}

//Punto 2:
struct nodo
{
	int info;
	nodo*sgte;
};

nodo*crearLista(nodo*&lista,nodo*&pila)
{
	nodo*listaNueva=NULL;
	int aux1=pop(lista);
	int aux2=pop(pila);
	while(lista!=NULL && pila!=NULL)
	{
		if(aux1==aux2)
		{
			insertarDelante(lista,aux1);
		    aux1=pop(lista);
	        aux2=pop(pila);
		}
		else if(aux1>aux2)
		{
			insertarDelante(lista,aux2);
			aux2=pop(pila);
		}
		else
		{
			insertarDelante(lista,aux1);
			aux1=pop(lista);
		}
	}
	while(lista!=NULL)
	{
		insertarDelante(lista,aux1);
		aux1=pop(lista);
	}
	while(pila!=NULL)
	{
		insertarDelante(lista,aux2);
		aux2=pop(pila);
	}
	return listaNueva;
}

struct nodo
{
	int info;
	nodo*sgte;
};

nodo*interseccionListas(nodo*&lista1,nodo*&lista2)
{
	nodo*listaFinal=NULL;
	int aux1=pop(lista1);
	int aux2=pop(lista2);
	while(lista1!=NULL && lista2!=NULL)
	{
		if(aux1==aux2)
		{
			insertarOrdenado(listaFinal,aux1);
			aux1=pop(lista1);
	        aux2=pop(lista2);
		}
		else if(aux1>aux2)
		{
			aux2=pop(lista2);
		}
		else
		{
			aux1=pop(lista1);
		}
	}
	return listaFinal;
}

//Punto 3:
struct regVector
{
	int codFabricante;
	int codProducto;
	int cantDisponible;
};

void puntoAyB(regVector vec[])
{
	int i,mayor=vec[0].cantDisponible,posMayor=0;
	for(i=1;i<200;i++)
	{
		if(vec[i].cantDisponible>mayor)
		{
			mayor=vec[i].cantDisponible;
			posMayor=i;
		}
	}
	cout<<"Fabricante con mas unidades: "<<vec[mayor].codFabricante<<endl;
	cout<<"Mueble con mas unidades: "<<vec[mayor].codProdcuto<<endl;
}

//Punto 4:
struct regVector
{
	int codHotel;
	int cantReservas;
	int cantHuespedes;
};

struct infoLista
{
	int codHotel;
	char preViaje;
	int cantHuespedes;
};

struct nodo
{
	infoLista info;
	nodo*sgte;
};

void actualizarVector(nodo*&lista,regVector v[])
{
	int i;
	infoLista aux;
	while(lista!=NULL)
	{
		aux=pop(lista);
		if(aux.preViaje=="S")
		{
			i=busquedaBinaria(v,100,aux.codHotel);
			v[i].cantReservas++;
			v[i].cantHuespedes+=aux.cantHuespedes;
		}
	}
}

//Punto 5:
struct regArchivo
{
	double codProducto;
	int peso;
	double cantStock;
};

struct nodo
{
	regArchivo info;
	nodo*sgte;
};

void ordenarArchivoYmostrarListado(FILE*archivo)
{
	regArchivo aux;
	nodo*listaOrden=NULL;
	nodo*listaStock=NULL;
	nodo*listaPesados=NULL;
	archivo=fopen("PROD.DAT","rb+");
	while(fread(&aux,sizeof(regArchivo),1,archivo))
	{
		insertarOrdenado(listaOrden,aux); //por codigo de producto
		if(aux.cantStock==0)
		{
			insertarOrdenado(listaStock,aux);
		}
		if(aux.peso>100)
		{
			insertarOrdenado(listaPesados,aux);
		}
	}
	fseek(archivo,0,SEEK_SET);
	while(listaOrden!=NULL)
	{
		aux=pop(listaOrden);
		fwrite(&aux,sizeof(regArchivo),1,archivo);
	}
	fclose(archivo);
	cout<<"Productos sin stock: "<<endl;
	while(listaStock!=NULL)
	{
		aux=pop(listaStock);
		cout<<aux.codProdcuto<<endl;
	}
	cout<<"Productos pesados: "<<endl;
	while(listaPesados!=NULL)
	{
		aux=pop(listaPesados);
		cout<<aux.codProdcuto<<endl;
	}

}
