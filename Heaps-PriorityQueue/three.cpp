#include <bits/stdc++.h>
using namespace std;

// Topic: PQ for objects

class Heap {
  vector<int> vec;

 public:
  void push(int x) {
    vec.push_back(x);
    int childid = vec.size() - 1;
    int parentid = (childid - 1) / 2;
    while (parentid >= 0 && vec[childid] > vec[parentid]) {
      swap(vec[parentid], vec[childid]);
      childid = parentid;
      parentid = (childid - 1) / 2;
    }
  }
  void heapify(int x) {
    int lchild = 2 * x + 1;
    int rchild = 2 * x + 2;
    int maxid = x;
    if (vec[lchild] > vec[maxid]) {
      maxid = lchild;
    }
    if (vec[rchild] > vec[maxid]) {
      maxid = rchild;
    }
    if (maxid != x) {
      swap(vec[maxid], vec[x]);
      heapify(maxid);
    }
  }
  void pop() {
    if (vec.empty()) {
      return;
    }
    swap(vec[0], vec[vec.size() - 1]);
    vec.pop_back();
    heapify(0);
  }
  bool isEmpty() { return vec.size() == 0; }
  int top() {
    if (vec.size() == 0) {
      return -1;
    }
    return vec[0];
  }
};

class Student {
 public:
  string name;
  int marks;

  Student(string name, int marks) {
    this->name = name;
    this->marks = marks;
  }

  // we need to define a custom comparator to let pq know how to put element in
  // pq (priority) we would use overloading concept
  bool operator<(const Student &obj) const {
    return this->marks < obj.marks;  // ascending
  }
};

int main() {
  priority_queue<Student> pq;
  pq.push(Student("Student1", 100));
  pq.push(Student("Student2", 50));
  pq.push(Student("Student3", 70));

  while (!pq.empty()) {
    cout << pq.top().name << " " << pq.top().marks << endl;
    pq.pop();
  }

  return 0;
}