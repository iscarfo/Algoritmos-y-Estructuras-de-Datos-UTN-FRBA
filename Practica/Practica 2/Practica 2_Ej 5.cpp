/*5.	 Escriba un programa que permita ingresar la tirada de un par de dados 50 veces
y muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el siguiente:
2 salió ... veces
3 salió ... veces
. . 12 salió ... veces*/
#include<iostream>
using namespace std;

void generarContador();

int main()
{
	generarContador();
	
	return 0;
}

void generarContador()
{
	int dado1,dado2, puntajes[13];
	for(int i=0;i<50;i++)
	{
		cout<<"Tirada "<<i+1<<endl;
		cout<<"Indique cuanto saco el primer dado: ";
		cin>>dado1;
		cout<<"Indique cuanto saco el segundo dado: ";
		cin>>dado2;
		puntajes[dado1+dado2]++;
	}
	for(int j=2;j<13;j++)
	{
		cout<<j<<" salio "<<puntajes[j]<<" veces"<<endl;
	}
}
