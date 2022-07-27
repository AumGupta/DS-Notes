/*
2. Create a class SET and take two sets as input from user to perform following SET 
Operations:
    a) Subset: Check whether one set is a subset of other or not.
    b) Union and Intersection of two Sets.
    c) Complement: Assume Universal Set as per the input elements from the user.
    d) Set Difference and Symmetric Difference between two SETS
    e) Cartesian Product of Sets.
*/

#include <iostream>
using namespace std;

class Set {
    public:
        int n;
        int *arr;

        // Constructors
        Set() {
            n = 0;
            arr = nullptr;
        }
        Set(int n) {
            arr = new int[n];
            this->n = n;
        }
        Set(int n,int *temp) {
            this->n = n;
            arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = temp[i];
        }

        // Utility Functions
        void input() const {
            for (int i = 0; i < n; i++) cin >> arr[i];
        }

        void print() const {
            cout << "{ ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i];
                if(i != n-1) cout<<", ";
            }
            cout << " }\n";
        }
};

int check(int key,int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

bool CheckSubset(Set superset,Set subset){
    for (int i = 0; i < subset.n; i++)
    {
        if ( check(subset.arr[i], superset.arr, superset.n) == -1)
            return false;
    }
    return true;
};

Set Union(Set a,Set b){
    int temp[a.n + b.n];
    int counter = 0;
    for (int i = 0; i < a.n; i++)
    {
        temp[i] = a.arr[i];
        counter++;
    }

    for (int i = 0; i < b.n; i++)
    {
        int x = check(b.arr[i], a.arr, a.n);
        if (x==-1){
            temp[counter++] = b.arr[i];
        }
    }
    Set result = Set(counter,temp);
    return result;
}

Set Intersection(Set a,Set b){
    int temp[a.n + b.n];
    int counter = 0;
    for (int i = 0; i < a.n; i++)
    {
        int x = check(a.arr[i], b.arr, b.n);
        if ( x != -1){
            temp[counter++] = a.arr[i];
        }
    }
    
    return Set(counter,temp);
}

Set Compliment(Set a,Set unionSet){
    int temp[unionSet.n];
    int counter = 0;
    for (int i = 0; i < unionSet.n; i++)
    {
        if ( check(unionSet.arr[i], a.arr, a.n) == -1){
            temp[counter++] = unionSet.arr[i];
        }
    }
    
    return Set(counter,temp);
}

Set Difference(Set a,Set b){
    return Intersection(a,Compliment(b,Union(a,b)));
}

Set SymmetricDifference(Set a,Set b){
    return Union(Difference(a,b),Difference(b,a));
}

void CartisianProduct(Set a, Set b){
    cout << "{ ";
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < b.n; j++)
        {
            cout << "{" << a.arr[i] << "," << b.arr[j] << "}";
            if (i+j != a.n+b.n-2) cout<<", ";
        }
    }
    cout << " }\n";
}



int main(){
    int n;
    cout << "ENTER THE NUMBER OF ELEMENTS IN Set A: " ;
    cin >> n;
    Set a = Set(n);
    cout << "ENTER THE ELEMENTS IN Set A (Separated by spaces): ";
    a.input();

    cout << "ENTER THE NUMBER OF ELEMENTS IN Set B: " ;
    cin >> n;
    Set b = Set(n);
    cout << "ENTER THE ELEMENTS IN Set B (Separated by spaces): ";
    b.input();

    cout << "\nSet A : ";
    a.print();
    cout << "\nSet B : ";
    b.print();

    cout << "\n\nCONCLUSIONS DRAWN: \n";

    if ( CheckSubset(a,b) ) cout << "Set B is a Subset of Set A.\n";
    else cout << "Set B is NOT a Subset of Set A.\n";

    Set universal_set = Union(a,b);

    cout << "\nUnion Set A & Set B is :\n";
    Union(a,b).print();

     cout << "\nIntersection of Set A & Set B is :\n";
     (Intersection(a,b)).print();

     cout << "\nCompliment of Set A is :\n";
     (Compliment(a,universal_set)).print();

     cout << "\nCompliment of Set B is :\n";
     (Compliment(b,universal_set)).print();

     cout << "\nSet A-B (difference) is :\n";
     (Difference(a,b)).print();

     cout << "\nSet B-A (difference) is :\n";
     (Difference(b,a)).print();

     cout << "\nSymmetric Differnce between Set A & Set B is :\n";
     (SymmetricDifference(a,b)).print();

     cout << "\nCartesian Product of Set A & Set B is : \n";
     CartisianProduct(a,b);
    
    return 0;
}