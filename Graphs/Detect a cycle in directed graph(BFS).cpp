// A C Program to demonstrate adjacency list
// representation of graphs
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int numOfVertices;
    list<int>* adjList;
    bool* visited;
    bool isCyclicUtil(int vertex);
    
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

bool Graph::isCyclicUtil(int vertex){
    visited[vertex] = true;
    vector<int> parent(numOfVertices, -1);
    queue<int> q;
    q.push(vertex);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(auto v : adjList[i]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = i;
            }
            else if(parent[i] != v){
                return true;
            }
        }
    }
    return false;
}

bool Graph::isCyclic(){
    for(int i = 0; i < numOfVertices; i++){
        if(!visited[i]){
            if(isCyclicUtil(i)) return true;    
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
