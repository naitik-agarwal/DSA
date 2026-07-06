#include <bits/stdc++.h>
using namespace std;

// Topic: Word break problem

class Node {
 public:
  unordered_map<char, Node *> children;
  bool endofword;

  Node() { endofword = false; }
};

class Trie {
 public:
  Node *root;
  unordered_map<string, bool> memo;

  Trie() { root = new Node(); }

  void insert(string key) {
    Node *temp = root;
    for (int i = 0; i < key.size(); i++) {
      if (temp->children.count(key[i]) == 0) {
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
    }
    temp->endofword = true;
  }

  bool search(string s) {
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
      if (temp->children.count(s[i])) {
        temp = temp->children[s[i]];
      } else {
        return false;
      }
    }
    return temp->endofword;
  }

  bool wordBreak(
      string key) {  // T.C => O(n^3) because of memoization unless O(2^n)
    if (!key.size()) {
      return true;
    }
    // memoization check
    if (memo.count(key)) {
      return memo[key];
    }
    Node *temp = root;
    for (int i = 0; i < key.size(); i++) {  // takes O(n)
      if (temp->children.count(key[i])) {
        temp = temp->children[key[i]];
        if (temp->endofword) {
          string left = key.substr(i + 1);  // takes O(n)
          if (wordBreak(left)) {            // could happen for n suffixes
            return memo[key] = true;
          }
        }
      } else {
        break;
      }
    }
    return memo[key] = false;
  }
};

int main() {
  vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
  string key = "ilikesamsung";
  Trie trie;
  for (int i = 0; i < dict.size(); i++) {
    trie.insert(dict[i]);
  }
  cout << trie.wordBreak(key) << endl;
  return 0;
}