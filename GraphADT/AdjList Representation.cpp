#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph { //Weighted Version
private:
    int numV;
    bool directed;
    vector<list<pair<int, int>>> adjlist;

public:
    Graph(int ver, bool isDir = false) {
        numV = ver;
        directed = isDir;
        adjlist.resize(ver);
    }

    void addEdge(int src, int des) {
        if (src >= numV || des >= numV || src < 0 || des < 0) {
            cout << "Invalid Edge\n";
            return;
        }
        adjlist[src].push_back({des, 0});  // unweighted, so weight = 0
        if (!directed)
            adjlist[des].push_back({src, 0});
    }

    void removeEdge(int src, int des) {
        adjlist[src].remove_if([des](const pair<int, int>& p) {
            return p.first == des;
        });
        if (!directed) {
            adjlist[des].remove_if([src](const pair<int, int>& p) {
                return p.first == src;
            });
        }
    }

    void printGraph() {
        for (int i = 0; i < numV; ++i) {
            cout << "Node " << i << ": ";
            for (auto& edge : adjlist[i]) {
                cout << edge.first << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);  // Undirected graph with 5 nodes

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.printGraph();

    cout << "\nAfter removing edge (0, 2):\n";
    g.removeEdge(0, 2);
    g.printGraph();

    return 0;
}


/*#include<iostream>
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
}; */
