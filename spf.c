/* Algortimo de planificacion de procesos
 * Algoritmo SJF (Shortest-Job-First) 
 * PRIMERO EL PROCESO MÁS CORTO
 * 
 * FECHA : 30 / 03 / 2017
 * Autor : Víctor Hernández Juárez
 * matricula : 2123008320
 * 
 * 
 * 10 Procesos 
 * Duracion de los procesos 
 * P[1]: 8
 * P[2]: 6
 * P[3]: 4
 * P[4]: 2
 * P[5]: 9
 * P[6]: 1
 * P[7]: 5
 * P[8]: 3
 * P[9]: 7 
 * P[10]: 10
 * 
 * Este algoritmo no contempla asignar prioridad a los procesos
 * debido a que no es util
 * 
 *  EL promedio de tiempo de espera es : 16.500000 
	El promedio de respuesta es : 22.00000
	los tiempos de ejecucion son:
	 
	1566 milisegundos
	1454 milisegundos
	1313 milisegundos
	1516 milisegundos
	1423 milisegundos
	1156 milisegundos
	1558 milisegundos
	1453 milisegundos
	1354 milisegundos
	1513 milisegundos
	 
 *  
*/ 

#include<stdio.h>
//libreria necesaria para medir el tiempo de ejecución 
#include<time.h>
int main()
{
	//declaracion de variables enteras y un areglo [] que almacenara el tamaño de los procesos
	int num,proceso[100],tespera,trespuesta,temp=0,ini,fin,time,i,j;
	tespera=0;
	float promespera=0,promrespuesta=0,espera=0,respuesta=0;
	//variable que indica que inicia la medicion del tiempo de ejecucion
	ini = clock();
	//se inicia pidiendo el numero de procesos que se van a tratar , (maximo 100 procesos)	
	printf("Ingrese el número de procesos : ");
	//obtenemos el dato del teclado
	scanf ("%d",&num);
	
	//ciclo para ingresar la duracion del numero de procesos establecidos 
	for (i=0; i<num; i++)
	{
		printf("Ingrese la duracion del proceso %d: ",i+1);
		scanf ("%d",&proceso[i]);
	}
	//parte lógica del programa 
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{   
			//comparacion de tamaños
			if (proceso[i]<proceso[j])
			{	
				
				temp = proceso[i];
				proceso[i] = proceso[j];
				proceso[j] = temp;				
			}		
		}
	}	
	//parte visual del programa que nos arroja , el numero de proceso , su tamaño, su tiempo de espera y de respuesta
	printf("_________________________________________________________________\n");
	printf("______________PRIMERO EL PROCESO MÁS CORTO (SJF)__________________\n");
	printf("_________________________________________________________________\n");
	printf ("PROCESO \t TAMAÑO \t Tiempo-Espera \t Tiempo-Respuesta");
	//creacion de la tabla de resultados
	for (i=0; i<num; i++)
	{
		trespuesta=tespera+proceso[i];
		printf("\n%d \t\t %d \t\t %d \t\t %d \n",i+1,proceso[i],tespera,trespuesta);
		printf("_________________________________________________________________\n");
		respuesta= respuesta+trespuesta;
		espera= espera+tespera;
		tespera= tespera+proceso[i];
	}
	//promedio de tiempo de respuesta y espera
	promrespuesta=respuesta/num;
	promespera=espera/num;
	//impresion de los resultados en pantalla
	printf("\nEL promedio de tiempo de espera es : %f \nEl promedio de respuesta es : %f",promespera,promrespuesta);
	printf("\n");
	//fin del tiempo de ejecucion
	fin=clock();
	time=fin-ini;
	printf("El tiempo de ejecucion es de: %d milisegundos",time);
	printf("\n");
	return 0;	
}
