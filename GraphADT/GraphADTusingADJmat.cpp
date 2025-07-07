#include <iostream>
using namespace std;
#include <queue>
const int V=4; //4 vertices #define V 4;
class Graph{
private:
int AdjMat[V][V];
public:
Graph(){
AdjMat[V][V]={0};
}
void addEdge(int i, int j){
AdjMat[i][j]=1;
//AdjMat[j][i]=1; //Removed for directed graph
}
void Display(){
   cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j)
                cout << AdjMat[i][j] << " ";
            cout << endl;
        }
    }
void BFS(int start){
  queue<int> Q;
    bool visited[V] = {false};  // visited[i] = true if visited

    visited[start] = true;
    Q.push(start);

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        cout << current << " ";

        for (int i = 0; i < V; ++i) {
            if (AdjMat[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}
    
}
void DFS(int node){
  bool visited[V]={false};
   visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < V; ++i) {
        if (AdjMat[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
};
