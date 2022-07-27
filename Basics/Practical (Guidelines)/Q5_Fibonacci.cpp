/*
 *5. Write a Program to generate the Fibonacci Series using recursion. 
 *
 */


#include<iostream>
using namespace std;

// void printFibonacci(int n){
//     static int n1=0, n2=1, n3;  
//     if(n>0){
//         n3 = n1 + n2;
//         n1 = n2;
//         n2 = n3;
//         cout<<n3<<" ";
//         printFibonacci(n-1);
//     }    
// }

int Fibonacci(int n){
    if (n<=1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    int x;
    cout<<"ENTER NUMBER OF TERMS OF FIBONACCI SERIES: ";
    cin>>x;
    // printFibonacci(x);

    for(int i=0; i<x; i++){
        cout<<Fibonacci(i)<<' ';
    }
    return 0;
}

