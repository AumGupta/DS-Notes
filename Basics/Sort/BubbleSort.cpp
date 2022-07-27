/*
 * Bubble Sort: Every element is compared with its succeeding element 
 *              and swapped if not in correct order.
 *
 *      A = [10,7 ,5 ,4 ]
 *   Index - 0  1  2  3     (n = 4)
 * 
 *  Pass 1 - 10 7  5  4     Pass 2 - 7  5  4  10     Pass 3 - 5  4  7  10    \
 *           ----                    ----                     ----           |  Number of Passes
 *           7  10 5  4              5  7  4  10              4  5  7  10    |  = 3 = (n - 1)
 *              ----                    ----                     ----*        > 
 *           7  5  10 4              5  4  7  10              4  5  7  10    |  Number of Comparisions
 *                 ----                    --->*                    ----*    |  = 3 = (n - 1)
 *           7  5  4  10             5  4  7  10              4  5  7  10    /
 *                    ^                    ^  ^                  ^  ^  ^
 *  Elements \        |                    |  |                  |  |  |
 *  at        >       |                    |  |                  |  |  |
 *  their    |
 *  corect   |        Since, above elements were already at their correct                \
 *  positions|        positions comparisions marked with * are useless hence             |
 *           /        are removed in code for optimisation.                              |
 *                                                                                        > Optimisation
 *                    Also, in some cases the array might get sorted before (n-1) passes |
 *                    hence it is optimised using flag varible named no_swap,            |
 *                    it checks for an iteration of loop in which no swapping was done   |
 *                    which means array is sorted and so it breaks the loop.             /
 * 
 *Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int main(){
    int A[] = {29,30,18,25,10,2,3,10,9};
    int size = sizeof(A)/sizeof(int);

    for (int i = 0; i<size-1; i++){
        int count = 0;
        bool no_swap = true;
        for (int j = 0; j<size-1-i; j++){
            count++;
            if (A[j]>A[j+1]){
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                no_swap = false;
            }
        }
        cout<<"Comparisions: "<<count<<endl;
        if (no_swap) break;
    }


    // Another way
    // bool no_swap = false;
    // for (int i = 0; i<size-1 && !no_swap; i++){
    //     for (int j = 0; j<size-1-i; j++){
    //         if (A[j]>A[j+1]){
    //             int tmp = A[j];
    //             A[j] = A[j+1];
    //             A[j+1] = tmp;
    //             no_swap = false;
    //         }
    //         else no_swap = true;
    //     }
    // }

    for (int i = 0; i<size; i++){
        cout<<A[i]<<"  ";
    }
    return 0;
}