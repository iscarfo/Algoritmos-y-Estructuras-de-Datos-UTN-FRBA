/*Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del pais y
requiere un programa para el otorgamiento de pasajes. Para ello dispone de un archivo de
registros, en el que cada registro contiene información de los vuelos que realiza y la
cantidad de pasajes disponibles en cada uno de ellos según se indica:
a. Código del vuelo (6 dígitos)
b. Cantidad de pasajes disponibles (3 dígitos)
Se dispone además de otro archivo con los datos de los potenciales compradores, en el
que cada registro tiene:
a) Codigo de vuelo solicitado b) Cantidad de pasajes solicitados (3 digitos)
c) DNI del solicitante (8 digitos) d) Apellido y nombres del solicitante (30 caracteres)

Desarrollar estrategia, algoritmo y codificacion del programa que determine e imprima:
1) Para los solicitantes a los cuales se les venden pasajes,

DNI - APELLIDO Y NOMBRES – CANTIDAD DE PASAJES - CODIGO VUELO
99999       XXXXXX              999                  999

2) Al final del proceso el siguiente listado:
CODIGO DE VUELO - PASAJES LIBRES - PASAJES NO VENDIDOS
    999999            999                  999

Se le vende al solicitante si la cantidad de pasajes que solicita esta disponible, en
caso contrario se computa como pasajes no vendidos.*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct estructura1
{
	int codVuelo;
	int cantPasajesDisponible;
};

struct estructura2
{
	int codVueloSolicitado;
	int cantPasajesSolicitados;
	int dni;
	char nombreApellido[30+1];
};

void generarListado(FILE*,FILE*);

int main()
{
	FILE*archivo1;
	FILE*archivo2;
	generarListado(archivo1,archivo2);
	
	return 0;
}

void generarListado(FILE*a1,FILE*a2)
{
	a1=fopen("INFOVUELOS.BIN","rb+");
	a2=fopen("COMPRADORES.BIN","rb");
	estructura1 aux1;
	estructura2 aux2;
	int pasajesNoVendidos=0;
	fread(&aux1,sizeof(estructura1),1,a1);

	while(fread(&aux2,sizeof(estructura2),1,a2))
	{
		fread(&aux1,sizeof(estructura1),1,a1);
		if(aux2.cantPasajesSolicitados<=aux1.cantPasajesDisponible)
		{
			cout<<"Dni: "<<aux2.dni<<endl;
			cout<<"Apellido y nombre: "<<aux2.nombreApellido<<endl;
			cout<<"Cantidad de pasajes: "<<aux2.cantPasajesSolicitados<<endl;
			cout<<"Codigo de vuelo: "<<aux2.codVueloSolicitado<<endl;
			aux1.cantPasajesDisponible-=aux2.cantPasajesSolicitados;
			fwrite(&aux1,sizeof(estructura1),1,a1);
		}
		else
		{
			pasajesNoVendidos+=aux2.cantPasajesSolicitados;
		}
	}
	fseek(a1,0,SEEK_SET);
	while(fread(&aux1,sizeof(estructura1),1,a1))
	{
		cout<<"Codigo de vuelo: "<<aux1.codVuelo<<endl;
		cout<<"Pasajes libres: "<<aux1.cantPasajesDisponible<<endl;
		cout<<"Pasajes no vendidos: "<<pasajesNoVendidos<<endl;
	}
	fclose(a1);
	fclose(a2);
}
