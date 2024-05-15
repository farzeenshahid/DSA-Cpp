#include <iostream>
using namespace std;
int bin_search(int low,int high,int x,int arr[])
{
    if (low <= high) {
        int mid = (low + high)/2;
        if (arr[mid] == x)
            return mid ;
        if (arr[mid] > x)
            return bin_search(low, mid-1, x,arr);
        if (arr[mid] < x)
            return bin_search(mid+1, high, x,arr);
    }
    return -1;
    }
int main(void) {
   int arr[] = {2,5,8,12,23,45,50};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x;
   cout <<"Enter the number to search: ";
   cin >> x;
   int result = bin_search(0, n-1, x,arr);
   if(result == -1)
   {
      cout<< x <<" is not present in the array";
   }
   else
      cout<< x <<" is present at index "<< result <<" in the array";
   
   return 0;
}