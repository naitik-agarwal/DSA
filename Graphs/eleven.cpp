#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void floydWarshall(vector<vector<int>> &graph) {
  vector<vector<int>> dist = graph;
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF) {
        cout << setw(7) << "INF";
      } else {
        cout << setw(7) << dist[i][j];
      }
    }
    cout << endl;
  }
}

int main() {
  /*
    Example graph:
               10
         (0)------->(3)
          |         /|\
        5 |          |
          |          | 1
         \|/         |
         (1)------->(2)
               3
  */
  vector<vector<int>> graph = {
      {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};
  floydWarshall(graph);
  return 0;
}