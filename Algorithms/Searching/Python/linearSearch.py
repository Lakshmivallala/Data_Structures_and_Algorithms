#Search Algorithms in Python
def search(arr, n, x): 
  
    for i in range (0, n): 
        if (arr[i] == x): 
            return i 
    return -1 
  
# Driver Code 
n = int(input())                                
arr = list(map(int, input("enter n terms in a line with space: ").split(' ')[:n]))
x = int(input("Search Value:"))
result = search(arr, n, x) 
if(result == -1): 
    print("Element is not present in array") 
else: 
    print("Element is present at index", result)