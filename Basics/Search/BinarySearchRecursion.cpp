/* 
 * 
 * 
 * Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int binary_search_R(int element , int array[], int high, int low);

int main(){
    int array[] = {2,3,4,5,7};
    int size = sizeof(array)/sizeof(int);
    int n;
    cout<<"Enter element to be searched: ";
    cin>>n;
    int index = binary_search_R(n, array, size-1,0);
    if (index>0) cout<<n<<" was found at index "<<index;
    else cout<<n<<" was not found";

    return 0;
}

int binary_search_R(int element , int array[], int high, int low){
    if (low<=high){
        int mid = (high + low)/2;
        if (array[mid] == element) return mid;
        else if (array[mid] > element) return binary_search_R(element, array, mid-1, low);
        else return binary_search_R(element, array, low, mid+1);
    }
    return -1;
}