/*9.	Dado un numero N (<=50) y un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD),
informar el conjunto:
" ordenado por nombre
" ordenado por fecha y nombre
" ordenado por nombre y fecha
NOTA: Modifique y utilice el procedimiento Burbujeo*/
#include<iostream>
#include<cstring>
using namespace std;

struct persona
{
	char nombre[50+1];
	int fecha;
};

void rellenarVector(persona[],int);
void burbujaNomb(persona[],int);
void burbujaFecNomb(persona[],int);
void burbujaNombFec(persona[],int);

int main()
{
	int N;
	cout<<"Indique el valor de N (<50): ";
	cin>>N;
	
	persona VEC[N];
	rellenarVector(VEC,N);
	burbujaNomb(VEC,N);
	burbujaFecNomb(VEC,N);
	burbujaNombFec(VEC,N);
	
	return 0;
}

void rellenarVector(persona v[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ingrese el nombre: ";
		cin>>v[i].nombre;
		cout<<"Ingrese su fecha de nacimiento (AAAAMMDD): ";
		cin>>v[i].fecha;
	}
}

void burbujaNomb(persona v[],int n)
{
	int i,j;
	persona aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(strcmp(v[j-1].nombre,v[j].nombre)==1)
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
		cout<<v[k].nombre<<endl;
	}
}

void burbujaFecNomb(persona v[],int n)
{
	int i,j;
	persona aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(v[j-1].fecha>v[j].fecha||v[j-1].fecha==v[j].fecha&&strcmp(v[j-1].nombre,v[j].nombre)==1)
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
		cout<<v[k].nombre<<", "<<v[k].fecha<<endl;
	}
}

void burbujaNombFec(persona v[],int n)
{
	int i,j;
	persona aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(strcmp(v[j-1].nombre,v[j].nombre)==1||(strcmp(v[j-1].nombre,v[j].nombre)==0&&v[j-1].fecha>v[j].fecha))
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
		cout<<v[k].nombre<<", "<<v[k].fecha<<endl;
	}
}
