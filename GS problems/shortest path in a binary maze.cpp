#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define ROW 10
#define COL 9
using namespace std;
 
struct Point{
    int x;
    int y;
};

struct queueNode{
    Point pt;
    int dist;
};

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int isAccessible(int r, int c){
    return (r >= 0 && c >= 0 && r < ROW && c < COL);
}

int BFS(int mat[][COL], Point src, Point dst){
    if(!mat[src.x][src.y] || !mat[dst.x][dst.y]) return -1;
    bool visited[ROW][COL];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            visited[i][j] = false;
        }
    }
    queue<queueNode> q;
    q.push({src, 0});
    visited[src.x][src.y] = true;
    while(!q.empty()){
        queueNode curr = q.front();
        q.pop();
        Point pt = curr.pt;
        if(pt.x == dst.x && pt.y == dst.y) return curr.dist;
        for(int i=0; i<4; i++){
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
            if(!visited[row][col] && mat[row][col] && isAccessible[row][col]){
                visited[row][col] = true;
                q.push({{row, col}, curr.dist + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
 
    Point source = {0, 0};
    Point dest = {3, 4};
 
    int dist = BFS(mat, source, dest);
 
    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";
 
    return 0;
}