/*Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT,
ambos ordenados ascendente por código de materia y con el siguiente diseño:
a. Nro de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. ApellidoNombre(25caract)
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden
y diseño.*/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
using namespace std;

struct alumno
{
	int legajo;
	int codMat;
	char apellidoNombre[25+1];
};

void apareoArch(FILE*,FILE*,FILE*);

int main()
{
	FILE*maestro;
	FILE*diaFinales;
	FILE*finalesAct;
	
	apareoArch(maestro,diaFinales,finalesAct);
	
	
	return 0;
}

void apareoArch(FILE*arch1,FILE*arch2,FILE*arch3)
{
	alumno aux1,aux2,aux3;
	arch1=fopen("MAESTROFINALES","rb");
	arch2=fopen("DIAFINALES.DAT","rb");
	arch3=fopen("FINALESACT","wb");
	
	while(fread(&aux1,sizeof(alumno),1,arch1)&&fread(&aux2,sizeof(alumno),1,arch2))
	{
		if(aux1.codMat>aux2.codMat)
		{
			aux3.legajo=aux2.legajo;
			aux3.codMat=aux2.codMat;
			strcpy(aux3.apellidoNombre,aux2.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
		}
		else if(aux1.codMat<aux2.codMat)
		{
			aux3.legajo=aux1.legajo;
			aux3.codMat=aux1.codMat;
			strcpy(aux3.apellidoNombre,aux1.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
		}
		else
		{
			aux3.legajo=aux1.legajo;
			aux3.codMat=aux1.codMat;
			strcpy(aux3.apellidoNombre,aux1.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
			aux3.legajo=aux2.legajo;
			aux3.codMat=aux2.codMat;
			strcpy(aux3.apellidoNombre,aux2.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
		}
	}
	while(fread(&aux1,sizeof(alumno),1,arch1))
	{
			aux3.legajo=aux1.legajo;
			aux3.codMat=aux1.codMat;
			strcpy(aux3.apellidoNombre,aux1.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
	}
	while(fread(&aux2,sizeof(alumno),1,arch2))
	{
			aux3.legajo=aux1.legajo;
			aux3.codMat=aux1.codMat;
			strcpy(aux3.apellidoNombre,aux1.apellidoNombre);
			fwrite(&aux3,sizeof(alumno),1,arch3);
	}
}
