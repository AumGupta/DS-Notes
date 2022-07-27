#include <iostream>
using namespace std;

bool Euler(int degree[10], int ver)
{
	int flag = 1;
	int count = 0;
	for (int k = 0; k < ver && flag; k++)
	{
		if (degree[k] % 2 != 0)
		{
			flag = 0;
			return false;
		}
		for (int k = 0; k < ver; k++)
		{
			if (degree[k] % 2 != 0)
				count++;
		}
		if (count == 2)
			cout << endl
				 << endl
				 << "The given graph is an Euler Path ";
	}
	return true;
}

int main()
{
	int arr[10][10];
	int v;
	int e;
	int sum;
	int deg[10];
	bool p = true;
	cout << endl
		 << "Enter the number of vertices : ";
	cin >> v;
	cout << endl
		 << "Enter the number of edges : ";
	cin >> e;
	for (int i = 0; i < v; i++)
	{
		cout << "Enter row " << i << " : ";
		for (int j = 0; j < v; j++)
			cin >> arr[i][j];
	}
	cout << endl
		 << "The adjacenecy matrix for the graph is " << endl
		 << endl;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < v; i++)
	{
		sum = 0;
		for (int j = 0; j < v; j++)
			sum += arr[i][j];
		deg[i] = sum;
	}
	for (int k = 0; k < v; k++)
	{
		cout << endl
			 << "The degree of vertex " << k + 1 << " is: ";
		cout << deg[k];
	}
	p = Euler(deg, v);
	if (!p)
		cout << endl
			 << endl
			 << "The given graph is not an Euler circuit " << endl;
	else if (p)
		cout << endl
			 << endl
			 << "The given graph is an Euler grpah as well as an Euler circuit " << endl;
	return 0;
}


// #include <iostream>
// using namespace std;
  
// // Number of vertices in the graph
// #define V 4
  
// // A naive recursive function to count
// // walks from u to v with k edges
// int countwalks(int graph[][V], int u, int v, int k)
// {
//     // Base cases
//     if (k == 0 && u == v)
//         return 1;
//     if (k == 1 && graph[u][v])
//         return 1;
//     if (k <= 0)
//         return 0;
  
//     // Initialize result
//     int count = 0;
  
//     // Go to all adjacents of u and recur
//     for (int i = 0; i < V; i++)
//         if (graph[u][i] == 1) // Check if is adjacent of u
//             count += countwalks(graph, i, v, k - 1);
  
//     return count;
// }
  
// // driver program to test above function
// int main()
// {
//     /* Let us create the graph shown in above diagram*/
//     int graph[V][V] = { { 0, 1, 1, 1 },
//                         { 0, 0, 0, 1 },
//                         { 0, 0, 0, 1 },
//                         { 0, 0, 0, 0 } };
//     int u = 0, v = 3, k = 2;
//     cout << countwalks(graph, u, v, k);
//     return 0;
// }