//1.	Dado un número N (<30), genere e informe un vector VEC de N elementos que contenga los primeros N números naturales pares.
#include<iostream>
using namespace std;

void generarVector(int);

int main()
{
	int n, vector[n], j;
	cout<<"Indique el tamanio del vector (<30): ";
	cin>>n;
	generarVector(n);

	
	return 0;
}

void generarVector (int n)
{
	int i,suma=2,v[n],j;
	for(i=0;i<n;i++)
	{
		v[i]=suma;
		suma+=2;
	}
	
	cout<<"Los primeros "<<n<<" numeros naturales pares son: ";
	for(j=0;j<n;j++)
	{
		cout<<v[j]<<endl;
	}
}
