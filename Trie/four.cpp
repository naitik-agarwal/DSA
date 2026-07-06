#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  unordered_map<char, Node *>
      children;    // for every Node we have an unordered map which stores the
                   // info for all its childre, for each children it has a node
  bool endofWord;  // similarly for each node we have the info if a word ends
                   // there or not?

  Node() {
    endofWord = false;
  }  // obviously no word ends when we initialize the node
};

class Trie {
 public:
  Node *root;  // a trie initialize with a empty Node
  Trie() { root = new Node(); }

  void insert(string key) {  // T.C => O(L)
    Node *temp = root;  // we dont want to do changes on root * so we created an
                        // empty Node *
    for (int i = 0; i < key.size(); i++) {
      if (temp->children.count(key[i]) == 0) {
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
    }
    temp->endofWord = true;
  }

  bool search(string s) {  // T.C => O(L) // since searching in unordered map is
                           // almost O(1)
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
      if (temp->children.count(s[i])) {
        temp = temp->children[s[i]];
      } else {
        return false;
      }
    }
    return temp->endofWord;
  }

  bool checkAllPrefixes(string s) {
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
      if (temp->children.count(s[i])) {
        temp = temp->children[s[i]];
        if (temp->endofWord == false) {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  Trie trie;
  for (int i = 0; i < dict.size(); i++) {
    trie.insert(dict[i]);
  }
  int len = 0;
  string ans;
  for (int i = 0; i < dict.size(); i++) {
    if (trie.checkAllPrefixes(dict[i])) {
      if (dict[i].size() > len) {
        len = dict[i].size();
        ans = dict[i];
      }
    }
  }
  cout << ans << endl;
  return 0;
}