#define INFINITY 999999


int intercala (double v[], int p, int q, int r) {
   
	int v2c, a, b, i;
	int tamanho=(r-p+1);
	double vetorAux[tamanho];
	v2c=q+1;
	a=p;
	b=v2c;
	i=0;
	while ( (a <= q) && (b <= r) ) {
		    
		    if ( v[a] < v[b] ) { vetorAux[i++]=v[a++];}
		    else { vetorAux[i++]=v[b++];}
	}
	
	if (a <= q) while (i < tamanho) vetorAux[i++]=v[a++];
	else while ( i < tamanho ) vetorAux[i++]=v[b++];
	a=p;
	
	for (i=0 ; i < tamanho ; i++) {
		v[a++]=vetorAux[i];
	}

}

void mergeSort(double A[], int p, int r){
	int q;

	if(p < r){
		q = (p + r)/2;
		
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		intercala(A, p , q, r);
	}
}
