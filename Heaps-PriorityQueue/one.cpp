#include <bits/stdc++.h>
using namespace std;

int main() {
  //   priority_queue<int> pq;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(5);
  pq.push(10);
  pq.push(13);
  pq.push(14);
  pq.push(3);
  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  return 0;
}