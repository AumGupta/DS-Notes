/*
 * Selection Sort: Minimum element is SELECTED from the unsorted part of the array and 
 *              swapped with the first element. 
 *
 *      A = [10,7 ,5 ,40 , 1]
 *   Index - 0  1  2   3   4    (n = 5)
 * 
 *   Array - | 10  7   5   40   1
 *             --               ^               \    Here,
 *  Pass 1 -   1 | 7   5   40   10              |    
 *                 --  ^                         >   ` | ` = Divider for sorted and unsorted part.
 *  Pass 2 -   1   5 | 7   40   10              |    ` ^ ` = Minimum element in unsorted part.
 *                     ^                        |    `-- ` = Element to be swapped with minimum.
 *  Pass 3 -   1   5   7 | 40   10              |
 *                         --   ^               |    Number of Passes = n
 *  Pass 4 -   1   5   7   10 | 40              /
 * 
 *  Sorted Array = {1, 5, 7, 10, 40}
 * 
 *  Program by Om Gupta (214047)
 */

#include<iostream>
using namespace std;

int main(){
    int A[] = {10,2,4,7,20,1};
    int size = sizeof(A)/sizeof(int);

    // Selection Sort 
    for (int i = 0; i<size-1; i++){
        int min = i;
        for (int j = i+1; j<size; j++){
            if (A[j] < A[min]) min = j;
        }
        if (min != i){
            // Swapping
            int tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }

    // Sorted Array 
    for (int i = 0; i<size; i++){
        cout<<A[i]<<"  ";
    }

    return 0;
}
