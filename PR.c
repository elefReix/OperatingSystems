
/*
ALGORITMO DE PLANIFICACIÓN DE PROCESOS POR PRIORIDAD
Fecha: 30/03/2017
Autora: Onofre Balbuena Jazmín
Matricula: 2133019808

Prueba con 10 procesos:
Duración y prioridad de cada proceso
P[1]:10,2
P[2]:3,1
P[3]:8,5
P[4]:12,3
P[5]:11,4
P[6]:1,7
P[7]:10,6
P[8]:3,2
P[9]:5,4
P[10]:8,1
Tiempos de ejecución por corrida
114 ms
115 ms
115 ms
117 ms
114 ms
115 ms
116 ms
116 ms
119 ms
111 ms

*/
#include<stdio.h>
#include <time.h> 

int main()
{

//Declaración de arreglos y variables a utilizar 
int t_rafaja[20], proceso[20],t_espera[20],t_respuesta[20], prioridad[20],i,j,n, pos, temp, t_ini,t_fin;
double promedio_espera, promedio_respuesta, total=0.0;

printf("Ingrese el número total de procesos: ");
//inicia el reloj para medir el tiempo de ejecución
t_ini=clock();
scanf("%d",&n);
printf("\nIngrese el tiempo de ejecución y prioridad de cada proceso \n");

//For que llena el arreglo de procesos,tiempo de ejecución y prioridad , ingresados
for (i=0;i<n;i++)
{
        printf("\nP[%d]\n",i+1);
        printf("Tiempo de ejecución:");
        scanf("%d",&t_rafaja[i]);
        printf("Prioridad:");
        scanf("%d",&prioridad[i]);
        proceso[i]=i+1; 
}
t_ini=clock();
//Ordenar los procesos por prioridad mas alta
for (i=0;i<n;i++)
{
	pos=i;
	for(j=i+1;j<n;j++)
	{
		if (prioridad[j]>prioridad[pos])
			pos=j;
	}
	
	temp=prioridad[i];
	prioridad[i]=prioridad[pos];
	prioridad[pos]=temp;
	
	temp=t_rafaja[i];
	t_rafaja[i]=t_rafaja[pos];	
	t_rafaja[pos]=temp;

	temp=proceso[i];
	proceso[i]=proceso[pos];
	proceso[pos]=temp;
}

t_espera[0]=0;
//Calculo de tiempo de espera

for(i=1;i<n;i++)
{
	t_espera[i]=0;
	for(j=0;j<i;j++)
		t_espera[i]+=t_rafaja[j];
	total+=t_espera[i];
}
//Promedio a partir de calcular el total de tiempo de espera
promedio_espera=total/n;
total=0;
printf("\n\t***ALGORITMO DE PLANIFICACIÓN POR PRIORIDAD***\n");
printf("\nProceso\t  Tiempo de ejecucion  Tiempo de espera  Tiempo de respuesta ");

// Calculo del tiempo de respuesta
for(i=0;i<n;i++)
{
        t_respuesta[i]=t_rafaja[i]+t_espera[i];     
        total+=t_respuesta[i];
	//Imprime "la tabla" de resultados 
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",proceso[i],t_rafaja[i],t_espera[i],t_respuesta[i]);
}

// Promedio a partir de calcular el total de tiempo de respuesta
promedio_respuesta=total/n;

// Se termina el reloj
t_fin=clock();

//Imprime el promedio de espera, respuesta y el tiempo total de ejecución
printf("\n\nPromedio de tiempo de espera=%f",promedio_espera);
printf("\nPromedio de tiempo de respuesta=%f\n",promedio_respuesta);
printf("\nTiempo de ejecución en milisegundos = %d\n",t_fin-t_ini);

return 0;
}

