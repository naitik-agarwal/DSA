#include <bits/stdc++.h>
using namespace std;

// Topic: cycle detection in directed graph

bool dfs(int src, vector<int> &state, vector<vector<int>> &adj) {
  state[src] = 1;
  for (int v : adj[src]) {
    if (state[v] == 1) {
      return false;
      // cycle detected
    } else if (state[v] == 0) {
      if (dfs(v, state, adj)) {
        return true;
      }
    }
    // if(state[v]==2)  => we can ignore as state 2 means no cycle goes through
    // this node and through all its descendants
  }
}

int main() { vector<vector<int>> adj; }