// A C Program to demonstrate adjacency list
// representation of graphs

/*In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. */
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
    int numOfVertices;
    list<int>* adjList;
    bool* visited;
    void topoSortUtil(int vertex, stack<int> &s);
    
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
    void topoSort();
};

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
}

void Graph::topoSortUtil(int vertex, stack<int> &s){
    visited[vertex] = true;
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i]){
            topoSortUtil(*i, s); // Till here same as DFS
        }
    }
    s.push(vertex);    /// Push current vertex to stack which stores result
}

void Graph::topoSort(){
    stack<int> s;
    for(int i = 0; i < numOfVertices; i++){
        if(!visited[i]){
            topoSortUtil(i, s);    
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topoSort();
 
    return 0;
}
