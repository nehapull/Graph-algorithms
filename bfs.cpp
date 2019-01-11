//breadth first search implementation

#include <iostream>
#include <list>
#include <queue>

using namespace std;

//create an adjacency list
//u is the present vertex, v is the adjacent vertex
void createList(list<int> *adjacencyList, int numVertices, int u, int v)
{
	//list<int> *adjacencyList = new list<int>[numVertices]; 	
	adjacencyList[u].push_back(v);
	//adjacencyList[v].push_back(u);
	
}

//implement BFS function
//first enqueue source vertex to queue
//next dequeue and find adjacent vertices using adj list
//mark the vertices as discovered
//enqueue these vertices to the queue
//repeat until queue is empty
void BFS(list<int> *adjList, vector<bool> discovered, int source)
{
	//declare present vertex u 
	int u;
	//step1: create a queue
	queue <int> StoreVertex;
	StoreVertex.push(source);

	while(!StoreVertex.empty())
	{
		u = StoreVertex.front();
		StoreVertex.pop();
		cout << "bfs order: = " << u << endl;
		discovered[u] = true;

		//declare an iterator to traverse adjacency list
		list<int>::iterator i;

		for(i = adjList[u].begin(); i != adjList[u].end(); i++)
		{
			//cout << "i = " << *i << endl;
			//vertex visited is white
			if(!discovered[*i])
			{
				discovered[*i] = true;
				StoreVertex.push(*i);
			}
		}
	}
}

//main function that adds the edges to the adj list and calls BFS
int main()
{
	//vertices ranging from 0 to 6
	const int numVertices = 7; 
	vector <bool> visit(numVertices, false);
	
	//set source as vertex 0
	//bfs on 0
	int source = 0;
	list<int> *activeList = new list<int>[numVertices];
	//activeList.size() = numVertices;
	//cout << "main size = " << activeList->size() << endl;
	createList(activeList, activeList->size(), 0, 1);
	createList(activeList, activeList->size(), 0, 2); 
	createList(activeList, activeList->size(), 1, 3);
	createList(activeList, activeList->size(), 2, 1);
	createList(activeList, activeList->size(), 3, 2);
	createList(activeList, activeList->size(), 4, 3);
	createList(activeList, activeList->size(), 4, 5);
	createList(activeList, activeList->size(), 5, 5);
	createList(activeList, activeList->size(), 6, 5);
	createList(activeList, activeList->size(), 6, 2);

	BFS(activeList, visit, source);

}