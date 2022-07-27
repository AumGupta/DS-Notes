/*
 *3. Create a class RELATION, use Matrix notation to represent a relation. Include functions to
 *check if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program
 *to use this class.
 *
 */

#include<iostream>
using namespace std;

class Relation
{
    private:
        int n; //Number of elements in set
        int a[][20];
    public:
        // Destructor
        ~Relation();

        // Constructors
        Relation();
        Relation(int n);
        Relation(int n, int arr[][20]);

        // Utility Functions
        static Relation input();
        void print() const;
        bool isReflexive() const;
        bool isSymmetric() const;
        bool isAntiSymmetric() const;
        bool isTransitive() const;
};

Relation::~Relation(){};

Relation::Relation(){
    n = 1;
    a[1][1] = {0};
}

Relation::Relation(int n){
    this->n = n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a[i][j] = 0;
        }
    }
}

Relation::Relation(int n, int arr[][20]){
    this->n = n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j] = arr[i][j]; 
}

Relation Relation::input(){
    int tmp;
    cout<<"ENTER THE NUMBER OF ELEMENTS IN THE SET\t: ";
    cin>>tmp;
    cout<<"ENTER THE VALUES OF RELATION\t\t: ";

    Relation r(tmp);
    for (int i = 0; i<tmp; i++)
        for (int j = 0; j<tmp; j++)
            cin>>r.a[i][j];
    return r;
}

void Relation::print() const{
    cout<<'\n';
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<'\n';
    }
}

bool Relation::isReflexive() const{
    // Checks for diagonal elements to be 1
    for (int i=0; i<n; i++)
        if (a[i][i] != 1) return false;
    return true;
}

bool Relation::isSymmetric() const{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i]) return false;
    return true;
}

bool Relation::isAntiSymmetric() const{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j]==1 && a[j][i]==1 && i!=j) return false;
    return true;
}

bool Relation::isTransitive() const{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if ( a[i][j]==1 && a[j][k]==1 && a[i][k]!=1 ) return false;
            }
    return true;
}


int main(){
    Relation r = Relation::input();
    cout<<"Given relation:\n";
    r.print();

    if (r.isReflexive()) cout<<"\nReflexive";
    else cout<<"\nNot Reflexive";

    if (r.isSymmetric()) cout<<"\nSymmetric";
    else cout<<"\nNot Symmetric";

    if (r.isTransitive()) cout<<"\nTransitive";
    else cout<<"\nNot Transitive";
    
    if (r.isAntiSymmetric()) cout<<"\n- Anti-Symmetric";
    else cout<<"\n- Not Anti-Symmetric";
    
    return 0;
}