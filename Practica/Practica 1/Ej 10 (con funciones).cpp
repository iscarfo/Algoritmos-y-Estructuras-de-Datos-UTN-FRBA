/*10.	Se ingresa un conjunto de valores float, cada uno de los cuales representan el sueldo de un empleado, excepto el ultimo valor que es cero e indica el fin del conjunto. 
Se pide desarrollar un programa que determine e informe:
" Cuantos empleados ganan menos $ 1.520.
" Cuantos ganan $1.520 o mas pero menos de $2.780.
" Cuantos ganan $2.780 o mas pero menos de $5.999.
" Cuantos ganan $5.999 o mas.*/
#include<iostream>
using namespace std;

void generarInforme();

int main()
{
	generarInforme();
	
	return 0;
}

void generarInforme()
{
	float sueldo;
	int menos1520=0,menos2780=0,menos5999=0,mas6000=0;
	cout<<"Indique el sueldo del empleado: ";
	cin>>sueldo;
	while (sueldo!=0)
	{
		if(sueldo<1520)
		{
			menos1520++;
		}
		else if ((sueldo>=1520)&&(sueldo<2780))
		{
			menos2780++;
		}
		else if ((sueldo>=2780)&&(sueldo<5999))
		{
			menos5999++;
		}
		else
		{
			mas6000++;
		}
	}
	
	cout<<"La cantidad de empleados que ganan menos de $1520 es: "<<menos1520;
	cout<<"La cantidad de empleados que ganan mas de $1520 pero menos de $2780 es: "<<menos2780;
	cout<<"La cantidad de empleados que ganan mas de $2780 pero menos de $5999 es: "<<menos5999;
	cout<<"La cantidad de empleados que ganan mas de $5999 es: "<<mas6000;
}
