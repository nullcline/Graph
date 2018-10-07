#include <stdio.h>
#include <limits.h>

#define NMAX 8

int root(int v,int p[]);
void union_ij(int i,int j,int p[]);
void kruskal(int w[][NMAX+1],int n);

int main(void){
  int i,j,n=NMAX,w[NMAX+1][NMAX+1];

  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      w[i][j]=INT_MAX;
    }
  }
  w[1][2]=w[2][1]=550;
  w[1][3]=w[3][1]=664;
  w[2][3]=w[3][2]=320;
  w[3][4]=w[4][3]=600;
  w[3][5]=w[5][3]=324;
  w[3][7]=w[7][3]=1230;
  w[4][5]=w[5][4]=150;
  w[5][6]=w[6][5]=110;
  w[6][7]=w[7][6]=54;
  w[6][8]=w[8][6]=780;
  w[7][8]=w[8][7]=240;

  kruskal(w,n);

  return 0;
}

int root(int v,int p[]){
  while(p[v] != v){
    v = p[v];
  }
  return v;
}

void union_ij(int i,int j,int p[]){
  if(j > i){
    p[j] = i;
  }else{
    p[i] = j;
  }
}

void kruskal(int w[][NMAX+1],int n){
  int i,j,k=0,u,v,min,count=0,sum=0;
  int p[NMAX+1],t[NMAX][2];

  for(i=1;i<=n;i++){
    p[i] = i;
  }

  while(count < n){
    min = INT_MAX;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(w[i][j] < min){
          min = w[i][j];
          u = i;
          v = j;
        }
      }
    }
    if(min != INT_MAX){
      i = root(u,p);
      j = root(v,p);
      if(i != j){
        t[k][0] = u;
        t[k][1] = v;
        k++;
        sum += min;
        union_ij(i,j,p);
      }
      w[u][v] = w[v][u] = INT_MAX;
    }
    count += 1;
  }

  if(count != n){
    printf("Spanning tree does not exist\n");
  }else{
    for(k=0;k<n-1;k++){
      printf(" %d -> %d ",t[k][0],t[k][1]);
    }
    printf("\ncost = %d \n",sum);
  }
}