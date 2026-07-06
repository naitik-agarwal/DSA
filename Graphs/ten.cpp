#include <bits/stdc++.h>
using namespace std;

// Topic: Bellman Ford Algorithm

class Edge {
 public:
  int v;
  int wt;

  Edge(int v, int wt) {
    this->v = v;
    this->wt = wt;
  }
};

void bellmanFord(vector<vector<Edge>>& graph, int src, int V) {
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (int u = 0; u < V; u++) {
      for (Edge e : graph[u]) {
        // now do relaxation step here
        if (dist[u] != INT_MAX && (dist[e.v] > e.wt + dist[u])) {
          dist[e.v] = e.wt + dist[u];
        }
      }
    }
  }
  for (int d : dist) {
    cout << d << " ";
  }
  cout << endl;
}

int main() {
  int V = 5;
  vector<vector<Edge>> graph(V);
  graph[0].push_back(Edge(1, 2));
  graph[0].push_back(Edge(2, 4));
  graph[1].push_back(Edge(2, -4));
  graph[2].push_back(Edge(3, 2));
  graph[3].push_back(Edge(4, 4));
  graph[4].push_back(Edge(1, -1));

  // lets run BF algo
  bellmanFord(graph, 4, V);

  return 0;
}