#include <bits/stdc++.h>
using namespace std;

// Topic: Prim's Algorithm

class Graph {
  int V;
  vector<vector<pair<int, int>>> adj;
  bool isUnir;

 public:
  Graph(int v, bool isUnir = true) {
    this->V = v;
    adj.resize(v);
    this->isUnir = isUnir;
  }
  void addEdge(int u, int v, int wt) {
    adj[u].push_back({v, wt});
    if (isUnir) {
      adj[v].push_back({u, wt});
    }
  }
  void primsAlgo(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<bool> mst(V, false);
    pq.push({0, src});
    int ans = 0;
    while (pq.size() > 0) {
      auto [cost, u] = pq.top();
      pq.pop();
      if (!mst[u]) {
        mst[u] = true;
        ans += cost;
        for (auto [v, wt] : adj[u]) {
          pq.push({wt, v});
        }
      }
    }
    cout << ans << endl;
  }
};

int main() {
  Graph g1(4, true);
  g1.addEdge(0, 1, 10);
  g1.addEdge(0, 2, 15);
  g1.addEdge(0, 3, 30);
  g1.addEdge(1, 3, 40);
  g1.addEdge(2, 3, 50);

  g1.primsAlgo(0);

  return 0;
}