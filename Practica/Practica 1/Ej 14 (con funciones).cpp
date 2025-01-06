/*14.	Un buque de carga traslada 100 contenedores a tres diferentes puertos del país. Los puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
" Identificación del contenedor (entero)
" Peso del contenedor en kg (entero)
" Puerto de arribo(un valor de 1 a 3).
Se pide calcular e informar:
i. El peso total que el buque debe trasladar
ii. La identificación del contenedor de mayor peso
iii. La cantidad de contenedores que debe trasladar a cada puerto*/

#include<iostream>
using namespace std;

void informeContenedores();

int main()
{
	informeContenedores();
	return 0;
}

void informeContenedores()
{
	int id,puerto,puerto1,puerto2,puerto3,idMax;
	float peso,sumaPeso=0,maxPeso=0;
	for(int i=1;i<=100;i++)
	{
		cout<<"Indique el ID del contenedor: ";
		cin>>id;
		cout<<"Indique el peso del contenedor: ";
		cin>>peso;
		sumaPeso+=peso;
		cout<<"Indique el puerto de arribo: ";
		cin>>puerto;
		if(peso>maxPeso)
		{
			maxPeso=peso;
			idMax=id;
		}
		else if(puerto==1)
		{
			puerto1++;
		}
		else if(puerto==2)
		{
			puerto2++;
		}
		else
		{
			puerto3++;
		}
	}
	cout<<"El buque debe trasladar: "<<sumaPeso<<" kilos"<<endl;
	cout<<"El contenedor mas pesado es el: "<<idMax<<endl;
	cout<<"Se deben trasladar "<<puerto1<<" contenedores al puerto 1, "<<puerto2<<" al puerto 2 y "<<puerto3<<" al puerto 3";
}
