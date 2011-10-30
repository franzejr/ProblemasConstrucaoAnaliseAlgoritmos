
void troca(double *data1,double *data2) {

  int temp;
  temp=*data1;
  *data1=*data2;
  *data2=temp;
  
}

void quickSort(double v[],int p,int r){
    int q;
    if(p<r){
        q = particaoAleatoria(v,p,r);
        quickSort(v,p,q-1);
        quickSort(v,q+1,r);
    }
}

int particaoAleatoria(double v[],int p,int r){
    int i=rand()%(p-r);
    i+=p;
    troca(&v[r],&v[i]);
    return particione(v,p,r);
}

int particione(double v[],int p,int r){
    int i,j;
    double x;
    x=v[r];
    i=p-1;
    for(j=p;j<=r-1;++j){
        if(v[j]<=x){
            i++;
            troca(&v[i],&v[j]);
        }
    }
    troca(&v[i+1],&v[r]);
    return i+1;
}
