#include <bits/stdc++.h>
using namespace std;

// Topic: PQ on pairs

struct ComparePair {
  bool operator()(pair<string, int> &p1, pair<string, int> &p2) {
    return p1.second > p2.second;
  }
};

int main() {
  priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

  pq.push({"aman", 500});
  pq.push({"bhumi", 1000});
  pq.push({"chetan", 1500});

  while (!pq.empty()) {
    auto [s, x] = pq.top();
    cout << s << " " << x << endl;
    pq.pop();
  }
  return 0;
}