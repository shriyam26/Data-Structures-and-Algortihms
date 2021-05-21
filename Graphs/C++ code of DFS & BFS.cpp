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
    
    public:
    Graph(int vertices){
        this->numOfVertices = vertices;
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        for(int i = 0; i < numOfVertices; i++){
            visited[i] = false;
        }
    }
    void printGraph(void);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void BFS(int vertex);
};

void Graph::printGraph(){
    for (int v = 0; v < numOfVertices; ++v){
        list<int> temp = adjList[v];
        cout << "\n Adjacency list of vertex "<< v << endl;
        for (auto x : temp)
           cout << " " << x;
        cout<<endl;
    }
}

void Graph::addEdge(int src, int dest){
    adjList[src].push_front(dest);
    adjList[dest].push_front(src);
}

void Graph::DFS(int vertex){
    visited[vertex] = true;
    cout << "DFS Visited vertex: "<< vertex <<endl;
    list<int>::iterator i;
    for(i = adjList[vertex].begin(); i != adjList[vertex].end(); i++){
        if(!visited[*i]){
            DFS(*i);
        }
    }
}

void Graph::BFS(int vertex){
    visited[vertex] = true;
    list<int> queue;
    queue.push_back(vertex);
    list<int>::iterator i;
    int v;
    while(!queue.empty()){
        v = queue.front();
        cout << "BFS Visited vertex: "<< v <<endl;
        queue.pop_front();
        for(i = adjList[v].begin(); i != adjList[v].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	// print the adjacency list representation of the above graph
	g.printGraph();
	g.DFS(2);
	g.BFS(0);

	return 0;
}
