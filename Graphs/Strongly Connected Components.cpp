#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
    int numOfVertices;
    list<int>* adjList;
    bool* visited;
    void fillOrder(int vertex, stack<int> &s);
    void DFSUtil(int vertex, bool visited[]);
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
    void printSCC();
    Graph transpose();
};

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
}

void Graph::fillOrder(int vertex, stack<int> &s){ //Same as Topological Sort
    visited[vertex] = true;
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i]){
            fillOrder(*i, s); // Till here same as DFS
        }
    }
    s.push(vertex);    /// Push current vertex to stack which stores result
}

void Graph::DFSUtil(int vertex, bool visited[]){
    visited[vertex] = true;
    cout << vertex << " ";
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

Graph Graph::transpose(){
    Graph g2(numOfVertices);
    for(int v = 0; v<numOfVertices; v++){
        list<int>::iterator i;
        for(i = adjList[v].begin(); i != adjList[v].end(); ++i){
            g2.adjList[*i].push_back(v);
        }
    }
    return g2;
}

void Graph::printSCC(){
    stack<int> s;
    for(int i = 0; i < numOfVertices; i++){
        if(!visited[i]){
            fillOrder(i,s);
        }
    }
    Graph g2 = transpose();
    for(int i = 0; i< numOfVertices; i++){
        visited[i] = false;
    }
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!visited[v]){
            g2.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	/* Let us create the following graph:
	https://www.programiz.com/dsa/strongly-connected-components
    */
    
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);
  
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCC();
  
    return 0;
}
