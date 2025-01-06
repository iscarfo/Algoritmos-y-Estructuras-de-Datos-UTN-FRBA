/*13.	Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
" El valor máximo negativo
" El valor mínimo positivo
" El valor mínimo dentro del rango -17.3 y 26.9
" El promedio de todos los valores.*/
#include<iostream>
using namespace std;

void meterValores ();
float calcularPromedio(int,int);


int main()
{
	meterValores();
	
	
	return 0;
}

float calcularPromedio(int suma,int cant)
{
	return suma/cant;
}

void meterValores ()
{
	float num,suma=0,cantNum=0,minPos,maxNeg=0,minRan=-17.2;
	cout<<"Ingrese un valor: ";
	cin>>num;
	while (num!=0)
	{
		suma+=num;
		cantNum++;
		if(num<0&&maxNeg==0)
		{
			maxNeg=num;
		}
		else if (num>=0&&minPos==0)
		{
			minPos=num;
		}
		else if(num<0&&num>maxNeg)
		{
			maxNeg=num;
		}
		else if(num>0&&num<minPos)
		{
			minPos=num;
		}
		else if(num>=-17.3&&num<=26.9&&num<minRan)
		{
			minRan=num;
		}
		cout<<"Ingrese un valor: ";
		cin>>num;
		
	}
	cout<<"El promedio total es: "<<calcularPromedio(suma,cantNum)<<endl;
	cout<<"El valor máximo negativo es: "<<maxNeg<<endl;
	cout<<"El valor mínimo positivo es: "<<minPos<<endl;
	cout<<"El valor mínimo dentro del rango -17.3 y 26.9 es: "<<minRan<<endl;
}
