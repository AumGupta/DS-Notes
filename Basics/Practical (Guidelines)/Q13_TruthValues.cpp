/*
 *13. Write a Program to accept the truth values of variables x and y, and print the truth table of 
 *the following logical operations:
 *    a) Conjunction      f) Exclusive NOR
 *    b) Disjunction      g) Negation
 *    c) Exclusive OR     h) NAND
 *    d) Conditional      i) NOR
 *    e) Bi-conditional 
 *Program by Om Gupta (214047)
 */


#include<iostream>
using namespace std;

int main(){
    bool x,y;
    
    cout<<"ENTER TRUTH VALUE OF `x` : ";
    cin>>x;
    cout<<"ENTER TRUTH VALUE OF `y` : ";
    cin>>y;

    cout<<"\n\nConjunction:\n x ∧ y = " << (x&&y);
    cout<<"\n\nDisjunction:\n x v y = " << (x || y);
    cout<<"\n\nExclusive OR:\n x \u2295 y = " << (x + y) * (!x + !y);
    cout<<"\n\nExclusive NOR:\n ~(x ⊕ y) = " << !((x + y) * (!x + !y));
    cout<<"\n\nConditional:\n x → y = " << ( (!x)||y );
    cout<<"\n\nBi-Conditional:\n x ↔ y = " << ( (x && y) || (!x && !y) );
    cout<<"\n\nNegation:\n ~x = "<< !x <<"\n ~y = "<< !y;
    cout<<"\n\nNAND:\n ~(x ∧ y) = "<< !(x&&y);
    cout<<"\n\nNOR:\n ~(x v y) = "<< !(x||y);

    return 0;
}