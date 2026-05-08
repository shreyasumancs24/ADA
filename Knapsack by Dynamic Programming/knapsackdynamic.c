#include <stdio.h>

struct item{
    int weight,profit;
};

int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

void main(){
    int m,n;
    printf("Enter capacity of the bag: ");
    scanf("%d",&m);
    printf("Enter no. of objects: ");
    scanf("%d",&n);
    int v[n+1][m+1];
    struct item items[n+1];
    int sol[n+1];
    for(int i=1;i<n+1;i++){
        printf("Weight for object %d: ",i);
        scanf("%d",&items[i].weight);
        printf("Profit for object %d: ",i);
        scanf("%d",&items[i].profit);
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }
            else if(items[i].weight>j){
                v[i][j]=v[i-1][j];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i-1][j-items[i].weight]+items[i].profit);
            }
        }
    }
    printf("Maximum profit: %d\n",v[n][m]);
    printf("Table:\n");
    for(int i=0;i<n+1;i++){
        sol[i]=0;
        for(int j=0;j<m+1;j++){
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    int j=m;
    while(j>0){
        for(int i=n;i>0;i--){
            if(v[i][j]!=v[i-1][j]){
                sol[i]=1;
                j=j-items[i].weight;
            }
        }
    }
    printf("Solution:");
    for(int i=1;i<n+1;i++){
        printf("%d ",sol[i]);
    }
}
