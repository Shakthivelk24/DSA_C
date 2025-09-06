#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void DFS(int graph[MAX][MAX],int visited[],int vertex,int n);
int isConnected(int graph[MAX][MAX],int n);

int main(){
   int n,i,j;
   int graph[MAX][MAX];
   printf("Enter the number of vertices : ");
   scanf("%d",&n);
   printf("Enter the adjacency matrix of the graph : \n");
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
    }
   }
   if(isConnected(graph,n)){
     printf("The graph is connected.\n");
   }
   else{
    printf("The graph is not connected.\n");
   }
   return 0;
}

void DFS(int graph[MAX][MAX],int visited[],int vertex,int n){
    visited[vertex] = 1;
    for(int i=0;i<n;i++){
        if(graph[vertex][i]==1&&!visited[i]){
            DFS(graph,visited,i,n);
        }
    }
}

int isConnected(int graph[MAX][MAX],int n){
      int visited[MAX]= {0};
      DFS(graph,visited,0,n);
      for(int i=0;i<n;i++){
        if(!visited[i]){
            return 0;
        }
      }
      return 1;
}
