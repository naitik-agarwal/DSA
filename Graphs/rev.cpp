#include <bits/stdc++.h>
using namespace std;

// Topic : Topological Sorting Rev

class Graph {
  int V;
  vector<vector<int>> adj;
  bool isUndir;

 public:
  Graph(int V, bool isUndir = true) {
    this->V = V;
    adj.resize(V);
    this->isUndir = isUndir;
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    if (isUndir) {
      adj[v].push_back(u);
    }
  }
  void printGraph() {
    if (isUndir) {
      cout << "Graph is undirected" << endl;
    } else {
      cout << "Graph is directed" << endl;
    }
    for (int i = 0; i < V; i++) {
      cout << "Neighbours of " << i << ": ";
      for (int v : adj[i]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  void dfs_wp(int src, vector<bool> &vis) {
    vis[src] = true;
    for (int v : adj[src]) {
      if (!vis[v]) {
        dfs_wp(v, vis);
      }
    }
  }
  vector<int> bfs(int src) {
    vector<int> ans;
    queue<int> q;
    vector<bool> vis(V);
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
      int node = q.front();
      ans.push_back(node);
      q.pop();
      for (int v : adj[node]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    return ans;
  }
  // kahn's algorithm
  void inDegree(vector<int> &indeg) {
    for (int i = 0; i < V; i++) {
      for (int v : adj[i]) {
        indeg[v]++;
      }
    }
  }
  vector<int> topoKahnSort() {
    vector<int> ans;
    vector<int> ind(V, 0);
    inDegree(ind);
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (ind[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (int v : adj[node]) {
        if (ind[v] > 0) {
          ind[v]--;
          if (ind[v] == 0) {
            q.push(v);
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Graph g1(6, false);
  g1.addEdge(2, 3);
  g1.addEdge(3, 1);
  g1.addEdge(4, 0);
  g1.addEdge(4, 1);
  g1.addEdge(5, 0);
  g1.addEdge(5, 2);
  vector<int> ans = g1.topoKahnSort();
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}