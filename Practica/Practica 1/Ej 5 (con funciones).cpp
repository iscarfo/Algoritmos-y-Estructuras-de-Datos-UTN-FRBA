//5.	Dado un triángulo representado por sus lados L1, L2, L3, determinar e imprimir una leyenda según sea: equilátero, isósceles o escalenos.
#include<iostream>
using namespace std;

void triangulo (float,float,float);

int main()
{
	float l1,l2,l3;
	cout<<"Indique la medida del primer lado: ";
	cin>>l1;
	cout<<"Indique la medida del segundo lado: ";
	cin>>l2;
	cout<<"Indique la medida del tercer lado: ";
	cin>>l3;
	
	triangulo(l1,l2,l3);
	
	return 0;
}

void triangulo (float x, float y, float z)
{
	if ((x==y)&&(y==z))
	{
		cout<<"Equilatero";
	}
	else if ((x==y)&&(x!=z)||(y==z)&&(x!=y)||(x==z)&&(z!=y))
	{
		cout<<"Isóceles";
	}
	else
	{
		cout<<"Escaleno";
	}
}
