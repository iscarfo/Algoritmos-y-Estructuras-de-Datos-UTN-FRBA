#include <iostream>
#include<cstring>
using namespace std;

/*dado un vector de estructura maestro (stock):
-idproducto int
nombre char (50)
cantidadvendida int
se tiene otro vector con las novedades de ventas del dia (desordenado)
obtener una tercera estructura del mismo tipo ordenada por producto que incluya
el maestro actualizado con las ventas del día (id articulo campo clave)
ejemplo:
maestro:
-7 lapiz azul 30 unidades
-8 lapiz verde 20 unidades
-20 goma de borrar 100 unidades
ventas:
   -7  lapiz azul 5 unidades
   -10  cuaderno   100 unidades
   - 8 lapiz verde 23 unidades
   - 5 lapiz negro 40 unidades
  
nuevo maestro:	
    - 5 lapiz negro 40 unidades
	- 7  lapiz azul  35 unidades
	- 8  lapiz verde 43 unidades
	 -10  cuaderno   100 unidades
	- 20 goma de borrar 100 unidades	
*/

struct maestro
{
	int id_producto;
	char nombre [50];
	int cant_vendida;
};

void burbuja (maestro[],int n);
void apareo (maestro v1[],maestro v2[], int n, int m, maestro v3[],int& k);

int main(){
	int n=3, m=4;
	int k=0;
	maestro desact[]={{7,"lapiz azul",30},{8,"lapiz verde",20},{20,"goma de borrar",100}};
	maestro ventas[]={{7,"lapiz azul",5},{10,"cuaderno",100},{8,"lapiz verde",23},{5,"lapiz negro",40}};
	maestro act[n+m];
	
	burbuja(ventas,m);	
	apareo(desact,ventas,n,m,act,k);

	
	for (int g=0;g<k;g++)
	{
		cout<<"ID del producto: "<<act[g].id_producto<<endl;
		cout<<"Nombre del producto: "<<act[g].nombre<<endl;
		cout<<"Cantidad vendida: "<<act[g].cant_vendida<<endl;
	}
	
	return 0;
}

void burbuja (maestro v[],int n)
{
	int i,j;
	maestro aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if((v[j-1].id_producto>v[j].id_producto))
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]= aux;
			}
		}
	}
}

void apareo(maestro v1[],maestro v2[], int n, int m,maestro v3[],int& k) //k pasa por referencia
{
	int i=0, j=0;
	
	while((i<n)&&(j<m))
	{
		if(v1[i].id_producto<v2[j].id_producto)
		{
			v3[k]=v1[i];
			i++;

		}
		else
		if(v1[i].id_producto==v2[j].id_producto)
		{
			v2[j].cant_vendida=v2[j].cant_vendida+v1[i].cant_vendida;
            v3[k]=v2[j];
            j++;
            i++;
		}
		else
		{
			v3[k]=v2[j];
			j++;

		}
		k++;
	}
	while(i<n)
	{
		v3[k]=v1[i];
		i++;
		k++;
	}
	while(j<m)
	{
		v3[k]=v2[j];
		j++;
		k++;
	}
}
