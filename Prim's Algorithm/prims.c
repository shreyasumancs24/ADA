#include <stdio.h>
int cost[10][10], vis[10],wt[10],et[10][10],e=0,i,j,k,u,v,sum=0,n,m;
void prims();

void main(){
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter cost-adjacency matrix:");
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(i=1;i<n+1;i++){
        vis[i]=0;
    }
    prims();
    printf("Minimum Spanning Tree:\n");
    for(i=1;i<e;i++){
        printf("%d->%d\n",et[i][1],et[i][2]);
    }
    printf("Total Cost=%d",sum);
    getch();
}
void prims(){
    int x=1,min;
    wt[x]=1;
    vis[x]=1;
    for(i=1;i<n+1;i++){
        j=x;
        min=999;
        while(j>0){
            k=wt[j];
            for(m=1;m<n+1;m++){
                if(cost[k][m]<min && vis[m]==0){
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
            j--;
        }
        wt[++x]=v;
        et[i][1]=u;
        et[i][2]=v;
        e++;
        vis[v]=1;
        sum+=cost[u][v];
    }
}
