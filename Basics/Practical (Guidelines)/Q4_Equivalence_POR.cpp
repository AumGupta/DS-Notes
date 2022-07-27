/*
 * 4. Use the functions defined in Ques 3 to find check whether the given relation is:
 *  a) Equivalent, or
 *  b) Partial Order relation, or
 *  c) None
 *Program by Om Gupta (214047)
 */


#include<iostream>
#include<C:\Users\aaumg\Files\Programming\C++\DS\Practical (Guidelines)\Relation.h> //Location of Relation.h
using namespace std;

int main(){
    Relation r = Relation::input();

    int e,p;
    if (r.isReflexive() && r.isSymmetric() && r.isTransitive()) cout<<"Relation is Equivalent";
    else (e=1);
    if (r.isReflexive() && r.isAntiSymmetric() && r.isTransitive()) cout<<"Relation is Partial Order Relation";
    else (p=1);

    if (e&&p) cout<<"Relation is neither equivalent nor partial ordering relation";

    return 0;
}