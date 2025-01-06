 #include <iostream>
#include<cstring>
using namespace std;

struct alumno
{
	int CodMateria;
	char nombreMateria [20];
	char nombre [50];
	int nota;
};

void cc (alumno[],int n);
void burbuja (alumno[],int n);

int main()
{
	int n=4;
	alumno vector[]={{2,"AyED","Juan",8},{1,"AM1","Josef",10},
	{2,"AyED","Lola",4},{1,"AM1","Pablo",5}};
	burbuja(vector,n);
	cc(vector,n);
}

// para el corte de control el vector debe estar ordenado y agrupado

void cc(alumno vector[], int n)
{
	int i=0;
	int contarGrupos=0;
	int total=0;
	int materia_Aux;
	float promedio;
	
	while(i<n)
	{
		contarGrupos=0;
		promedio=0;
		materia_Aux=vector[i].CodMateria;
		cout<<"Materia "<< materia_Aux << ": "<<vector[i].nombreMateria<<endl;
		
		while (i<n && materia_Aux==vector[i].CodMateria)
		{
			cout<<vector[i].nombre<<"  "<<vector[i].nota<<endl;
			promedio+=vector[i].nota;
			contarGrupos++;
			total++;
			i++;
		}
		cout<<"------------"<<endl;
		cout<< "Total: "<< contarGrupos<<endl;
		cout<< "Promedio de la Materia: "<< promedio/contarGrupos<<endl<<endl;
	}
	
	cout<<"Cantidad de registros procesados: "<<total;
}

void burbuja (alumno v[],int n)
{
	int i,j;
	alumno aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if((v[j-1].CodMateria>v[j].CodMateria))
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]= aux;
			}
		}
	}
}

