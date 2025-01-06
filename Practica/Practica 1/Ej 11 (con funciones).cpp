//11.	Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.
#include<iostream>
using namespace std;

void informe(int);

int main()
{
	int n;
	cout<<"Indique el tamanio del conjunto: ";
	cin>>n;
	
	informe(n);
	
	
	return 0;
}

void informe (int n)
{
	int num,mayor=0,menor=0,posicionMen, posicionMay;
	for(int i=1;i<=50;i++)
	{
		cout<<"Ingrese un valor: ";
		cin>>num;
		mayor=num;
		menor=num;
		if(num<menor)
		{
			menor=num;
			posicionMen=i;
		}
		else if (num>mayor)
		{
			mayor=num;
			posicionMay=i;
		}
	}
	
	cout<<"El mayor fue: "<<mayor<<" en la posicion "<<posicionMay<<endl;
	cout<<"El menor fue: "<<menor<<" en la posicion "<<posicionMen<<endl;
}
