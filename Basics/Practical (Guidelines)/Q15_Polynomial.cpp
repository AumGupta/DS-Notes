/*
 *Program by Om Gupta (214047)
 */


#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void polynomial(int degree,int value_of_x){
    int result,tmp;
    string poly = "";
    for (int i = degree; i>=0; i--){
        if (i) {
            cout<<"Enter coefficient of x^"<<i<<" : ";
            cin>>tmp;

            if (i==degree && !tmp){ //to check coefficient of highest degree is not 0
                cout<<"Coefficient of x^"<<degree<<" can't be 0.";
                break;
            }
            if (tmp){
                result += tmp*pow(value_of_x, i);

                if (i!= degree) poly.append(" + ");
                if (tmp != 1) poly.append(to_string(tmp));
                poly.append("x");
                if (i != 1) poly.append("^"+to_string(i));
                }
            }
        else{
            cout<<"Enter constant term: ";
            cin>>tmp;
            if (tmp){ //to check if constant term is zero
                result+=tmp;
    
                poly.append(" + "+to_string(tmp));
            }
        }
    }
    if (result) cout<<"\nf(x) = "<<poly<<"\nf("<<value_of_x<<") = "<<result;

}

int main(){
    polynomial(3,2); // takes degree and value of x
    return 0;
}