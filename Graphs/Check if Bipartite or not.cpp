// A C Program to demonstrate adjacency list
// representation of graphs
/*
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS). 
1. Assign RED color to the source vertex (putting into set U). 
2. Check if its neigbhour is coloured or not, if coloured then check whether same or different. If same the return false, if different then push that vertex pair into queue.
3. Similary check for all vetrex and their neigbours.
*/
#include <iostream>
#include <list>
#include <queue>
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
    void addEdge(int src, int dest);
    bool isBipartite();
};

void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

bool Graph::isBipartite(){
    int color[numOfVertices];
    /*to store colour of vertex
    assiging all to -1 i.e. uncoloured
    colours are either 0 or 1
    for understanding take 0 as red and 1 as blue*/
    for(int i = 0; i< numOfVertices; i++){
        color[i] = -1;
    }
    queue<pair<int, int>> q; //queue will contain a pair of {vertex,  color}
    for(int i = 0; i<numOfVertices; i++){
        if(color[i] == -1){
            color[i] = 0;  //Mark source as RED
            q.push({i, 0});
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;   //save current vertex
                int c = p.second;  //save color of current vertex
                for(auto j : adjList[v]){
                    if(color[j] == c){  // This means wo adjacent vertices have same colur, so graph is not bipartite
                        return false;
                    }
                    if(color[j] == -1){ //if adjacent vertex is not coloured
                        color[j] = c ? 0 : 1; // then mark different colour than adjancent vertex
                        q.push({j, color[j]});  // push vertex and colour into queue
                    }
                }
            }
        }
    }
    return true;
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
 
    bool ans = g.isBipartite();
    //returns 1 if bipatite graph is possible
      if (ans)
        cout << "Yes\n";
    //returns 0 if bipartite graph is not possible
      else
        cout << "No\n";
 
    return 0;
}
