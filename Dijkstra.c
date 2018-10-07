#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define START 5
#define NMAX 8

int main(void){
  int i,j,n=NMAX,next,min;
  char visited[NMAX+1];
  int distance[NMAX+1],prev[NMAX+1];
  int weight[NMAX+1][NMAX+1];

  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      weight[i][j]=INT_MAX;
    }
  }
  weight[1][2]=weight[2][1]=550;
  weight[2][3]=weight[3][2]=320;
  weight[2][4]=weight[4][2]=430;
  weight[3][5]=weight[5][3]=270;
  weight[4][5]=weight[5][4]=150;
  weight[4][6]=weight[6][4]=170;
  weight[5][6]=weight[6][5]=110;
  weight[6][7]=weight[7][6]=60;
  weight[7][8]=weight[8][7]=520;

  for(i=1;i<=n;i++){
    visited[i]=FALSE; distance[i]=INT_MAX;
  }
  distance[START]=0;next=START;
  do{
    i=next; visited[i]=TRUE; min=INT_MAX;
    for(j=1;j<=n;j++){
      if(visited[j]) continue;
      if(weight[i][j]<INT_MAX && distance[i] + weight[i][j]<distance[j]){
        distance[j]=distance[i]+weight[i][j];
        prev[j]=i;
      }
      if(distance[j]<min){
        min=distance[j]; next=j;
      }
    }
  } while(min<INT_MAX);

  printf("点 直前の点 最短距離\n");
  for(i=1;i<=n;i++){
    if(i!=START && visited[i]){
      printf("%2d%10d%10d\n",i,prev[i],distance[i]);
    }
  }

  return 0;
}