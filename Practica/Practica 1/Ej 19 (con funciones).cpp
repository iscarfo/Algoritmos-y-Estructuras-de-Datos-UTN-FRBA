/*19.	Desarrolle un procedimiento que reciba el costo en pesos de un abono telefónico, la cantidad de minutos libres que incluye el abono, 
el cargo en pesos por minuto excedente y la cantidad de minutos utilizados por un abonado, 
retorne la cantidad de minutos excedidos y el monto en pesos a abonar (costo del abono mas minutos excedidos por el costo de minutos excedidos) mas el 21% del valor del IVA.*/
#include<iostream>
using namespace std;

int cantMinExcedidos (int,int);
int sacarDeudaIva(int,int);

int main()
{
	int costoAbono, cantMinLibre, cargoMin, cantMin;
	cout<<"Indique el costo del abono: ";
	cin>>costoAbono;
	cout<<"Indique la cantidad de minutos libres que incluye el abono: ";
	cin>>cantMinLibre;
	cout<<"Indique el cargo de pesos por minuto excedente: ";
	cin>>cargoMin;
	cout<<"Indique la cantidad de minutos usados: ";
	cin>>cantMin;
	
	int minsExcedidos=cantMinExcedidos(cantMinLibre,cantMin);
	if(minsExcedidos==0)
	{
		cout<<"El cliente no debe nada";
	}
	else
	{
		cout<<"La cantidad de minutos excedidos es de: "<<minsExcedidos<<endl;
		cout<<"Y la deuda a pagar sera de: "<<sacarDeudaIva(minsExcedidos,cargoMin);
	}
	
	return 0;
}

int cantMinExcedidos(int libre,int usados)
{
	if(usados<=libre)
	{
		return 0;
	}
	else if (usados>libre)
	{
		return usados-libre;
	}
}

int sacarDeudaIva (int excedido,int cargo)
{
	int deuda=0,IVA;
	deuda=excedido*cargo;
	IVA=deuda*0.21;
	return deuda+IVA;
}
