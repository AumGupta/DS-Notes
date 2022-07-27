#include<iostream>

using namespace std;

int main()
{
	int m,i;
	
	cout << "\nEnter the maximum no. of children in full m-ary tree: ";
	cin >> m;
	
	cout << "Enter the number of internal vertices: ";
	cin >> i;

	cout << "Number of Leaf Nodes in the full m-ary tree: " << (i * (m - 1) + 1);
	
	return 0;
}

// int leafNodes(int m, int i){
// 	return (m-1)*i + 1;
// }

// int calcVertices(int m, int i){
// 	return m*i +1;
// }