/*16.	Dado un conjunto de valores enteros, calcular e informar 
a) cuantos valores cero hubo, 
b) promedio de valores positivos, 
c) sumatoria de valores negativos.
Resolver el ejercicio para los siguientes lotes de datos:
b.	N valores, donde el valor de N debe ser leido previamente*/

#include <iostream>
using namespace std;

void informe (int);

int main()
{
	int n;
	
	cout<<"Indique el tamanio del conjunto: ";
	cin>>n;
	
	informe(n);
	
	
	return 0;
}

void informe (int x)
{
	int num,cantCero=0,cantNumPos=0, sumaNumPos=0, sumaNumNeg=0;
	float promedio;
	for(int i=0;i<x;i++)
	{
		cout<<"Indique un numero: ";
		cin>>num;
		if(num==0)
		{
			cantCero++;
		}
		else if (num>=0)
		{
			cantNumPos++;
			sumaNumPos+=num;
		}
		else if (num<=0)
		{
			sumaNumNeg+=num;
		}
	}
	promedio=sumaNumPos/cantNumPos;
	cout<<"La cantidad de valores cero que hubo fueron: "<<cantCero<<endl;
	cout<<"El promedio de los numeros positivos es: "<<promedio<<endl;
	cout<<"La sumatoria de valores negativos es: "<<sumaNumNeg;
}
