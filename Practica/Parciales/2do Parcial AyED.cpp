#include<iostream>
using namespace std;
/*Una empresa de marketing ofrece a su público tarjetas de descuento para pacientes que
consumen medicamentos de diferentes laboratorios.
Cada tarjeta tiene un id de laboratorio (1-10) que la identifica, un id de tarjeta(1-10000 Y
ESTAN TODAS) y un paciente asociado con los siguientes datos: nombre, apellido, dni.
Existe un archivo con la información de todas las tarjetas ordenado por dni y otro con las
compras que cada paciente hizo en el mes de marzo con su tarjeta única e intransferible, con
los siguientes datos:
Día de compra, Id de tarjeta, unidades vendidas, id de producto(99999), precio de venta,
descuento (%) también en un archivo pero desordenado (tener en cuenta que un paciente
puede comprar mas de una vez y los productos se venden mas de una vez).
1) Hacer el prototipo de una función que imprima el siguiente listado con los parámetros
que considere necesarios. Debe ordenarse por laboratorio y día.
LABORATORIO
DIA
idProducto cantidad vendida importe total de descuento (sumatoria de bonificaciones por
todas las ventas realizadas para este producto)
Ejemplo
LABORATORIO PFIZER
1
Idproducto cantidad importe dcto
100 55 990 (ese producto sale $120 se venden 55 unidades
y el descuento es de 15%=> 55*120=6600, $6600 * 0.15 = 990)

2) Declarar variables y estructuras necesarias.
3) Desarrollar la función.
Pueden utilizar las funciones de biblioteca siempre que las invoquen correctamente.
4) Si las compras estuvieran ordenadas por día afectaría el desarrollo que planteó para
resolver la función?*/

//Punto 1:
void punto1(FILE*,FILE*);

//Punto 2:
struct persona
{
	char nombre[20+1];
	char apellido[20+1];
	int dni;
};

struct tarjeta //Archivo 1
{
	int idLab;
	int idTarjeta;//  -->estan todas del 1 al 10000 (se puede hacer un vector y PUP)
	persona paciente;
};

struct infoCompras //Archivo 2
{
	int dia;
	int idTarjeta;
	int unidadesVendidas;
	int idProducto;
	int precio;
	float descuento;
};

struct listado
{
	int idLab;
	int dia;
	int idProducto;
	int cantVendida;
	float descuento;
};

struct nodoCompras
{
	infoCompras info;
	nodoCompras*sgte;
};

struct nodoTarjetas
{
	tarjeta info;
	nodoTarjetas*sgte;
};

struct nodoListado
{
	listado info;
	nodoListado*sgte;
}

// 1: se tiene un archivo ordenado por DNI con la info de las tarjetas
// 2: se tiene otro archivo desordenado con las compras de cada paciente 

//Punto 3:
void punto1(FILE*archivoInfo,FILE*archivoCompras)
{
	nodoCompras*lista1=NULL;
	nodoTarjetas*lista2=NULL;
	nodoListado*lista3=NULL;
	archivoInfo=fopen("INFOTARJETAS.DAT","rb+");
	archivoCompras=fopen("COMPRAS.DAT","rb+");
	infoCompras raux1;
	tarjeta raux2;
	while(fread(&raux2,sizeof(tarjeta),1,archivoInfo))
	{
		insertarOrdenado(lista2,raux2); //Ordenado por ID lab
	}
	while(fread(&raux1,sizeof(infoCompras),1,archivoCompras))
	{
		insertarOrdenado(lista1,raux1); //Ordenado por ID producto
	}
	fclose(archivoInfo);
	fclose(archivoCompras);
	
	nodoCompras*auxOrden=lista1;
	while(auxOrden!=NULL)
	{
		if(auxOrden->info.idTarjeta==auxOrden->sgte->info.idTarjeta)
		{
			buscar(lista1,auxOrden->info.idProducto)->info.undiadesVendidas+=buscar(lista1,auxOrden->sgte->info.idProducto)->info.undiadesVendidas;
			delete(buscar(lista1,auxOrden->sgte->info.idProducto)); //Juntas los totales de unidades vendidas de cada producto
		}
		auxOrden=auxOrden->sgte;
	}
	nodoCompras*aux1=lista1;
	nodoTarjetas*aux2=lista2;
	listado aux3;
	while(aux1!=NULL&&aux2!=NULL)
	{
		if(aux1->info.idTarjeta==aux2->info.idTarjeta)
		{
            aux3.idLab=aux2->info.idLab;
            aux3.dia=aux1->info.dia;
            aux3.idProducto=aux1->info.idProducto;
            aux3.cantVendida=aux1->info.unidadesVendidas;
            aux3.descuento=(aux1->info.precio*aux1->info.unidadesVendidas)/(aux1->info.descuento/100);
			insertarOrdenado(lista3,aux3); //ordenado por lab y dia
		}
	}
}

//Punto 4:
/*Si las compras estuvieran ordenadas por dia no habria que generar la lista para modificar el archivo

