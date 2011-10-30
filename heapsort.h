void maxHeapify(double vetor[], int raiz, int ultimo)
{
  int concluido, maior, temp;
 
  concluido = 0;
  while ((raiz*2 <= ultimo) && (!concluido))
  {
    if (raiz*2 == ultimo)
      maior = raiz * 2;
    else if (vetor[raiz * 2] > vetor[raiz * 2 + 1])
      maior = raiz * 2;
    else
      maior = raiz * 2 + 1;
 
 	//Se for menor entao troca
    if (vetor[raiz] < vetor[maior])
    {
      temp = vetor[raiz];
      vetor[raiz] = vetor[maior];
      vetor[maior] = temp;
      raiz = maior;
    }
    //Se for maior, nao precisa fazer mais nada. Sai do loop
    else
      concluido = 1;
  }
  
}

void heapSort(double vetor[], int tamanhoVetor)
{
  int i, temp;

	//Criando o Max-Heap 
  for (i = (tamanhoVetor / 2); i >= 0; i--)
    maxHeapify(vetor, i, tamanhoVetor - 1);
 
 	//Ordenando 
  for (i = tamanhoVetor-1; i >= 1; i--)
  {
    temp = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = temp;
    maxHeapify(vetor, 0, i-1);
  }
}
