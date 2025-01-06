//FINAL fecha 2

//Punto 1:
struct regArchivo
{
    int dniPaciente;
    char nombreyApellido[100+1];
    int fechaNacimiento;
    char domicilio[50+1];
    char centroTesteo[50+1];
    char tipoTest[20+1];
    char obraSocial[30+1];
    int cantidadDosis;
    int fechaPosibleContacto;
    char resultadoTest[10+1];
}; 

struct infoNodoLT
{
	int dniPaciente;
	char nombreyApellido[100+1];
	int fechaNacimiento;
	char domicilio[50+1];
};

struct nodoLT
{
	infoNodoLT info;
	nodoLT*sgte;
};

struct infoNodoLS
{
	char tipoTest[20+1];
	int cantTipo;
	nodoLT*listaPacientes;
};

struct nodoLS
{
	infoNodoLS info;
	nodoLS*sgte;
};

struct infoNodoLP
{
	char obraSocial[30+1];
	int totalHisopados;
	int totalPos;
	int totalNeg;
	nodoLS*vec[2]; //0 para positivos y 1 para negativos
};

struct nodoLP
{
	infoNodoLP info;
	nodoLP*sgte;
};

//Punto 2:
nodoLP*cargarEstructura(FILE*archivo)
{
	nodoLP*lista=NULL; //supongo todas las inicializaciones de la estructuras ya hechas en 0 o en NULL
	regArchivo aux1;
	infoNodoLP aux2;
	while(fread(&aux1,sizeof(regArchivo),1,archivo))
	{
	   while((buscar(lista,lista->info.vec[0]->info.listaPacientes->info.dniPaciente)==NULL)&&(buscar(lista,lista->info.vec[1]->info.listaPacientes->info.dniPaciente)==NULL))
	  {
		strcpy(aux2.obraSocial,aux1.obraSocial);
		aux2.totalhisopados++;
		if(strcmp(aux1.resultadoTest,"POSITIVO")==0)
		{
			aux2.totalPos++;
			strcpy(aux2.vec[0]->info.tipoTest,aux1.tipoTest);
			aux2.vec[0]->info.cantTipo++;
			aux2.vec[0]->info.listaPacientes->info.dniPaciente=aux1.dniPaciente;
			strcpy(aux2.vec[0]->info.listaPacientes->info.nombreYapellido,aux1.nombreYapellido);
			strcpy(aux2.vec[0]->info.listaPacientes->info.domicilio,aux1.domicilio);
			aux2.vec[0]->info.listaPacientes->info.fechaNacimiento=aux1.fechaNacimiento;
		}
		else
		{
			aux2.totalNeg++;
			strcpy(aux2.vec[1]->info.tipoTest,aux1.tipoTest);
			aux2.vec[1]->info.cantTipo++;
			aux2.vec[1]->info.listaPacientes->info.dniPaciente=aux1.dniPaciente;
			strcpy(aux2.vec[1]->info.listaPacientes->info.nombreYapellido,aux1.nombreYapellido);
			strcpy(aux2.vec[1]->info.listaPacientes->info.domicilio,aux1.domicilio);
			aux2.vec[1]->info.listaPacientes->info.fechaNacimiento=aux1.fechaNacimiento;
		}
		insertarOrdenado(lista,aux2);
	  }
	}
	return lista;
}

//Punto 3:
void imprimirListado(nodoLP*lista)
{
	nodoLP*aux=lista;
	while(aux!=NULL)
	{
		cout<<aux->info.obraSocial<<": "<<aux->info.totalHisopados<<endl;
		cout<<"Casos positivos: "<<aux->info.totalPos<<endl;
		while(aux->info.vec[0]!=NULL)
		{
			cout<<aux->info.vec[0]->info.tipoTest<<": "<<(aux->info.vec[0]->info.cantTipo/aux->info.totalPos)*100<<endl;
			while(aux->info.vec[0]->info.listaPacientes!=NULL)
			{
				cout<<aux->info.vec[0]->info.listaPacientes->info.dniPaciente<<"...."<<endl;
				aux->info.vec[0]->info.listaPacientes=aux->info.vec[0]->info.listaPacientes->sgte;
			}
			aux->info.vec[0]=aux->info.vec[0]->sgte;
		}
		cout<<"Casos negativos: "<<aux->info.totalNeg<<endl;
		while(aux->info.vec[1]!=NULL)
		{
			cout<<aux->info.vec[1]->info.tipoTest<<": "<<(aux->info.vec[1]->info.cantTipo/aux->info.totalNeg)*100<<endl;
			while(aux->info.vec[1]->info.listaPacientes!=NULL)
			{
				cout<<aux->info.vec[1]->info.listaPacientes->info.dniPaciente<<"...."<<endl;
				aux->info.vec[1]->info.listaPacientes=aux->info.vec[1]->info.listaPacientes->sgte;
			}
			aux->info.vec[1]=aux->info.vec[1]->sgte;
		}
		aux=aux->sgte;
	}
	liberar(aux);
}
