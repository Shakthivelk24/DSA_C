#include <stdio.h>
#include <stdlib.h>
void bfs(int a[10][10],int n,int v[10],int source){
    int q[10],f=0,r=-1;
    int node,i;
    v[source] = 1;
    q[++r] = source;
    while(f<=r){
        node = q[f++];
        for(i=1;i<=n;i++){
            if(a[node][i] == 1&&v[i]==0){
                v[i]=1;
                q[++r]=i;
            }
        }
    }
}
int main(){
    int n,source,i,j,count;
    int a[10][10],v[10];
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("\nRead Adjacency matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        v[i] = 0;
    count = 0;
    for(i=1;i<=n;i++){
        if(v[i] == 0){
            bfs(a,n,v,i);
            count++;
        }
    }
    if(count == 1)
        printf("Graph is connected.");
    else
        printf("Graph is not connected with %d components",count);
    return 0;
}
