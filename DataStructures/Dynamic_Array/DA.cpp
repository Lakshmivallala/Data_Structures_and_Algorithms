#include<iostream>
using namespace std;

const int MAX = 1000;

int main()
{
	// 1. STANDARD METHOD 
	int *arr;
	arr = new int[MAX];

	arr[0]=1;
	arr[1]=2;
	arr[2]=3;
	arr[3]=4;
	arr[4]=5;
	arr[5]=6;

	cout<< "Displaying array elements:";


	for(int i=0;i<6;i++) 
	{
		cout<<arr[i]<< " ";
	}

	// 2. USER INPUT METHOD
	int n;
	cout<<"How many elements do you want to store in your dynamic array 2? Enter n"<<"\n";
	cin>>n;

	int *newa;
	newa= new int[n];

	cout<<"Enter values:";
	for(int k=0;k<n;k++)
	{
		cout<<"Input your value:";
		cin>>newa[k];
		cout<<endl;
	}
	cout<<"Displaying array 2:"<<"\n";
	for(int k=0;k<n;k++) 
	{
		cout<<newa[k]<< " ";
	}

	
	cout<<"After delete operation on array:"<<"\n";
	delete [] arr; //For any other regular variable, we skip the parenthesis. We need to include the parenthesis here since we want to delete an array.

	cout<< arr[0]<<endl; //Displays garbage values
	arr=NULL;
	cout<<arr[0]<<endl; //Segmentiation fault (core dumped)

	arr[6]=6; //No output, code stops executing after the segmentation error
	

	return 0;
}