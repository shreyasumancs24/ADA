#include <stdio.h>

int cost[10][10], t[10][10];
int min, i, j, count, sum, k, u, v, n, parent[10];

void kruskal();
void union_ij(int,int);
int find(int);

int main(){
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    kruskal();
    return 0;
}

void kruskal(){
    count=0;
    k=0;
    sum=0;

    for(i=0;i<n;i++){
        parent[i]=i;
    }

    while(count != n-1){
        min = 999;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][j] < min && cost[i][j] != 0){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);

        if(i != j){
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += min;
            union_ij(i,j);
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nSpanning tree edges:\n");
    for(i=0;i<k;i++){
        printf("%d -> %d\n", t[i][0], t[i][1]);
    }

    printf("Total cost = %d\n", sum);
}

void union_ij(int i,int j){
    if(i < j){
        parent[j] = i;
    } else {
        parent[i] = j;
    }
}

int find(int v){
    while(parent[v] != v){
        v = parent[v];
    }
    return v;
}
