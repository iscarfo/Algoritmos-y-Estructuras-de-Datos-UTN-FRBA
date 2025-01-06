//10.	Genere e informe una matriz MUL[10x10] con las tablas de multiplicar.
#include<iostream>
using namespace std;

void generarMatriz(int[][11]);

int main()
{
	int MUL[11][11];
	generarMatriz(MUL);
	
	return 0;
}

void generarMatriz(int[11][11])
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<j*i<<"   ";
		}
		cout<<endl;
	}
}
