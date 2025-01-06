//1.	Dados dos valores enteros A y B, informar la suma, la resta y el producto.
#include<iostream>
using namespace std;

int suma (int,int);
int resta (int,int);
int multiplicacion (int,int);

int main()
{
	int num1,num2;
	cout<<"Decime el primer valor: ";
	cin>>num1;
	cout<<"Decime el segundo valor: ";
	cin>>num2;
	
	cout<<"La suma de estos dos es: "<<suma(num1,num2)<<endl;
	cout<<"La resta de estos dos es: "<<resta(num1,num2)<<endl;
	cout<<"La multiplicacion de estos dos es: "<<multiplicacion(num1,num2)<<endl;
	
	
	return 0;
}

int suma (int x,int y)
{
	return x+y;
}

int resta (int x,int y)
{
	return x-y;
}

int multiplicacion (int x,int y)
{
	return x*y;
}
