/*7.	Dado un conjunto de N cursos ( <=20) de la cátedra de algoritmos, de cada uno
de ellos código de curso ( 4 caracteres) y cantidad de alumnos, y de cada curso el número de legajo y nota (0..10) de los alumnos.
Se pide:
A- informar de cada curso la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10
B- informar al final del proceso el código de curso, el % de aprobados y el de insuficientes de cada curso.*/
#include<iostream>
using namespace std;

struct notas
{
	int posibilidades[11];
};

struct alumno
{
	int legajo;
	int nota;
};

struct curso
{
	char codCurso[4+1];
	int cantAlumnos;
	alumno alumnos[100];
	int cantApr;
	int cantDes;
};

void juntarDatos(curso[],int);
void puntoA(curso[],int);
void puntoB(curso[],int);

int main()
{
	int n;
	cout<<"Indique la cantidad de cursos (<=20): ";
	cin>>n;
	
	curso catAlgoritmos[n];
	juntarDatos(catAlgoritmos,n);
	puntoA(catAlgoritmos,n);
	puntoB(catAlgoritmos,n);
	
	return 0;
}

void juntarDatos(curso algoritmos[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Indique el codigo de curso: ";
		cin>>algoritmos[i].codCurso;
		cout<<"Indique la cantidad de alumnos: ";
		cin>>algoritmos[i].cantAlumnos;
		for(int j=0;j<algoritmos[i].cantAlumnos;j++)
		{
			cout<<"Indique el numero de legajo del alumno: ";
			cin>>algoritmos[i].alumnos[j].legajo;
			cout<<"Indique la nota del alumno: ";
			cin>>algoritmos[i].alumnos[j].nota;
		}
	}
}

void puntoA(curso algoritmos[],int n)
{
	notas vector[n];
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<11;l++)
		{
			vector[k].posibilidades[l]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<algoritmos[i].cantAlumnos;j++)
		{
			vector[i].posibilidades[algoritmos[i].alumnos[j].nota]++;
		}
	}
	for(int h=0;h<n;h++)
	{
		cout<<"Curso: "<<algoritmos[h].codCurso<<endl;
		for(int x=0;x<11;x++)
		{
			cout<<"Cantidad de "<<x<<" : "<<vector[h].posibilidades[x]<<endl;
		}

	}

}

void puntoB(curso algoritmos[],int n)
{
	for(int k=0;k<n;k++)
	{
	   algoritmos[k].cantApr=0;
	   algoritmos[k].cantDes=0;

	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<algoritmos[i].cantAlumnos;j++)
		{
			if(algoritmos[i].alumnos[j].nota>=6)
			{
				algoritmos[i].cantApr++;
			}
			else
			{
				algoritmos[i].cantDes++;
			}
		}
		cout<<"Curso: "<<algoritmos[i].codCurso<<endl;
		cout<<"Porcentaje de aprobados: "<<(algoritmos[i].cantApr*100)/algoritmos[i].cantAlumnos<<" %"<<endl;
		cout<<"Porcentaje de desaprobados: "<<(algoritmos[i].cantDes*100)/algoritmos[i].cantAlumnos<<" %"<<endl;
	}
}
