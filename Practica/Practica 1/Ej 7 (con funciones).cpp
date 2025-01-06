//7.	Calcular la velocidad (metros/segundo) de los participantes de una carrera de 1500mts dado el tiempo en segundos en recorrerla y determinar el nombre del mas veloz. 

#include<iostream>
using namespace std;

float determinarVelocidad(int);
void determinarGanador(float,float,float,char[],char[],char[]);

int main()
{
	char participante1 [50+1],participante2[50+1],participante3[50+1];
	int tiempo1, tiempo2, tiempo3;
	float v1,v2,v3;
	
	cout<<"Indique el nombre del primer participante: ";
	cin>>participante1;
	cout<<"Indique su tiempo: ";
	cin>>tiempo1;
	cout<<"Indique el nombre del segundo participante: ";
	cin>>participante2;
	cout<<"Indique su tiempo: ";
	cin>>tiempo2;
	cout<<"Indique el nombre del tercer participante: ";
	cin>>participante3;
	cout<<"Indique su tiempo: ";
	cin>>tiempo3;
	
	v1=determinarVelocidad(tiempo1);
	v2=determinarVelocidad(tiempo2);
	v3=determinarVelocidad(tiempo3);
	
	determinarGanador(v1,v2,v3,participante1,participante2,participante3);
	
	return 0;
}


float determinarVelocidad(int tiempo)
{
	return 1500/tiempo;
}

void determinarGanador(float v1, float v2, float v3, char p1[],char p2[],char p3[])
{
	if ((v1>v2)&&(v1>v3))
	{
		cout<<"El ganador es: "<<p1;
	}
	else if((v2>v3)&&(v2>v1))
	{
		cout<<"El ganador es: "<<p2;
	}
	else if((v3>v2)&&(v3>v1))
	{
		cout<<"El ganador es: "<<p3;
	}
	
	
}
