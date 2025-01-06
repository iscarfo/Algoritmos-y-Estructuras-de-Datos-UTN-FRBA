//2.	Ingresar un valor entero N (< 30) y a continuación un conjunto de N elementos. 
//Si el último elemento del conjunto tiene un valor menor que 10 imprimir los negativos y en caso contrario los demás
#include<iostream>
using namespace std;

void generarVector(int, int []);
void analisis(int,int[]);

int main()
{
	int n,v[n];
	cout<<"Indique el tamanio del conjunto: ";
	cin>>n;
	generarVector(n,v);
	analisis(n,v);

	return 0;
}

void generarVector (int n, int v[])
{
	for(int i=0;i<n;i++)
	{
		cout<<"Indique el siguiente elemento: ";
		cin>>v[i];
	}
	
}

void analisis (int n, int v[])
{
	if (v[n-1]<10)
	{
		for(int h=0;h<n;h++)
		{
			if (v[h]<0)
			{
				cout<<v[h]<<endl;
			}
		}
	}
	else
	{
		for(int l=0;l<n;l++)
		{
			if (v[l]>=0)
			{
				cout<<v[l]<<endl;
			}
		}
	}
}
