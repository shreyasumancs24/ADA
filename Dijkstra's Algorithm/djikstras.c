#include<stdio.h>
int src, dist[10], cost[10][10], n, vis[10];

void djikstras(){
    int i, min, count, u;
    for(i=1; i<=n; i++){
        dist[i]=cost[src][i];
        vis[src]=1;
        count=1;
    }
    while(count<n){
        min=999;
        for(i=1; i<=n; i++){
            if(dist[i]<min && vis[i]==0){
                min=dist[i];
                u=i;
            }
        }

        vis[u]=1;
        for(i=1; i<=n; i++){
            if(dist[u]+cost[u][i]<dist[i] && vis[i]==0){
                dist[i]=dist[u]+cost[u][i];
            }
        }
        count++;
    }
}


void main(){
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix:\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    djikstras();
    printf("Shortest path: ");
    for(i=1; i<=n; i++){
        printf("\n%d->%d=%d", src, i, dist[i]);
    }
    getch();
}
