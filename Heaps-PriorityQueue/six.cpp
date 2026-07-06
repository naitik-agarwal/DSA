#include <bits/stdc++.h>
using namespace std;

// Topic: Nearby Cars

class Car {
 public:
  int idx;
  int distSq;

  Car(int idx, int distSq) {
    this->idx = idx;
    this->distSq = distSq;
  }

  bool operator<(const Car &obj) const { return this->distSq > obj.distSq; }
};

int square(int x) { return x * x; }

void nearbyCars(vector<pair<int, int>> pos, int k) {  // T.C : O(n+klog(n))
  vector<Car> cars;
  for (int i = 0; i < pos.size(); i++) {
    int distSq = square(pos[i].first) + square(pos[i].second);
    cars.push_back(Car(i, distSq));
  }

  priority_queue<Car> pq(
      cars.begin(), cars.end());  // would take O(n), if we would do by loop and
                                  // push_back(), it would take O(nlog(n))
  for (int i = 0; i < k; i++) {
    cout << "car " << pq.top().idx << " " << pq.top().distSq << endl;
    pq.pop();
  }
}

int main() {
  vector<pair<int, int>> pos;
  pos.push_back({3, 3});
  pos.push_back({5, -1});
  pos.push_back({-2, 4});

  int k = 2;

  nearbyCars(pos, k);

  return 0;
}