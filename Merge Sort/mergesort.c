#include<stdio.h>
#include<time.h>
int n;
/*int time(float size){
    if(size==1){
        return 0;
    }
    else{
        return (2*time(size/2)+size);
    }
}*/

void merge(int a[], int low, int mid, int high){
    int i, j, k, c[n];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=a[j++];
        }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=high){
        c[k++]=a[j++];
    }
    for(i=low; i<=high; i++){
        a[i]=c[i];
    }
}

void mergesort(int a[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

void main(){
   /* printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n-1);
    printf("\nSorted array:");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }*/
    int i;
    clock_t start, end;
    double time_taken;
    srand(time(NULL));
    printf("N\tTime Taken(seconds)\n");
    for(n=10000; n<=50000; n+=10000){
        int a[n];
        for(i=0; i<n; i++){
            a[i]=rand()%10000;
        }
        start=clock();
        mergesort(a, 0, n-1);
        end=clock();
        time_taken=(double)(end-start)/CLOCKS_PER_SEC;
        printf("%d\tTime taken: %f\n", n, time_taken);
    }
}
