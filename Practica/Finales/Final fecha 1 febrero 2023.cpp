//FINAL fecha1

//Estructuras que te dan:
struct Electrodomestico //--> registro del array de 2500 posiciones (ordenado por codigo)
{
    char codigoElectrodomestico[6+1];
    char nombreElectrodomestico[250+1];
    float precioUnitario;
};

struct Venta //--> registro del archivo "ventas.dat" que contiene las compras de los clientes
{
    char codigoElectrodomestico[6+1];
    int diaDelMes; // valores entre 1 y 31
    int cantidadVendida;
    int dniCliente;
    char nombreCliente[100+1];
};

//Punto 1:

struct infoNodo
{
	int dniCliente;
	char nombreCliente[100+1];
};

struct nodo
{
	infoNodo info;
	nodo*sgte;
};

struct Matriz
{
	int cantVendida;
	nodo*lista;
};

Matriz m[31][2500];

//Punto 2A:
int obtenerPosFilaEnMatriz(int& diaDelMes)
{
	return diaDelMes-1;
}


//Punto 2B:
 int obtenerPosColumnaEnMatriz(Electrodomestico electrodomesticos[], char codigoElectrodomestico[6+1])
 {
 	int i;
 	i=busquedaBinaria(electrodomesticos,2500,codigoElectrodomestico);
 	return i;
 }
 
 //Punto 3:
 void cargarMatriz(FILE*archivoVentas,Electrodomestico electrodomesticos[],Matriz m[][2500])
 {
 	Venta aux1;
 	infoNodo aux2;
 	while(fread(&aux1,sizeof(Ventas),1,archivoVentas))
	 {
	 	m[obtenerPosFilaEnMatriz(aux1.diaDelMes)][obtenerPosColumnaEnMatriz(electrodomesticos,aux1.codigoElectrodomestico)].cantVendida++;
	 	aux2.dniCliente=aux1.dniCliente;
		strcpy(aux2.nombreCliente,aux1.nombreCliente); 
		insertarOrdenado(m[obtenerPosFilaEnMatriz(aux1.diaDelMes)][obtenerPosColumnaEnMatriz(electrodomesticos,aux1.codigoElectrodomestico)].lista,aux2);
 	}
 }
 
//Punto 4:
void mostrarClientes(Matriz m[][2500],int& fila,int& columna)
{
	nodo*aux=m[fila][columna].lista;
	infoNodo aux2;
	cout<<"Cantidad de ventas realizadas: "<<m[fila][columna].cantVendida<<endl;
	cout<<"DNI de clientes: "<<endl;
	while(aux!=NULL)
	{
		aux2=pop(aux);
		cout<<aux2.dniCliente<<endl;
		aux=aux->sgte;
	}
}

/*Punto BONUS:
Hubiese utilizado un vector (ya que conoces la cantidad de dias) y dentro del vector una lista de listas, ya que una sería para los electrodomesticos vendidos en ese dia y otra 
para los clientes*/
