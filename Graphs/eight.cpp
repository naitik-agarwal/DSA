#include <bits/stdc++.h>
using namespace std;

// Topic: Topological Sorting

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
  bool bipartiteHelper(int src) {
    vector<bool> vis(V, false);
    queue<int> q;
    vector<int> color(V);  // 0 & 1
    q.push(src);
    vis[src] = true;
    color[src] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int v : adj[node]) {
        if (vis[v]) {
          if (color[v] == color[node]) {
            // cant be bipartite
            return false;
          }
        } else {
          q.push(v);
          vis[v] = true;
          color[v] = !color[node];
        }
      }
    }
    return true;
  }
  bool isBipartite() {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
      if (vis[i] == 0) {
        dfs_wp(i, vis);
        if (!bipartiteHelper(i)) {
          return false;
        }
      }
    }
    return true;
  }
  void allPath(int src, int dest, vector<bool> &vis, vector<vector<int>> &ans,
               vector<int> &path) {
    path.push_back(src);
    vis[src] = true;
  }

  void TopoSort(int src, vector<bool> &vis, stack<int> &s) {
    vis[src] = true;
    for (int v : adj[src]) {
      if (vis[v] == 0) {
        TopoSort(v, vis, s);
      }
    }
    s.push(src);
  }
  // using kahn's algorithm
  void inDegree(vector<int> &ind) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        ind[adj[i][j]]++;
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
  stack<int> s;
  vector<bool> vis(6);
  for (int i = 0; i < 6; i++) {
    if (vis[i] == 0) {
      g1.TopoSort(i, vis, s);
    }
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  vector<int> ans = g1.topoKahnSort();
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  if (ans.size() != 6) {
    cout << "Cycle Detected" << endl;
  } else {
    cout << "No cycle detected" << endl;
  }
  return 0;
}