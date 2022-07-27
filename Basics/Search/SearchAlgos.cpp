#include<iostream>

using namespace std;

int binary_search(int element, int size, int array[]); // Only on sorted arrays
int linear_search(int element, int size, int array[]); // On unsorted arrays too

int main(){
    int a[] = {1,2,4,6,10,90,102}; // Sorted Array
    int size = sizeof(a)/sizeof(int);
    int element = 6;

    // int index = binary_search(element, size, a);
    int index = linear_search(element, size, a);

    if (index >= 0) cout<<element<<" found at index "<< index;
    else cout<<element<<" not found.";
    return 0;
}

int binary_search(int element, int size, int array[]){
    int low = 0;
    int high = size-1;
    for (int i = low; i<high; i++){
        int mid = (low+high)/2;
        if (array[mid] == element) return mid;
        if (array[mid] > element) high = mid-1;
        else low = mid+1;
    }
    return -1;
} 

int linear_search(int element, int size, int array[]){
    for (int i = 0; i<size; i++){
        if (array[i] == element) return i;
    }
    return -1;
}