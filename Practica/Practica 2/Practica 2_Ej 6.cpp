/*6.	En un club social se abrieron las inscripciones de los socios distintos deportes,
codificados de 1a 20, y de cada inscripción se conoce número de socio y código de deporte.
Las inscripciones finalizan con un número de socio igual a 0.
Se pide informar:
" la cantidad de inscriptos en cada deporte
" el código de deporte con la mayor cantidad de inscriptos*/
#include<iostream>
using namespace std;

void conteo(int[]);
void recorrerVector(int[]);
int main()
{
	int deportes[21];
	conteo(deportes);
	recorrerVector(deportes);
	
	return 0;
}

void conteo(int d[21])
{
	int numSoc,codDep;
	cout<<"Indique el numero de socio: ";
	cin>>numSoc;
	while(numSoc!=0)
	{
		cout<<"Indique el codigo de deporte: ";
		cin>>codDep;
		d[codDep]++;
		cout<<"Indique el numero de socio: ";
		cin>>numSoc;
    }
}

void recorrerVector(int d[21])
{
	int mayor=d[1];
	for(int i=1;i<21;i++)
	{
		cout<<"En el deporte "<<i<<" hay "<<d[i]<<" inscriptos"<<endl;
		if(d[i]>mayor)
		{
			mayor=d[i];
		}
	}
	cout<<"El/los deporte/es con mayor cantidad de inscriptos son los numero: ";
	for(int j=1;j<21;j++)
	{
		if(mayor==d[j])
		{
			cout<<d[j]<<endl;
		}
	}
}
