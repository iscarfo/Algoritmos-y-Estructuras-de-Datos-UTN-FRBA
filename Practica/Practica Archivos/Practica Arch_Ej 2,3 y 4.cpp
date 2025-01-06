/*2- Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el
mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código
de materia, día, mes y año del examen. Los datos finalizan con un nombre y apellido =”x”.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por
teclado, genere un archivo binario de inscripción de alumnos a exámenes finales
DIAFINALES.DAT, según el siguiente diseño:
a. Nro. de legajo (8 dígitos)
b. Código de materia (6 dígitos)
c. Día del examen (1..31)
d. Mes del examen (1..12)
e. Año del examen (4 dígitos)
f. Nombre-Apellido (25caract)
3- Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que solicitando por teclado un código de materia permita seleccionar todos los registros
que se anotaron para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo
diseño.
4- Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que genere un archivo ordenado por número de legajo (cada registro debe tener los
campos legajo y apellido y nombre) para todos los alumnos que se inscribieron una o más
veces. Cada legajo debe ocupar una posición única y predecible en el archivo. El intervalo
de los legajos es 80001 a 110000, pueden no presentarse todos los legajos.*/
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

struct alumno
{
	char nombreApellido[50+1];
	int legajo;
	int codMat;
	int dia;
	int mes;
	int anio;
};

struct inscripcion
{
	int legajo;
	char nombreApellido[30+1];
};

void generarArchivo(FILE*);
void punto3(FILE*,FILE*);
void punto4(FILE*,FILE*);

int main()
{
	FILE*archivo;
	generarArchivo(archivo);
	
	FILE*archivo2;
	punto3(archivo,archivo2);
	
	FILE*ordenados;	
	punto4(archivo,ordenados);
	return 0;
}

void generarArchivo(FILE*arch)
{
	arch=fopen("DIAFINALES.DAT","wb");
	alumno aux;
	cout<<"Indique su nombre y apellido: ";
	cin>>aux.nombreApellido;
	while(strcmp(aux.nombreApellido,"x")!=0)
	{
		cout<<"Indique numero de legajo: ";
		cin>>aux.legajo;
		cout<<"Indique codigo de materia: ";
		cin>>aux.codMat;
		cout<<"Indique dia del examen: ";
		cin>>aux.dia;
		cout<<"Indique mes del examen: ";
		cin>>aux.mes;
		cout<<"Indique anio del examen: ";
		cin>>aux.anio;
		fwrite(&aux,sizeof(alumno),1,arch);
		cout<<"Indique su nombre y apellido: ";
	    cin>>aux.nombreApellido;
	}
	fclose(arch);
}

void punto3(FILE*arch,FILE*arch2)
{
	int elegido;
	cout<<"Indique el codigo de una materia: ";
	cin>>elegido;
	arch=fopen("DIAFINALES.DAT","rb");
	fseek(arch,0,SEEK_SET);
	arch2=fopen("MATFINALES.DAT","wb");
	alumno aux;
	while(fread(&aux,sizeof(alumno),1,arch))
	{
		if(aux.codMat==elegido)
		{
			fwrite(&aux,sizeof(alumno),1,arch2);
		}
	}
	fclose(arch);
	fclose(arch2);
}

void punto4(FILE*arch,FILE*arch2)
{
	arch=fopen("DIAFINALES.DAT","rb");
	alumno aux;
	fseek(arch,0,SEEK_SET);
	arch2=fopen("ORDENADOS.DAT","wb");
	inscripcion aux2;
	while(fread(&aux,sizeof(alumno),1,arch))
	{
		fseek(arch2,sizeof(aux2)*(aux.legajo-80001),SEEK_SET); //P.U.P. en archivos
		aux2.legajo=aux.legajo;
		strcpy(aux2.nombreApellido,aux.nombreApellido);
		fwrite(&aux2,sizeof(inscripcion),1,arch2);
	}
	fclose(arch);
	fclose(arch2);
}
