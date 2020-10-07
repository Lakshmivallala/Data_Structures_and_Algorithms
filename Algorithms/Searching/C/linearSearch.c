#include<stdio.h>

int main(){
	// Declaring the required variables
	int flag=0,x,n,i;

	// Taking the size of array which is qiven as input
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
	// Defining an array of given size
	int a[n];
	
	// Print the numbers given as input
	printf("Enter the numbers :\n");
	for(i=0;i<n;i++){
		printf("%d. ",i+1);
		scanf("%d",&a[i]);
	}
	
	// Getting the element which we want to search
	printf("Enter the element you want to search : ");
	scanf("%d",&x);
	
	// Searching algo
	for(i=0;i<n;i++){
		if(a[i]==x){
			printf("The number %d is at index %d\n",x,i);
			flag=1;
		}
	}
	
	if(flag==0)
		printf("Element is not in the array\n");
		
	return 0;

}
