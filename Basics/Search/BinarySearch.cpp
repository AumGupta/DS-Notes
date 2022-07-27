/*
 *Binary Search
 *Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int binarySearch(int[], int, int);

int main(){
    int array[] = {2,3,4,5,7};
    int n;
    cout<<"Enter element to be searched: ";
    cin>>n;
    int index = binarySearch(array, 5,n);
    if (index>0) cout<<n<<" was found at index "<<index;
    else cout<<n<<" was not found";

    return 0;
}

int binarySearch(int array[], int size, int element){
    int low = 0;
    int high = size-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (array[mid] == element)
        {
            return mid;
        }
        else if (array[mid] > element)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}