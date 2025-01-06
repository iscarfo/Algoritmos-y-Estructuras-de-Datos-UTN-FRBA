/*3.	Dado un conjunto (<100) de valores enteros de los cuales el último es cero y no
debe procesarse:
a.	informe el valor mínimo, su posición dentro del conjunto, si el mínimo no es único, informar todas las posiciones donde se encuentre.
b.	informe el producto de los elementos impares que ocupen posición par.*/
#include<iostream>
using namespace std;

void generarVector(int []);
void puntoA(int []);
void puntoB(int[]);

int main()
{
	int v[100];
	generarVector(v);
	puntoA(v);
	puntoB(v);
	
	
	return 0;
}

void generarVector (int v[100])
{
	int num,i=0;
	cout<<"Indique el siguiente elemento: ";
	cin>>num;
	while(num!=0)
	{
		v[i]=num;
		i++;
		cout<<"Indique el siguiente elemento: ";
	    cin>>num;
	}
	
}

void puntoA (int v[100])
{
	int mayor=v[0],menor=v[0], posMen=0, repeticion=0;
	
	for(int j=1;j<100;j++)
	{
		if(v[j]<menor)
		{
			menor=v[j];
			posMen=j;
		}
		else if(v[j]==menor)
		{
			repeticion++;
		}
	}
	cout<<"El valor minimo es: "<<menor<<endl;
	if(repeticion!=0)
	{
		cout<<"No es unico, se repite "<<repeticion<<" veces en las posiciones: ";
		for(int y=0;y<100;y++)
		{
			if(v[y]==menor)
			{
				cout<<y<<endl;
			}
		}
	}
	else
	{
		cout<<"Su posicion es: "<<posMen<<endl;
	}
}

void puntoB (int v[100])
{
	int producto=1;
	for(int z=0;z<100;z++)
	{
		if ((v[z]%2==1) && (z%2==0))
		{
			producto*=v[z];
		}
	}
	cout<<"El producto de los elementos impares que ocupen posición par es: "<<producto;
}
