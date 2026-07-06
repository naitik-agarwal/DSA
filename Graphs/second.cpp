#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;  // number of vertices in our graph
  list<int> *l;

 public:
  Graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }
  void addEdge(int u, int v) {
    l[u].push_back(v);
    l[v].push_back(u);
  }
  void printGraph() {
    for (int u = 0; u < V; u++) {
      cout << "Neighbours of " << u << " :";
      for (int v : l[u]) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  vector<int> BFS(
      int src) {  // time complexity of bfs is O(V+E) as every node is explored
                  // once and every edge is explored once
    vector<int> bfs;
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (int v : l[node]) {
        if (visited[v] == false) {
          visited[v] =
              true;  // when adding in queue -> then only mark as visited
                     // ->> very very important (always remember)
          q.push(v);
        }
      }
    }
    return bfs;
  }  // Space complexity of BFS is O(V) -> you can see from code

  void DFS(int src, vector<bool> &visited) {
    // Rule of DFS => keep going to first unvisited neighbour
    // time complexity : O(V+E) => same reason as BFS
    // Space complexity : O(V)
    visited[src] = true;
    cout << src << " ";
    for (int v : l[src]) {
      if (visited[v] == false) {
        DFS(v, visited);
      }
    }
  }
};

int main() {
  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(1, 2);
  g1.addEdge(1, 3);
  g1.addEdge(2, 4);
  g1.addEdge(3, 4);

  g1.printGraph();

  vector<int> bfs = g1.BFS(0);
  for (int i = 0; i < bfs.size(); i++) {
    cout << bfs[i] << " ";
  }
  cout << endl;

  vector<bool> visited(6);
  g1.DFS(0, visited);
  cout << endl;

  return 0;
}