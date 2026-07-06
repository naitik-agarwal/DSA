#include <bits/stdc++.h>
using namespace std;

// Topic: cycle detection in undirected graph

class Graph {
  int V;
  vector<vector<int>> adj;

 public:
  Graph(int v) {
    this->V = v;
    adj.resize(v);
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
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
};

int main() {
  Graph g1(10);
  g1.addEdge(1, 6);
  g1.addEdge(6, 4);
  g1.addEdge(4, 9);
  g1.addEdge(4, 3);
  g1.addEdge(3, 8);
  g1.addEdge(3, 7);
  g1.addEdge(2, 5);
  g1.addEdge(2, 0);
  g1.addEdge(7, 1);
  vector<bool> visited(10);
  //   int components = 0;
  //   for (int i = 0; i < 10; i++) {
  //     if (visited[i] == 0) {
  //       g1.dfs_wp(i, visited);
  //       components++;
  //     }
  //   }
  //   cout << components << endl;
  cout << g1.cycleDetection(1, visited, -1) << endl;
  return 0;
}