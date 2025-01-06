/*Dado un archivo binario ‘ACTASFINALES.dat’ que contiene las actas de los exámenes
finales de las distintas materias, ordenado por libro y folio y con el siguiente diseño
a. Libro (6 digitos)
b. Folio ( 1..999)
c. Fecha (aaaammdd)
d. Código materia (6 dígitos)
e. Legajo (10 digitos)
f. Apellido y nombre (20 caracteres)
g. Nota (1..10, 0 indica ausente)
Se pide desarrollar todos los pasos necesarios para realizar un algoritmo que grabe
un archivo ‘TOTALES.dat’ ordenado por libro y folio con el siguiente diseño:
Libro (6 digitos)
Folio ( 1..999)
Total alumnos inscriptos (1..20)
Total alumnos ausentes (1..20)
Total alumnos aprobados (1..20)
Total alumnos desaprobados (1..20)*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
using namespace std;

struct acta
{
	int libro;
	int folio;
	int fecha;
	int codMat;
	int legajo;
	char nombreApellido[20+1];
	int nota;
};

struct total
{
	int libro;
	int folio;
	int alumnosIns;
	int alumnosAus;
	int alumnosApr;
	int alumnosDes;
};

void cortControl(FILE*,FILE*);

int main()
{
	FILE*archivo1;
	FILE*archivo2;
	
	cortControl(archivo1,archivo2);
	
	return 0;
}

void cortControl(FILE*actas,FILE*totales)
{
	actas=fopen("ACTASFINALES.DAT","rb");
	totales=fopen("TOTALES.DAT","wb");
	acta aux1;
	total aux2;
	fread(&aux1,sizeof(acta),1,actas);
	while(!feof(actas))
	{
		int control=aux1.libro;
		int control2=aux1.folio;
		aux2.alumnosIns=0;
		aux2.alumnosAus=0;
		aux2.alumnosApr=0;
	    aux2.alumnosDes=0;
	    while(!feof(actas)&&control==aux1.libro&&control2==aux1.folio)
		{
			if(aux1.nota==0)
			{
				aux2.alumnosAus++;
			}
			else if(aux1.nota>=6)
			{
				aux2.alumnosApr++;
			}
			else
			{
				aux2.alumnosDes++;
			}
			aux2.alumnosIns++;
			fread(&aux1,sizeof(acta),1,actas);
	    }
	    fwrite(&aux2,sizeof(total),1,totales);
	    
	    
	}
	fclose(actas);
	fclose(totales);
}
