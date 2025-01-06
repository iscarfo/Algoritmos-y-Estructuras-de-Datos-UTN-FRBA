//3.	Realizar la suma de todos los números pares entre 2 y 10000
#include<iostream>
using namespace std;

void SumaNumPar ();

int main()
{
	SumaNumPar();
	
	
	return 0;
}

void SumaNumPar()
{
	int suma=0;
	for(int i=2;i<=10000;i+=2)
	{
		suma += i;
	}
	cout<<"La suma de todos los numeros pares entre 2 y 10000 es: "<<suma;
}
