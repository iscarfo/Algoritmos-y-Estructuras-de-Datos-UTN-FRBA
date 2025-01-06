/*Se conoce de cada alumno de un curso los siguientes datos: legajo (8digitos) y las notas de
2 parciales (0..10), que finaliza con un legajo negativo.
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe
un archivo binario CURSO.BIN con una línea por cada alumno, con el número de legajo y su
promedio (real).*/
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

struct alumno
{
	int legajo;
	int nota1;
	int nota2;
};

void llenarArchivo(FILE*);
void leerArchivo(FILE*);

int main()
{
	FILE*archivo;
	llenarArchivo(archivo);
	leerArchivo(archivo);
	
	return 0;
}

void llenarArchivo(FILE*arch)
{
	arch=fopen("CURSO.BIN","wb");
	alumno aux;
	cout<<"Indique el legajo: ";
	cin>>aux.legajo;
	while(aux.legajo>0)
	{
		cout<<"Indique la nota 1: ";
	    cin>>aux.nota1;	
		cout<<"Indique la nota 2: ";
	    cin>>aux.nota2;
	    fwrite(&aux,sizeof(alumno),1,arch);
	    cout<<"Indique el legajo: ";
	    cin>>aux.legajo;
	    
	}
	fclose(arch);
}

void leerArchivo(FILE*arch)
{
	arch=fopen("CURSO.BIN","rb");
	alumno aux;
	float promedio;

	while(fread(&aux,sizeof(alumno),1,arch))
	{
		cout<<"Legajo: "<<aux.legajo<<endl;
		promedio=(aux.nota1+aux.nota2)/2;
		cout<<"Promedio: "<<promedio<<endl;
		
	}
	fclose(arch);
	
}
