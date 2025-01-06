/*11.	Dado un valor N (<50), y una matriz MAT[NxN] que contiene valores enteros.
Se pide:
a) Leerla por fila
b) Informarla por columna
c) Informar la sumatoria de sus elementos y el valor promedio
d) Informar el máximo elemento y su ubicación (fila y columna)
e) Informar el mínimo de cada fila y el máximo de cada columna
f) Informar cuantos elementos positivos hay en la diagonal principal y cuantos negativos en la diagonal secundaria*/
#include<iostream>
using namespace std;

void generarMatriz(int[][50],int);
void matrizXFILA(int [][50],int);
void matrizXCOLUMNA(int [][50],int); 
void sumatoriaYPromedio(int [][50],int); 
void maximo(int [][50],int);
void minFilaYmaxCol(int [][50],int);
void diagonales(int [][50],int);

int main()
{
	int N;
	cout<<"Ingrese el n: ";
	cin>>N;
	
	int MAT[N][50];
	
	generarMatriz(MAT,N);
	matrizXFILA(MAT,N);
	matrizXCOLUMNA(MAT,N);
	sumatoriaYPromedio(MAT,N);
	minFilaYmaxCol(MAT,N);
	diagonales(MAT,N);
	
}

void generarMatriz(int m[][50],int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<"Indique el siguiente valor: ";
			cin>>m[i][j];
		}
	}
}

void matrizXFILA(int m[][50],int N)
{
	cout<<"Punto A: "<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<m[i][j];
		}
	}
	cout<<endl;
}

void matrizXCOLUMNA(int m[][50],int N)
{
	cout<<"Punto B: "<<endl;
	for(int j=0;j<N;j++)
	{
		for(int i=0;i<N;i++)
		{
			cout<<m[i][j];
		}
	}
	cout<<endl;
}

void sumatoriaYPromedio(int m[][50],int N)
{
	cout<<"Punto C: "<<endl;
	int suma=0, cant=N*N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			suma+=m[i][j];
		}
	}
	float promedio=suma/cant;
	cout<<"La sumatoria es: "<<suma<<endl;
	cout<<"El promedio es: "<<promedio<<endl;
} 

void maximo(int m[][50],int N)
{
	cout<<"Punto D: "<<endl;
	int maximo=m[0][0],fila=0,columna=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(m[i][j]>maximo)
			{
				maximo=m[i][j];
				fila=i;
				columna=j;
			}
		}
	}
	cout<<"El maximo es: "<<maximo<<" y esta en la posicion ["<<fila<<"]["<<columna<<"]"<<endl;
}

void minFilaYmaxCol(int m[][50],int N)
{
	cout<<"Punto E: "<<endl;
	int min,max;
	for(int i=0;i<N;i++)
	{
		min=m[i][0];
		for(int j=0;j<N;j++)
		{
			if(m[i][j]<min)
			{
				min=m[i][j];
			}
		}
		cout<<"Minimo de la fila "<<i<<" : "<<endl;
	}
	for(int j=0;j<N;j++)
	{
		max=m[0][j];
		for(int i=0;i<N;i++)
		{
			if(m[i][j]>max)
			{
				max=m[i][j];
			}
		}
		cout<<"Maximo de la columna "<<j<<" : "<<endl;
	}
}

void diagonales(int m[][50],int N)
{
	cout<<"Punto F: "<<endl;
	int positivos=0,negativos=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j)
			{
				if(m[i][j]>=0)
				{
					positivos++;
				}
			}
			else if(i==j+1)
			{
				if(m[i][j]<0)
				{
					negativos++;
				}
			}
		}
	}
	cout<<"Cantidad de positivos en la diagonal principal: "<<positivos<<endl;
	cout<<"Cantidad de negativos en la diagonal secundaria: "<<negativos<<endl;
}
