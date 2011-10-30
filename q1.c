/*
Questao 1 - Comparacao entre Algoritmos de Ordenacao - Francisco Jose Lins Magalhaes - 0322836
Construcao e Analise de Algoritmos
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"


//Gerar o vetor aleatório e ao mesmo tempo já coloca no arquivo
int generateRandom(int quantidade, double *p){
	int i = 0, numero = 0;

	for(i = 0; i <= quantidade ; i++){
		p[i] = (rand()%999) + 1;
	}
	
}


int main(int narg, char *argv[]){
	
	srand(time(NULL));
	clock_t antes;
	clock_t depois;
	int i;
	FILE *tempos;
	
	tempos = fopen("temposOrdenacao.txt","w");
	
	//Pegando o tamanho do vetor passado por parametro	
	int tamanho = atoi((char *)argv[1] );
	
	//Variaveis que irao guardar o tempo
	double tempoMerge;
	double tempoHeap;
	double tempoQuick;
	
	//Criando os vetores que vao ser utilizados por cada algoritmo de ordenacao
	double vetorMerge[tamanho];
	double vetorHeap[tamanho];
	double vetorQuick[tamanho];
	
	for(i = 1; i < tamanho; i=i+5000){
		
		/*MergeSort*/
			//Gerando vetor aleatorio
			generateRandom(i,vetorMerge);
		
			antes = clock();
			mergeSort(vetorMerge,0,i-1);
			depois = clock();
		    tempoMerge = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
		    
        
		/*HeapSort */
			//Gerando vetor aleatorio
			generateRandom(i,vetorHeap);
		
			antes = clock();
			heapSort(vetorHeap,i);
			depois = clock();
		    tempoHeap = (double) (depois - antes)/(double)CLOCKS_PER_SEC; 
		    
		    
        /*QuickSort */
			//Gerando vetor aleatorio
			generateRandom(i,vetorQuick);
		
			antes = clock();
			quickSort(vetorQuick,0,i-1);
			depois = clock();
		    tempoQuick = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
        
		fprintf(tempos,"%d %lf %lf %lf\n", i, tempoMerge, tempoHeap, tempoQuick);
	
	}		
	
	fclose(tempos);
	
return 0;
}
