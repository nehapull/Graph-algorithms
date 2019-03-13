//depth first search implementation

#include <iostream>
#include <list>
#include <queue>

using namespace std;

//create an adjacency list
//u is the present vertex, v is the adjacent vertex
void createList(list<int> *adjacencyList, int u, int v)
{
	//list<int> *adjacencyList = new list<int>[numVertices]; 	
	adjacencyList[u].push_back(v);
	
}

//DFSVisit function - recursive function that marks starting node as visited
//then it traverses through adjacency list and calls the function again when 
//a new vertex is visited
//update the vector discovered everytime a new vertex is visited
//u = current node
void DFSVisit(list<int> *adjacencyList, int u, vector<bool> &discovered) 
{ 
	// Mark the current node as visited and print it 
	discovered[u] = true; 
	cout << u << " "; 
	cout << endl;

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for(i = adjacencyList[u].begin(); i != adjacencyList[u].end(); i++) 
		if(!discovered[*i]) 
			DFSVisit(adjacencyList, *i, discovered); 
} 

void DFS(list<int> *adjacencyList, int& numVertices, vector<bool> &visited, int& u) 
{ 
	//print number of vertices
	cout << "num vertices = " << numVertices << endl;
	
	// Call the recursive helper function to print DFS traversal 
	// starting from the source vertex 
		if (visited[u] == false) 
		{
			DFSVisit(adjacencyList, u, visited); 
		}
} 

int main()
{
	//vertices ranging from 0 to 3
	int numVertices = 4; 
	//intialize visit vector where all elements are false
	vector <bool> visit(numVertices, false);

	//start search at vertex 2
	int u = 2;

	//initialize adjacency list
	list<int> *adjacencyList = new list<int>[numVertices];

	//create adjacency list
	createList(adjacencyList, 0, 1);
	createList(adjacencyList, 0, 2);
	createList(adjacencyList, 1, 2);
	createList(adjacencyList, 2, 0);
	createList(adjacencyList, 2, 3);
	createList(adjacencyList, 3, 3);

	DFS(adjacencyList, numVertices, visit, u);
}
