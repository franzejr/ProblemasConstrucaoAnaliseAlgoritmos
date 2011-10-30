/*
Questao 2 - Recursao em PD e Memoizado - Francisco Jose Lins Magalhaes - 0322836
Construcao e Analise de Algoritmos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Recursivo puro
	
int P_Recursivo(int n){
	
	if(n < 5){
		return 0;
	}
	else{
		return P_Recursivo(n/2) + P_Recursivo(n/2 + 1) + P_Recursivo(n/2 + 2) + n;
	}
}


//Programacao Dinamica
int P_ProgramacaoDinamica(int n){
	int P[n+1];
	int i;
	
	for(i = 0; i < 5; i++){
		P[i] = 0;
	}
	
	for(i = 5; i <= n; i++){
		P[i] = P[i/2] + P[i/2 + 1] + P[i/2 + 2] + i;
	}
	
	return P[n];
}


int P_Memoizado(int P[],int n){
	
	if(P[n] == -1){
		
		P[n] = P_Memoizado(P,n/2) + P_Memoizado(P,n/2 + 1) + P_Memoizado(P,n/2 + 2) + n;
	
	}

	return P[n];
	
}



int main(int narg, char *argv[]){
	int numero;
	
	FILE *tempos;
	clock_t antes;
	clock_t depois;
	tempos = fopen("temposQuestao2.txt","w");
	int tamanho = atoi((char *)argv[1] );
	double tempoDinamico;
	double tempoMemoizado;
	double tempoRecursivo;
	
	
	//P_ProgramacaoDinamica(numero);
	//P_Recursivo(numero));
	
	//Memoizado
	int i,x;
	int P[tamanho+1];
	
	for(x = 0; x< tamanho; x=x+5000 ){
	
	
		//Setando o vetor que usaremos na memoizacao
		for	(i = 0; i <= 4; i++){
			P[i] = 0; 
		}
	
		for	(i = 5; i <= tamanho; i++){
			P[i] = -1; 
		}
		
		//Memoizado
		antes = clock();
		//printf("Memoizado: %d \n",P_Memoizado(P,x));
		P_Memoizado(P,x);
		depois = clock();
		tempoMemoizado = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
		
		//Dinamico
		antes = clock();
		//printf("Dinamico: %d \n",P_ProgramacaoDinamica(x));
		P_ProgramacaoDinamica(x);
		depois = clock();
		tempoDinamico = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
		
		//Recursivo
		antes = clock();
		//printf("Dinamico: %d \n",P_ProgramacaoDinamica(x));
		P_Recursivo(x);
		depois = clock();
		tempoRecursivo = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
		
		
		fprintf(tempos,"%d %lf %lf %lf\n", x, tempoMemoizado, tempoDinamico, tempoRecursivo);
			
	}
	
	//Fechando o arquivo que ira salvar os tempos
	fclose(tempos);
return 0;
}
