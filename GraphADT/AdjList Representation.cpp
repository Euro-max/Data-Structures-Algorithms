#include<iostream>
using namespace std;
struct Node{
int vertex;
Node*next;
Node(int v) : vertex(v), next(nullptr) {}
};
class Graph(){
public:
int V;
  Node**adjList;
  Graph(){
    adjList=new int*[V];
    for(int i=0;i<V;i++){
      adjList[i]=nullptr;
}
  }
void AddEdge(int i, int j){
  Node* node = new Node(j); //Make new node carrying j
        node->next = adjList[i]; //Make this node the next of adjList[i]
        adjList[i] = node; //Update the node to point to adj[i]

        // Add i to j’s list (undirected graph)
        node = new Node(i);
        node->next = adjList[j];
        adjList[j] = node;
}
void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << i << " → ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
