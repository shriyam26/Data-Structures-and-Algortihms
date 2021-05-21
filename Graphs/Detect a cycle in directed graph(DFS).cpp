// A C Program to demonstrate adjacency list
// representation of graphs
#include <iostream>
#include <list>
#define SIZE 40
using namespace std;

class Graph{
    int numOfVertices;
    list<int>* adjList;
    bool* visited;
    bool* rStack;
    bool isCyclicUtil(int vertex);
    
    public:
    Graph(int vertices){
        this->numOfVertices = vertices;
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        rStack = new bool[vertices];
        for(int i = 0; i < numOfVertices; i++){
            visited[i] = false;
            rStack[i] = false;
        }
    }
    void addEdge(int src, int dest);
    bool isCyclic();
};

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
}

bool Graph::isCyclicUtil(int vertex){
    visited[vertex] = true;
    rStack[vertex] = true;
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i] && isCyclicUtil(*i)){    //Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function returns true, return true.
            return true;
        }
        else if(rStack[*i]){  //If the vertices are already marked in the recursion stack then return true
            return true;
        }
    }
    rStack[vertex] = false; // remove the vertex from recursion stack
    return false;
}

bool Graph::isCyclic(){
    for(int i = 0; i < numOfVertices; i++){
        if(isCyclicUtil(i)) return true;
    }
    return false;
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
