#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int n;

int partition(int a[],int low,int high){
    int i,j,temp,pivot;
    pivot=a[low];
    i=low+1;
    j=high;
    while(i<=j){
        while(i<=high && a[i]<=pivot){
            i++;
        }
        while(j>=low && a[j]>pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quiksort(int a[],int low,int high){
    int p;
    if(low<high){
        p=partition(a,low,high);
        quiksort(a,low,p-1);
        quiksort(a,p+1,high);
    }
}
void main(){
    clock_t start,end;
    double time_taken;
    srand(time(NULL));
    printf("N\tTime Taken(seconds)\n");
    for(n=10000;n<=50000;n+=10000){
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=rand()%10000;
        }
        start=clock();
        quiksort(a,0,n-1);
        end=clock();
        time_taken=(double)(end-start)/CLOCKS_PER_SEC;
        printf("%d\tTime used:%f\n",n,time_taken);
    }
}
