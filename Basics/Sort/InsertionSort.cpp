/*
 * Insertion Sort: Divide array into sorted and unsorted, take elements from unsorted part and
 *                  put them at their CORRECT position in the sorted part.
 *
 *      A = [5, 4,10, 1, 6, 2]
 *   Index - 0  1  2  3  4  5  (n = 6)
 * 
 * if element in sorted array > key
 * then shift that element to right
 * and check for another element in sorted part.
 * if element in sorted array < key
 * put k at hollow (--) 
 * 
 * Pass 1 -  5 | 4   10  1   6   2      key = 4
 *               --
 *           5   5   10  1   6   2
 *           --
 * Pass 2 -  4   5 | 10  1   6   2      key = 10
 *                   --
 * Pass 3 -  4   5   10| 1   6   2      key = 1
 *                       --
 *           4   5   10  10  6   2
 *                   --
 *           4   5   5   10  6   2
 *               --      
 *           4   4   5   10  6   2
 *           --
 * Pass 4 -  1   4   5   10| 6   2      key = 6
 *                           --
 *           1   4   5   10  10  2
 *                       --
 * Pass 5 -  1   4   5   6   10| 2      key = 2
 *                               --
 *           1   4   5   6   10  10
 *                           --
 *           1   4   5   6   6   10
 *                       --
 *           1   4   5   5   6   10
 *                   --
 *           1   4   4   5   6   10
 *               --
 *           1   2   4   5   6   10|
 * 
 *         { 1 , 2 , 4 , 5 , 6 , 10 } ->Sorted Array
 * 
 * 
 *  Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int main(){
    
    int a[]={3,4,2,1};
    int n = sizeof(a)/sizeof(int);

    for (int i = 1; i<n; i++){
        int key = a[i];
        int j = i-1;
        int count = 1;
        while (count++ && a[j]>key && j>=0){
            a[j+1]= a[j];
            j--;
        }
        cout<<"Comparisions: "<<count-1<<endl;
        a[j+1] = key;
    }

    for (int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}