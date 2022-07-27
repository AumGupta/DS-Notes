#include<iostream>

using namespace std;

void bubble_sort(int *array, int size);
void selection_sort(int *array, int size);
void insertion_sort(int *array, int size);

int main(){
    int a[] = {30,20,10,17};
    int size = sizeof(a)/sizeof(int);

    // bubble_sort(a,size);
    // selection_sort(a,size);
    insertion_sort(a,size);

    for (int i = 0; i < size; i++){
        cout<<a[i]<<'\n';
    }

    return 0;
}

void bubble_sort(int *array, int size){
    int tmp;
    for (int i = 0; i<size-1; i++){
        bool no_swap = false;
        for (int j = 0; j<size-1; j++){
            if (array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }else no_swap = true;
        }
        if (no_swap) break; // Checks a PASS with no swaps => array is sorted, hence breaks.
    }
}

void selection_sort(int *array, int size){
    for (int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if (array[j]<array[min]) min = j;
        }
        if (min != i){
            int tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

void insertion_sort(int *array, int size){
    for (int i = 1; i<size; i++){
        int tmp = array[i];
        int j = i-1;
        while(j>=0 && array[j]>tmp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }
}