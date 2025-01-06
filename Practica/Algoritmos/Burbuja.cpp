void burbuja (maestro v[],int n)
{
	int i,j;
	maestro aux;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if((v[j-1].id_producto>v[j].id_producto))
			{
				aux=v[j-1];
				v[j-1]=v[j];
				v[j]= aux;
			}
		}
	}
}
