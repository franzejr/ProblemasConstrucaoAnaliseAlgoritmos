/*
Questao 3 - Matrix Chain Multiplication - Francisco Jose Lins Magalhaes - 0322836
Construcao e Analise de Algoritmos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INFINITY 999999999

int TAMANHO = 0;

//Gerar o vetor aleatório
int generateRandom(int quantidade, int *p){
	int i = 0;
	//printf("Rands: ");
	//FILE* arquivo;
	//arquivo = fopen (nome_arquivo, "w");
	for(i = 0; i < quantidade ; i++){
		p[i] = (rand()%8) + 2;

	}
	
}


//Algoritmo da Multiplicação de Matrizes
int chainMultiplication(int p[]){
	int i,j,l,k;
	int q = 0;
	int n = TAMANHO-1; // n <- p.size() - 1
	int m[n][n];		
	
	for(i = 0; i<n; i++){
       
	   m[i][i] = 0;
       	}
	for(l = 1; l < n; l++){
		//printf("\ndiagonal %d\n",l+1);
		for(i = 0;i <n-l; i++ ){
		  j = i + l;
		  //printf("tratando posicao %d %d\n",i+1,j+1);
		  m[i][j] = INFINITY;
			for(k = i; k < j; k++){
				q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				//printf("somando %d %d com %d %d\n",i+1,k+1,k+2,j+1);
				//printf("indices do vetor considerados: %d %d %d\n",i+1,k+2,j+2);
					if( q < m[i][j] ){
						m[i][j] = q;
						//Colocar a sequencia que irá receber o parenteses
					}
			}
		}
	}
	
	/*for(i = 0; i < n; i++){
		printf("\n");
		for(j = i; j<n ; j++){
			printf("%.3lf ", m[i][j]);
		}
	}*/
	
	//printf("\n");
	return m[0][n-1];
}

int memoizacao(int *p,int n, int m[n][n], int i, int j){

	int k;
	int q = 0;

    if (m[i][j] == -1)
    {
	
	  m[i][j] = INFINITY;
		for(k = i; k < j; k++){
			q = memoizacao(p,n,m,i,k) + memoizacao(p,n,m,k+1,j)+ p[i]*p[k+1]*p[j+1];

				if( q < m[i][j] ){
					m[i][j] = q;
				}
		}
    }
    return m[i][j];

}

int main(int narg, char *argv[]){

	
	srand(time(NULL));
	clock_t antes;
	clock_t depois;
	double tempoDinamico;
	double tempoMemoizado;

    FILE *arquivo_saida = fopen("temposMultiplicacaoDeMatrizes.txt", "w");
	
	
	int tamanho = atoi((char *)argv[1] );
	
	int p[tamanho];
	
	TAMANHO = tamanho;
	
	int i=0;
	
    int linha, coluna, resultadoDin, resultadoMem;
    int m[tamanho-1][tamanho-1];
    
    for(i = 2; i < tamanho; i++ ){

        generateRandom(i, p);
        TAMANHO = i;
        
        /*Utilizando Programacao Dinamica */
			antes = clock();
				chainMultiplication(p);
			depois = clock();
		    tempoDinamico = (double) (depois - antes)/(double)CLOCKS_PER_SEC;

        
        
        /*Utilizando Memoizacao*/
        
        //Setando a matriz que vou usar na memoizacao
        for(linha = 0; linha < i; linha++){
          
            for(coluna = linha; coluna < i; coluna++){
                m[linha][coluna] = linha==coluna? 0:-1;      
            }
        }
        
	    antes = clock();
	    	memoizacao(p,i,m,0,i-2);
	    depois = clock();
        tempoMemoizado = (double) (depois - antes)/(double)CLOCKS_PER_SEC;
        
 
	    fprintf(arquivo_saida," %d %.5f %.5f\n", i, tempoDinamico, tempoMemoizado);
	
    }	
    fclose(arquivo_saida);
   
    
return 0;
}
