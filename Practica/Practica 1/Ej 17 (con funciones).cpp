/*17.	Desarrolle la función
float CalcularPorcentajeDiferencia(int A ,int B) que recibe dos valores y retorne el siguiente calculo:
(B-A) *100 / (A+B)
*/
#include<iostream>
using namespace std;

float CalcularPorcentajeDiferencia(int,int);

int main()
{
	int x,y;
	cout<<"Indique el valor x: ";
	cin>>x;
	cout<<"Indique el valor y: ";
	cin>>y;
	
	cout<<"El porcentaje diferencia es: "<<CalcularPorcentajeDiferencia(x,y);
	
	return 0;
}

float CalcularPorcentajeDiferencia(int A,int B)
{
	return (B-A)*100/(A+B);
}
