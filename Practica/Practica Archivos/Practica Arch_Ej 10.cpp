/*Dado el archivo ‘ALUMNOS.dat’ con los datos personales de alumnos ordenado por legajo,
con el siguiente diseño:
a. Legajo (8 digitos)
b. Apellido y nombre ( 30 caracteres)
c. Domicilio (20 caracteres)
d. Código postal (4 digitos)
e. Teléfono (10 caracteres)
f. Año de ingreso (4 digitos)
Y otro archivo sin orden que el mencionado llamado ‘NOVEDADES.dat’, con cantidad
máxima de registros es 100. Posee las actualizaciones (altas, bajas, y modificaciones) a ser
aplicadas, donde cada registro contiene además de todos los campos de Alumnos.dat un
código de operación (‘A’= Alta, ‘B’= Baja, ‘M’= Modificación).
Se pide desarrollar todos los pasos necesarios para realizar un programa que genere un
archivo actualizado ‘ALUMACTU.dat’ con el mismo diseño.*/
#include <iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct alumno
{
	int legajo;
	char nombreApellido[30+1];
	char domicilio[20+1];
	int codPostal;
	int telefono;
	int anioIngreso;
};

struct novedades
{
	int legajo;
	char nombreApellido[30+1];
	char domicilio[20+1];
	int codPostal;
	int telefono;
	int anioIngreso;
	char codOp;
};

int cantidadReg(FILE*);
void pasarVector(FILE*,novedades[],int);
void burbuja (novedades [],int);
void pasarArchivo(FILE*,novedades[],int);
void apareo(FILE*,FILE*,FILE*);

int main()
{
	FILE*fnovedades;
	FILE*alumnos;
	FILE*alumnosact;
	int tam=cantidadReg(fnovedades);
	novedades vec[tam];
	pasarVector(fnovedades,vec,tam);
	burbuja(vec,tam);
	pasarArchivo(fnovedades,vec,tam);
	apareo(alumnos,fnovedades,alumnosact);
	
	return 0;
}

int cantidadReg(FILE*a)
{
	novedades aux;
	int posActual=ftell(a),cantReg;
	fseek(a,0,SEEK_END);
	cantReg=ftell(a)/sizeof(aux);
	fseek(a,posActual,SEEK_SET);
	return cantReg;
}

void pasarVector(FILE*a,novedades vec[],int tam)
{
	a=fopen("NOVEDADES.dat","rb");
    fread(vec,sizeof(novedades),tam,a);

	fclose(a);
}

void burbuja (novedades v[],int n)
{
	int i,j;
	novedades aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if((v[j-1].legajo<v[j].legajo))
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]= aux;
			}
		}
	}
}

void pasarArchivo(FILE*a,novedades vec[],int tam)
{
	a=fopen("NOVEDADES.dat","wb");
	for(int i=0;i<tam;i++)
	{
		fwrite(&vec[i],sizeof(novedades),1,a);
	}
	fclose(a);
}

void apareo(FILE*a1,FILE*a2,FILE*a3)
{
	a1=fopen("ALUMNOS.DAT","rb");
	a2=fopen("NOVEDADES.DAT","rb");
	a3=fopen("ALUMNOSACT.DAT","wb");
	alumno aux1;
	novedades aux2;
	alumno aux3;
	fread(&aux1,sizeof(alumno),1,a1);
	fread(&aux2,sizeof(novedades),1,a2);
	while(!feof(a1)&&!feof(a2))
	{
		if(aux1.legajo<aux2.legajo)
		{
			fwrite(&aux1,sizeof(alumno),1,a3);
		}
		else if(aux1.legajo>aux2.legajo||(aux1.legajo>aux2.legajo&&aux2.codOp=='A'))
		{
			aux3.legajo=aux2.legajo;
			strcpy(aux3.nombreApellido,aux2.nombreApellido);
			strcpy(aux3.domicilio,aux2.domicilio);
			aux3.codPostal=aux2.codPostal;
			aux3.telefono=aux2.telefono;
			aux3.anioIngreso=aux2.anioIngreso;
			fwrite(&aux3,sizeof(alumno),1,a3);
		}
	    else
		{
			if(aux2.codOp=='M')
			{
			aux3.legajo=aux2.legajo;
			strcpy(aux3.nombreApellido,aux2.nombreApellido);
			strcpy(aux3.domicilio,aux2.domicilio);
			aux3.codPostal=aux2.codPostal;
			aux3.telefono=aux2.telefono;
			aux3.anioIngreso=aux2.anioIngreso;
			fwrite(&aux3,sizeof(alumno),1,a3);
			}
	    }
	fread(&aux1,sizeof(alumno),1,a1);
	fread(&aux2,sizeof(novedades),1,a2);
	}
	
	while(!feof(a1))
	{
		fwrite(&aux1,sizeof(alumno),1,a3);
		fread(&aux1,sizeof(alumno),1,a1);
	}
	while(!feof(a2))
	{
		if(aux2.codOp=='A'||aux2.codOp=='M')
		{
			aux3.legajo=aux2.legajo;
			strcpy(aux3.nombreApellido,aux2.nombreApellido);
			strcpy(aux3.domicilio,aux2.domicilio);
			aux3.codPostal=aux2.codPostal;
			aux3.telefono=aux2.telefono;
			aux3.anioIngreso=aux2.anioIngreso;
			fwrite(&aux3,sizeof(alumno),1,a3);
		}
		fread(&aux2,sizeof(novedades),1,a2);
	}
	fclose(a1);
	fclose(a2);
	fclose(a3);
}
