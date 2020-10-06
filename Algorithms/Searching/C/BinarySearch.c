#include<stdio.h>

int main(){
	
	// Declaring required variables
  int flag=0,x,n,i,j,m;
	
	// Getting size of array
  printf("Enter the size of array : ");
  scanf("%d",&n);
	
	// Declaring an array of given size
  int a[n];
	
	// Printing the numbers that are taken as input
  printf("Enter the numbers :\n");
  for(i=0;i<n;i++){
  	printf("%d. ",i+1);
    scanf("%d",&a[i]);
	}
	
	// Getting the element value that should be searched
  printf("Enter the element you want to search : ");
  scanf("%d",&x);

	i=0;
	j=n;
	
	// Binary searching
	while(i<j){
		m=(i+j)/2;
		if(a[m]==x){
			printf("The element is at index %d\n",m);
			flag=1;
			break;
		}
		else if(a[m]<x){
			i=m+1;
		}
		else{
			j=m;
		}
	}

	if(flag==0)
		printf("Element not found");
		
	return 0;
}
