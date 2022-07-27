/* 
 * 7. Write a Program to implement binary search using recursion.
 * 
 * Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int binary_search(int element,int arr[], int low, int hing);

int main(){
    int arr[] = {1,2,3,4,5,7,90};
    int size = sizeof(arr)/sizeof(int);
    int element = 999;    
    int index = binary_search(element, arr, 0, size-1);
    if (index != -1) cout<<element<<" found at "<<index;
    else cout<<element<<" not found.";   
    return 0;
}

int binary_search(int element,int arr[], int low, int high){
    if (low<=high){
        int mid = (high+low)/2;
        if (arr[mid] == element) return mid;
        if (arr[mid] > element) return binary_search(element, arr, low, mid-1);
        return binary_search(element, arr, mid+1, high);
    }
    return -1;
}
