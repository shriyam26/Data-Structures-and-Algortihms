/*Using adjacency matrix*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define V 5

void primMST(int G[V][V]){
    bool visited[V];
    for(int i = 0; i<V; i++){
        visited[i] = false;
    }
    visited[0] = true;
    int count = 0;
    while(count < V-1){
        int min = INT_MAX;
        int x = 0, y = 0;
        for(int i = 0; i<V; i++){
            if(visited[i]){
                for(int j = 0; j<V; j++){
                    if(!visited[j] && G[i][j]){
                        if(min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = true;
        cout << x << "-" << y << ":" << G[x][y] << endl;
        count++;
    }
}

int main() {
  /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // Print the solution 
    primMST(graph); 
  
    return 0; 
}