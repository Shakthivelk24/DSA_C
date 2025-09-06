#include<stdio.h>
#include<stdlib.h>
#define INF 999
void dijkstra(int cost[10][10],int n,int source,int v[10],int d[10]){
       int min,j,i,u;
       v[source] = 1;
       for(i=1;i<=n;i++){
           min = INF;
           for(j=1;j<=n;j++){
            if(v[j] == 0 && d[j]<min){
                min = d[j];
                u = j;
            }
           }
       v[u]=1;
       for(j=1;j<=n;j++){
           if(v[j]==0 &&(d[j]>(d[u]+cost[u][j])))
               d[j] = d[u]+cost[u][j];
       }
    }
}
int main(){
     int n,cost[10][10],sourceNode,v[10],d[10];
     int i,j;
     printf("Enter no. of vertices : ");
     scanf("%d",&n);
     printf("Enter cost Adjacency martix : \n");
     for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           scanf("%d",&cost[i][j]);
     printf("Enter the source (%d to %d) : \n",1,n);
     scanf("%d",&sourceNode);
     for(i=1;i<=n;i++){
        d[i] = cost[sourceNode][i];
        v[i] = 0;
     }
     dijkstra(cost,n,sourceNode,v,d);
     printf("Shortest distance from %d \n\n",sourceNode);
     for(i=1;i<=n;i++)
        printf("%d --> %d = %d\n\n",sourceNode,i,d[i]);
     return 0;
}
