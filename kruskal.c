#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int u,v,weight;
}Edge;

int compare(const void *a,const void *b){
     Edge *e1 = (Edge *)a;
     Edge *e2 =  (Edge *)b;
     return e1->weight-e2->weight;
}

void kruskal(Edge edges[],int n,int e){
   int component[MAX],totalWeight=0,edgeCount=0;
   for(int i=0;i<n;i++)
    component[i] = i;
   qsort(edges,e,sizeof(Edge),compare);
   printf("Edge in the Minimum Spanning Tree : \n");
   for(int i=0;i<e&&edgeCount<n-1;i++){
      int u = edges[i].u;
      int v = edges[i].v;
      int compU = component[u];
      int compV = component[v];
      if(compU != compV){
        printf("%d---%d = %d\n",u,v,edges[i].weight);
        totalWeight += edges[i].weight;
        edgeCount++;
        for(int j=0;j<n;j++){
            if(component[j]==compV)
                component[j] = compU;
        }
      }
   }
   printf("Total weight of MST : %d\n",totalWeight);
}

int main(){
     int n,e;
     Edge edges[MAX];
     printf("Enter number of vertices : ");
     scanf("%d",&n);
     printf("Enter number of edges : ");
     scanf("%d",&e);
     printf("Enter edges (u v weight) : \n");
     for(int i=0;i<e;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].weight);
     }
     kruskal(edges,n,e);
     return 0;
}
