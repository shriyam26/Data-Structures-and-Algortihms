// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct Node{
  int vertex;
  struct Node* next;
};

struct Graph{
    int vertices;
    struct Node** adjLists;
    int* visited;
};

struct Queue{
  int item[SIZE];
  int front;
  int rear;
};

struct Node* createNode(int v){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->next =  NULL;
    return temp;
}

struct Queue* createQueue(){
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

struct Graph* createGraph(int vertices){
    struct Graph* temp = malloc(sizeof(struct Graph));
    temp->vertices = vertices;
    temp->adjLists = malloc(vertices * sizeof(struct Node*));
    temp->visited = malloc(vertices* sizeof(int));
    for(int i = 0; i<vertices ; i++){
        temp->adjLists[i] = NULL;
        temp->visited[i] = 0;
    }
    return temp;
}

int isEmpty(struct Queue* q){
    if(q->rear == -1) return 1;
    return 0;
}

void enqueue(struct Queue* q, int val){
    if(q->rear == SIZE) return;
    if(q->front == -1) q->front = 0;
    q->rear++;
    q->item[q->rear] = val;
}

int dequeue(struct Queue* q){
    int item;
    if(isEmpty(q)) return -1;
    item = q->item[q->front];
    q->front++;
    if(q->front > q->rear){
        printf("\n Resetting queue \n");
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

void printQueue(struct Queue* q){
    if(isEmpty(q)) return;
    int i = q->front;
    printf("\n Queue contains \n");
    for(i = q->front; i<=q->rear; i++){
        printf(" %d", q->item[i]);
    }
}

void addEdge(struct Graph* graph, int src, int dest){
    struct Node* temp = createNode(dest);
    temp->next = graph->adjLists[src];
    graph->adjLists[src] = temp;
    
    temp = createNode(src);
    temp->next = graph->adjLists[dest];
    graph->adjLists[dest] = temp;
}

void printGraph(struct Graph* graph){
    for(int i = 0; i<graph->vertices; i++){
        struct Node* temp = graph->adjLists[i];
        printf("\n Adjacency list of vertex %d\n", i);
        while(temp){
            printf(" %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph* graph, int vertex){
    struct Node* temp = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("\n Visited %d\n", vertex);
    while(temp){
        int connected = temp->vertex;
        if(!graph->visited[connected]){
            DFS(graph, connected);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph* graph, int vertex){
    struct Queue* q = createQueue();
    graph->visited[vertex] = 1;
    enqueue(q, vertex);
    while(!isEmpty(q)){
        printQueue(q);
        int curr = dequeue(q);
        printf("\n Visited vertex %d \n", curr);
        struct Node* temp = graph->adjLists[curr];
        while(temp){
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// print the adjacency list representation of the above graph
	printGraph(graph);
	DFS(graph, 2);
	BFS(graph, 0);

	return 0;
}
