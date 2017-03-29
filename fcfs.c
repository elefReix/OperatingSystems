/*
/* Algortimo de planificacion de procesos no expulsivos
 * Algoritmo First Come First Server (FIRST COME - FIRST SERVER)
 * Primero en llegar primero en ser atendido
 *
 * FECHA : 30 / 03 / 2017
 * Autor : Jesús Vázquez Saldaña (elef)
 *
 * 10 Procesos
 * Duracion de los procesos
 * P[1]: 2
 * P[2]: 9
 * P[3]: 3
 * P[4]: 8
 * P[5]: 1
 * P[6]: 10
 * P[7]: 4
 * P[8]: 12
 * P[9]: 5
 * P[10]: 14
 *
 Tiempo de ejecucion para el algoritmo con las entradas anteriores

	422 milisegundos
	446 milisegundos
	184 milisegundos
	501 milisegundos
	458 milisegundos
	468 milisegundos
	403 milisegundos
	464 milisegundos
	237 milisegundos
	440 milisegundos
*/

#include<stdio.h>
#include<time.h>
#define SIZEk 50;

//Algoritmo (FIRST COME - FIRST SERVER) FCFS
int  main(){
  int i,procesos,proceso[10],wait = 0,answer = 0,once,ini,fin,time;
    printf("\n..::Algoritmo (FIRST COME - FIRST SERVER)::..\n");
    printf("      ----------------------------------------\n");
    do {//Pide el número de procesos y verifica que no exceda el tope de la aplicacion
      printf("Ingresa el número de procesos a planificar : ");
      scanf ("%d",&procesos);
    } while(procesos > 10);
    //Guarda el tiempo de ejecucion para cada proceso
    for (i = 0; i < procesos ; i++){
      printf("Ingrese la duracion del proceso %d: ",i+1);
      scanf ("%d",&proceso[i]);
    }once = proceso[0];
    ini = clock();
    //Se simula el procesamiento restando 1 por iteracion a cada proceso
    printf("-----------Inicia procesamiento -----------------\n");
    for (i = 0; i < procesos; i++) {
      wait += proceso[i];
      answer += proceso[i];
      printf("Tiempo-Espera    : %d\n", wait - once);
      printf("Tiempo-Respuesta : %d\n", answer);
      while (proceso[i] != 0) {
        proceso[i] -= 1;
      }printf("Proceso : %d | terminado.\n",i+1);//retro para el usuario
      printf("-----------------------------------\n");
      once += 1;
    }
    fin=clock();
  	time=fin-ini;
  	printf("El tiempo de ejecucion es de: %d milisegundos\n",time);
}
