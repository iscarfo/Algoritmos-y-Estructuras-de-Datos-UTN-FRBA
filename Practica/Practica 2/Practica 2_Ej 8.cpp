/*8.	Dado un numero N (<50), y un vector VEC de N valores enteros positivos ordene el contenido del vector y lo informe, aplicando el procedimiento Burbujeo:
" en orden ascendente
" en orden descendente*/
#include<iostream>
using namespace std;

void rellenarVector(int[],int);
void burbujaA(int[],int);
void burbujaD(int[],int);

int main()
{
	int N;
	cout<<"Indique el valor de N (<50): ";
	cin>>N;
	
	int VEC[N];
	rellenarVector(VEC,N);
	burbujaA(VEC,N);
	burbujaD(VEC,N);
	
	
	return 0;
}

void rellenarVector(int v[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Indique el siguiente valor: ";
		cin>>v[i];
	}
}

void burbujaA(int v[],int n)
{
	int i,j,aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(v[j-1]>v[j])
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]=aux;
			}
		}
	}
	cout<<"En orden ascendente: "<<endl;
	for(int k=0;k<n;k++)
	{
		cout<<v[k]<<endl;
	}
}

void burbujaD(int v[],int n)
{
	int i,j,aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(v[j-1]>v[j])
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]=aux;
			}
		}
	}
	cout<<"En orden descendente: "<<endl;
	for(int k=n-1;k>=0;k--)
	{
		cout<<v[k]<<endl;
	}
}
