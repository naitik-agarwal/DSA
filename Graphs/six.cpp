#include <bits/stdc++.h>
using namespace std;

// Topic: cycle detection in directed graph

class Graph {
  int V;
  vector<vector<int>> adj;
  bool isUnir;

 public:
  Graph(int v, bool isUnir = true) {
    this->V = v;
    adj.resize(v);
    this->isUnir = isUnir;
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    if (isUnir) {
      adj[v].push_back(u);
    }
  }
  void dfs_wp(int src, vector<bool> &visited) {
    visited[src] = true;
    for (int v : adj[src]) {
      if (visited[v] == false) {
        dfs_wp(v, visited);
      }
    }
  }
  bool cycleDetection(int src, vector<bool> &visited, int parent) {
    visited[src] = true;
    for (int v : adj[src]) {
      if (visited[v]) {
        if (v != parent) {
          return true;
        } else {
          continue;
        }
      } else {
        if (cycleDetection(v, visited, src)) {
          return true;
        }
      }
    }
    return false;
  }
  bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recpath) {
    vis[src] = true;
    recpath[src] = true;
    for (int v : adj[src]) {
      if (!vis[v]) {
        if (dirCycleHelper(v, vis, recpath)) {
          return true;
        }
      } else {
        if (recpath[v]) {
          return true;
        }
      }
    }
    recpath[src] = false;
    return false;
  }
  bool isCycleDir() {
    vector<bool> vis(V, false);
    vector<bool> recpath(V, false);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (dirCycleHelper(i, vis, recpath)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Graph g1(4, false);
  g1.addEdge(1, 0);
  g1.addEdge(0, 2);
  g1.addEdge(2, 3);
  g1.addEdge(3, 0);
  cout << g1.isCycleDir() << endl;
  return 0;
}