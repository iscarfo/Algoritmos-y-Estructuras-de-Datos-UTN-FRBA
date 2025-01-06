//4.	Dado tres valores determinar e imprimir una leyenda según sea: "Forman triangulo" o "No forman triangulo"
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
	if ((x+y>z)&&(x+z>y)&&(y+z>x))
	{
		cout<<"Forman triangulo";
	}
	else
	{
		cout<<"No forman triangulo";
	}
}
