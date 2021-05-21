// A C Program to demonstrate adjacency list
// representation of graphs
#include <iostream>
#include <list>
using namespace std;

class Graph{
    int numOfVertices;
    list<int>* adjList;
    bool* visited;
    bool isCyclicUtilUsingDFS(int vertex, int parent);
    
    public:
    Graph(int vertices){
        this->numOfVertices = vertices;
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        for(int i = 0; i < numOfVertices; i++){
            visited[i] = false;
        }
    }
    void addEdge(int src, int dest);
    bool isCyclic();
};

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

bool Graph::isCyclicUtil(int vertex, int parent){
    visited[vertex] = true;
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i] && isCyclicUtil(*i, vertex)){   //Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function returns true, return true. 
            return true;
        }
        else if(*i != parent){ //If an adjacent vertex is visited and is not parent of current vertex, then there exists a cycle in the graph.
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    for(int i = 0; i < numOfVertices; i++){
        if(!visited[i]){
            if(isCyclicUtil(i, -1)) return true;    
        }
    }
    return false;
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
