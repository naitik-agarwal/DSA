#include <bits/stdc++.h>
using namespace std;
#define int long long

class Graph {
  int V;
  list<int>* l;  // l is a pointer to dynamically allocated array of list of int

 public:
  Graph(int V) {  // constructor
    this->V = V;
    l = new list<int>[V];  // initialized l -> create an array of V linked list
                           // in heap memory
  }

  void addEdge(int u, int v) {  // u,v in zero-indexed
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void print() {
    for (int u = 0; u < V; u++) {  // for all vertices of graph
      cout << "Neighbour of " << u << " :";
      for (int v : l[u]) {  // print all thier neighbours
        cout << v << " ";
      }
      cout << endl;
    }
  }
};

// use list<pair<int,int>>* l for weighted graph....

signed main() {
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(2, 1);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(2, 3);
  graph.print();

  return 0;
}