/*Parcial curso de verano 2023*/

//Punto 1:
struct infoPila
{
	int idVendedor;
	char apYNombre[60+1];
};

struct nodoPila
{
	infoPila info;
	nodoPila*sgte;
};

struct modelos
{
	int idModelo;
	char descripcion[70+1];
};

struct regArchivo
{
	int idModelo;
	int idVendedor;
	int fecha;
	char cliente[60+1];
};

struct infoNodoLS
{
	int idVendedor;
	int fecha;
	char cliente[60+1];
	char apYNombre[60+1];
};

struct nodoLS
{
	infoNodoLS info;
	nodoLS*sgte;
};

struct infoNodoLP
{
	int idModelo;
	nodoLS*sublista;
};

struct nodoLP
{
	infoNodoLP info;
	nodoLP*sgte;
};

//Punto 2:
void cargarModelos(nodoLP*);
void imprimir(nodoLP*,FILE*,nodoPila*);

//Punto 3:
void cargarModelos(nodoLP*lista)
{
	modelos aux;
	infoNodoLP aux2;
	int contador=0;
	while(contador!=15||aux.idModelo<0)
	{
		cout<<"Indique el numero de modelo: ";
		cin>>aux.idModelo;
		cout<<"Indique la descripcion: ";
		cin>>aux.descrpicion;
		aux2.idModelo=aux.idModelo;
		aux2.sublista=NULL;
		insertarOrdenado(lista,aux2); //por modelo
	}
	
}

//Punto 5:
void imprimir(nodoLP*lista,FILE*archivo,nodoPila*pila)
{
	regArchivo aux;
	infoNodoLP aux2;
	nodoLP*aux3=NULL;
	infoPila aux4;
	archivo=fopen("Ventas.dat","rb");
	while(fread(&aux,sixeof(regArchivo),1,archivo))
	{
		aux3=buscar(lista,aux.idModelo);
		aux2.sublista->info.idVendedor=aux.idVendedor;
		aux2.sublista->info.fecha=aux.fecha;
		strcpy(aux2.sublista->info.cliente,aux.cliente);
		insertarOrdenado(aux3->info.sublista,aux2); //por idVendedor
	}
	
	while(pila!=NULL)
	{
		aux4=pop(pila);
		aux3=buscar(lista,aux.idVendedor);
		strcpy(aux3->info.sublista->info.apYNombre,aux4.apYNombre);
	}
	
	nodoLP*listado=lista;
	while(listado!=NULL)
	{
		cout<<"Modelo "<<listado->info.idModelo<<endl;
		while(listado->info.sublista!=NULL)
		{
			cout<<"ID vendedor: "<<listado->info.sublista->info.idVendedor<<endl;
			cout<<"Nombre vendedor: "<<listado->info.sublista->info.apYNombre<<endl;
			cout<<"Cliente : "<<listado->info.sublista->info.cliente<<endl;
		    cout<<"Fecha: "<<listado->info.sublista->info.fecha<<endl;
		    listado->info.sublista=listado->info.sublista->sgte;
		}
		listado=listado->sgte;
	}
}
