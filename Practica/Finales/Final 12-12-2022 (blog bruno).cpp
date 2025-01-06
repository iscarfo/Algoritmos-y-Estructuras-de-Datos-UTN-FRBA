//FINAL 12/12/2022

/*Parte teorica:
1-Esta invocacion muestra "26" ya que se suman los valores de los nodos hasta que se encuentre un NULL en donde se sumara "0"
2-La secuencia es 11-7-5-3 ya que inserta delante del primero asi que el orden es el inverso al ingresado
3-NO CONTESTO*/

//Parte Practica:
struct tRDatos
{
    char pais[61];
    char resultado[4]; //0 – octavos; 1 – cuartos; 2 – semifinal; 3 – final. Contenido G si ganó; P si perdió
};

tRDatos tVMundial[16];

//Punto 4:
struct partido
{
	char pais1[61];
	char pais2[61];
	int instancia;
	char ganador;
};
void actualizarVec(tRDatos tVMundial[],partido& resultado)
{
	int i=busquedaBinaria(tVMundial,16,resulatdo.pais1);
	int j=busquedaBinaria(tVMundial,16,resulatdo.pais2);
	if(resulatdo.ganador=="G")
	{
		tVMundial[i].resulatdo[resultado.instancia]=resulatdo.ganador;
		tVMundial[j].resulatdo[resultado.instancia]='P';
	}
	else
	{
		tVMundial[j].resulatdo[resultado.instancia]=resulatdo.ganador;
		tVMundial[i].resulatdo[resultado.instancia]='P';
	}
}

//Punto 5:
void mostrarFinalistas(tRDatos tVMundial[]) //se puede hacer mas eficiente
{
	int i,j,k;
	cout<<"Paises que jugaron cuartos: "<<endl;
	for(i=0;i<16;i++)
	{
		if(tVMundial[i].resultado[0]=="G")
		{
			cout<<tVMundial[i].pais<<endl;
		}
	}
	cout<<"Paises que jugaron semis: "<<endl;
	for(j=0;j<16;j++)
	{
		if(tVMundial[j].resultado[1]=="G")
		{
			cout<<tVMundial[j].pais<<endl;
		}
	}
	cout<<"Paises que jugaron la final: "<<endl;
	for(k=0;k<16;k++)
	{
		if(tVMundial[k].resultado[2]=="G")
		{
			cout<<tVMundial[k].pais<<endl;
		}
	}
}
