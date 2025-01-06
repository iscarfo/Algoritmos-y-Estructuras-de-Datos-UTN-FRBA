/*4.	Dado un número N (<25), y dos vectores A y B de N elementos que contenga
valores reales
a) genere e informe un tercer vector C intercalando los valores de posición impar de A y los valores de posición par de B.
b) genere e informe un tercer vector D donde cada elemento contenga un valor cero si
los elementos de una misma posición de A y B son iguales, o un valor uno si no lo son.*/
#include<iostream>
using namespace std;

void generarVector(int[],int);
void puntoA(int[],int[],int);
void puntoB(int[],int[],int);

int main()
{
	int n;
	
	cout<<"Indique el tamanio de los vectores: ";
	cin>>n;
	
	int vectorA[n],vectorB[n];
	cout<<"Primer vector:"<<endl;
	generarVector(vectorA,n);
	cout<<"Segundo vector:"<<endl;
	generarVector(vectorB,n);
	
	puntoA(vectorA,vectorB,n);
	puntoB(vectorA,vectorB,n);
	
	return 0;
}

void generarVector(int v[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Indique el siguiente numero: ";
		cin>>v[i];
	}
}

void puntoA(int a[],int b[],int n)
{
	int vectorC[n];
	cout<<"Vector C:"<<endl;
	for(int h=0;h<n;h++)
	{
		if(h%2==0)
		{
			vectorC[h]=b[h];
		}
		else
		{
			vectorC[h]=a[h];
		}
		cout<<vectorC[h]<<endl;
	}
}

void puntoB(int a[],int b[],int n)
{
	int vectorD[n];
	cout<<"Vector D:"<<endl;
	for(int j=0;j<n;j++)
	{
		if(a[j]==b[j])
		{
			vectorD[j]=0;
		}
		else
		{
			vectorD[j]=1;
		}
		cout<<vectorD[j]<<endl;
	}
}
