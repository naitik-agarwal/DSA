#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  vector<vector<int>> l;

 public:
  Graph(int V) {
    this->V = V;
    l.resize(V);
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
  }
  void print() {
    for (int i = 0; i < V; i++) {
      cout << "Neighbours of " << i << " ";
      for (int j = 0; j < l[i].size(); j++) {
        cout << l[i][j] << " ";
      }
      cout << endl;
    }
  }
  void DFS(int src, vector<bool> &visited) {}
};

int main() {}