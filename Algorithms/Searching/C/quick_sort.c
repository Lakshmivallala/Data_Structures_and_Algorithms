#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

//last
int partition(int arr[], int l, int r) {
    int pivot = r;
    int i=l-1;
    for(int j=l; j<=r; j++) {
        if(arr[j]<arr[pivot]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[pivot]);
    return i+1;
}

int qs_last(int arr[], int l, int r) {
    if(l<r) {
        int p = partition(arr, l, r);
        qs_last(arr, l, p-1);
        qs_last(arr, p+1, r);
    }
}

//mid
void qs_mid(int arr[], int l, int r) {
    if(l>=r) return;
    int i=l, j=r;
    int pivot = (l+r)/2;
    pivot = arr[pivot];
    while(i<=j) {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<=j){
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    qs_mid(arr, l, i-1);
    qs_mid(arr, i, r);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n], arr2[n];
    
    printf("Unsorted array: ");
    for(int i=0; i<n; i++) {
        //arr[i] = rand()%10000;
        arr[i] = i;
        arr2[i] = arr[i];
        //printf("%d ", arr[i]);
    }

    //pivot - mid
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    qs_mid(arr, 0, n-1);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nSorted array with middle element as pivot: ");
    //print(arr, n);
    printf("\nIt took %fms", cpu_time_used*1000);

    //pivot - last
    start = clock();
    qs_last(arr2, 0, n-1);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nSorted array with last element as pivot: ");
    //print(arr2, n);
    printf("\nIt took %fms", cpu_time_used*1000);
}