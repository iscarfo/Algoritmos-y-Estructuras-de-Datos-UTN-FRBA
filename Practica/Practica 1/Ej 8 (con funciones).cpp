//8.	Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los menores que -10.
#include<iostream>
using namespace std;

void promedioSuma ();

int main()
{
	promedioSuma();
	
	return 0;
}

void promedioSuma ()
{
	int num,sumaPro=0,sumaMen=0,cantPro=0;
	for(int i=0;i<=49;i++)
	{
		cout<<"Indique un numero: ";
		cin>>num;
		if(num>100)
		{
			sumaPro+=num;
			cantPro++;
		}
		else if (num<-10)
		{
			sumaMen+=num;
		}
	}
	cout<<"El promedio de los mayores que 100 es: "<<sumaPro/cantPro;
	cout<<"La suma de los menores que 100 es: "<<sumaMen;
}
