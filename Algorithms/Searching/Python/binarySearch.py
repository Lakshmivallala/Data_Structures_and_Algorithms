#Search Algorithms in Python
def binarySearch (arr, l, r, x):  
    if r >= l: 
  
        mid = l + (r - l) // 2
  
        if arr[mid] == x: 
            return mid 

        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 

        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 

        return -1
  
# Driver Code 
n = int(input())                                
arr = list(map(int, input("enter n terms in a line with space: ").split(' ')[:n]))
x = int(input("Search Value:"))
result = binarySearch(arr, 0, len(arr)-1, x) 
if(result == -1): 
    print("Element is not present in array") 
else: 
    print("Element is present at index", result)