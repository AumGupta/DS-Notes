/*
1. Write a Program to create a SET A and determine the cardinality of SET for an input array of
elements (repetition allowed) and perform the following operations on the SET:
a) ismember (a, A): check whether an element belongs to set or not and return value as
true/false.
b) powerset(A): list all the elements of power set of A.
*/

#include<iostream>
#include<array>

using namespace std;

bool ismember(int, int[]);
void powerset(int[], int);

int main(){
    int n;
    cout<<"Enter the number of members of SET A: ";
    cin>>n;
    int A[n] = {0};
    cout<<"Enter the elements of SET A (Separated by Space): ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    cout<<ismember(4, A)<<'\n';
    powerset(A,n);
    return 0;

}

bool ismember(int a, int A[]){
    int i=0;
    while (A[i]){
        if (A[i] == a) return true;
        i++;
    }
    return false;
}

void powerset(int A[],int s){
    //Left Shift Operator: N=N<<2 then N will become N=N*(2^2)
    int n = 1<<s; //2^s

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s; j++)
        {
            int x = i & (1<<j);
            if (x)
            {
                cout<<A[j];
            }
        }
        cout<<'\n';
    }
}
