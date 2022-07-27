/*
 *Linear Search Implimentation
 *Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int main(){
    int l[] = {1,2,3,4,5,6};
    int size = sizeof(l)/sizeof(l[0]);

    int n;
    cout<<"Enter element to be searched: ";
    cin>>n;

    for (int i = 0 ; i<size; i++) {
        if (l[i] == n){
            cout<<n<<" found at index "<<i;
            return 0;
        }
    }
    cout<<n<<" not found";

    return 0;
}





