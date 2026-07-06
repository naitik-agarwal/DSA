#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  vector<vector<int>> adj;

 public:
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void printGraph() {
    for (int u = 0; u < V; u++) {
      cout << "Neighbours of " << u << " :";
      for (int v : adj[u]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  void dfs(int src, vector<bool> &visited) {
    visited[src] = true;
    cout << src << " ";
    for (int v : adj[src]) {
      if (visited[v] == false) {
        dfs(v, visited);
      }
    }
  }
  vector<int> BFS(int src) {
    vector<int> bfs;
    queue<int> q;
    vector<bool> visited(V);
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (int v : adj[node]) {
        if (visited[v] == false) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    return bfs;
  }
};

int main() {
  Graph g1(8);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 3);
  g1.addEdge(5, 3);
  g1.addEdge(2, 4);
  g1.addEdge(3, 4);
  g1.addEdge(5, 4);
  g1.addEdge(5, 6);

  g1.printGraph();
  vector<int> bfs = g1.BFS(0);
  for (int i = 0; i < bfs.size(); i++) {
    cout << bfs[i] << " ";
  }
  cout << endl;
  vector<bool> visited(8);
  //   g1.dfs(0, visited);
  //   cout << endl;
  int src = 0, dest = 6;
  g1.dfs(src, visited);
  cout << endl;
  if (visited[dest] == 1) {
    cout << "Path exist between src and dest" << endl;
  } else {
    cout << "No path exist" << endl;
  }

  return 0;
}