#include<stdio.h>

// C Program for Merge sort algorithm

// Merge sort divides the array into two subarrays, referred to as "left" and "right".
// Left is further divided into two subarrays, until there are subarrays of one element each.
// Similarly, right is divided till there is one element each.
// Then each element of left is successively compared with each element of right.
// The smaller of the two elements is stored into a temporary array. 
// If left has less elements than right, then the remaining elements in right are copied into temp, and vice versa.


void merge(int arr[], int leftFirst,int leftLast, int rightFirst, int rightLast){
    // leftFirst is a pointer to each element of left subarray.
    // rightFirst is a pointer to each element of right subarray.

    int index = leftFirst;
    int saveFirst = leftFirst;
    int temp[rightLast+1];

    // Iterating through both subarrays
    while ( (leftFirst <= leftLast) && (rightFirst <= rightLast) )
    {
        if( arr[leftFirst] < arr[rightFirst] ){
            temp[index] = arr[leftFirst];
            
            leftFirst++;
            
        }else{
            temp[index] = arr[rightFirst];
            
            rightFirst++;
            
        }
        index++;        
    }

    // If right subarray has less elements than left subarray, the remaining elements in left are copied into temp. 
    while (leftFirst <= leftLast)
    {
        temp[index] = arr[leftFirst];
        leftFirst++;
        
        index++;
        
    }

    // Similarly, if left subarray has less elements than right, the remaining elements in right are copied into temp.  
    while (rightFirst <= rightLast)
    {
        temp[index] = arr[rightFirst];
        rightFirst++;
        
        index++;
        
    }
    // temp is the merged and sorted array. It is copied back to the original array

    for( index = saveFirst; index <= rightLast; index++){
        arr[index]=temp[index];
    }
    // arr is sorted
}


void mergeSort(int arr[], int first,int last){
    int mid;
    
    if(first<last)
    {
        // Middle element of array is found
        mid=(first+last)/2;
        
        // Left subarray is from first to middle index
        mergeSort(arr,first,mid);
        // Right subarray is from (mid + 1) to last index 
        mergeSort(arr,mid+1,last);

        // The subarrays are to be merged.
        merge(arr,first,mid,mid+1,last);
    }
}

// Driver program
int main(){
    int a[]={18, 32, 43, 23, 56, 34, 87, 12, 2, 67};
    int a_size=sizeof(a)/sizeof(a[0]);

    // First call
    mergeSort(a,0,a_size-1);

    // Prints sorted array
    printf("The sorted array is: ");
    for( int i = 0; i < a_size; i++){
        printf("%d ",a[i]);
    }
    return 0;
}