/*9.	Se realiza una inspección en una fábrica de pinturas, y se detectaron 20 infracciones. De cada infracción se tomó nota de los siguientes datos:
- Tipo de Infracción (1, 2, 3, o 4)
- Motivo de la Infracción
- Valor de la multa (un entero)
- Gravedad de la infracción ('L','M', 'G')
Se pide informar al final del proceso:
o Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
o La leyenda "Clausurar fabrica" si la cantidad de infracciones 3 y 4 con gravedad "G" sean mayor a 3.*/
#include<iostream>
using namespace std;

int determinarMulta(int,int);
void clausura(int,char);

int main()
{
	int tipoInfraccion,valor;
	char gravedad,motivo [50+1];
	int multaTotal=0;
	
	for(int i=1;i<=20;i++)
	{
		cout<<"Indique el tipo de infraccion: ";
		cin>>tipoInfraccion;
		cout<<"Indique el motivo de infraccion: ";
		cin>>motivo;
		cout<<"Indique el valor de la multa: ";
		cin>>valor;
		cout<<"Indique la gravedad de la infraccion: ";
		cin>>gravedad;
		
		multaTotal=determinarMulta(multaTotal,valor);
		clausura(tipoInfraccion,valor);
	}
	
	cout<<"Valor de la multa a pagar: "<<multaTotal;
	
	return 0;
}

int determinarMulta(int total,int multa)
{
	return total+multa;
}

void clausura(int tipo,char gravedad)
{
	int clausura=0;
	if((tipo==3||tipo==4)&&(gravedad=='G'))
	{
		clausura++;
	}
	else if (clausura>3)
	{
		cout<<"Clausurar fabrica";
	}

}




