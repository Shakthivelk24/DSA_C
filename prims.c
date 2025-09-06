#include<stdio.h>
#include<stdlib.h>
void prims(int cost[10][10],int n){
     int a,b,u,v,j,i,visited[10],mincost = 0,min,ne=1;
     for(i=1;i<=n;i++)
        visited[i] = 0;
     printf("\n The edges of the MST \n");
     visited[1] =1;
     while(ne<n){
        min =999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]!=0&&visited[j] == 0){
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0||visited[v]==0){
            printf("\n %d Edges(%d %d) = %d",ne++,a,b,min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
     }
     printf("\n Minimum Total Cost = %d\n",mincost);
}

int main(){
    int n,i,j,cost[10][10];
    printf("\n Read Number of nodes : ");
    scanf("%d",&n);
    printf("\n Read Cost Matrix \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
             cost[i][j] = 999;
        }
    }
    prims(cost,n);
    return 0;
}
