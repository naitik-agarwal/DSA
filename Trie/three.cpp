#include <bits/stdc++.h>
using namespace std;

// topic: Prefix Problem, given a list of words, return the shortest unique
// prefix of each word

class Node {
 public:
  unordered_map<char, Node *>
      children;    // for every Node we have an unordered map which stores the
                   // info for all its childre, for each children it has a node
  bool endofWord;  // similarly for each node we have the info if a word ends
                   // there or not?
  int wordcnt;

  Node() {
    endofWord = false;
    this->wordcnt = 0;
  }  // obviously no word ends when we initialize the node
};

class Trie {
  Node *root;  // a trie initialize with a empty Node

 public:
  Trie() { root = new Node(); }

  void insert(string key) {  // T.C => O(L)
    Node *temp = root;  // we dont want to do changes on root * so we created an
                        // empty Node *
    for (int i = 0; i < key.size(); i++) {
      if (temp->children.count(key[i]) == 0) {
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
      temp->wordcnt++;
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
  string prefix(string s) {
    string ans;
    Node *temp = root;
    int i = 0;
    while (temp->wordcnt != 1) {
      temp = temp->children[s[i]];
      ans.push_back(s[i]);
      i++;
    }
    return ans;
  }
};

int main() {
  vector<string> words = {"dog", "dot"};
  vector<string> ans;
  Trie trie;
  for (int i = 0; i < words.size(); i++) {
    trie.insert(words[i]);
  }
  for (int i = 0; i < words.size(); i++) {
    ans.push_back(trie.prefix(words[i]));
  }
  for (string word : ans) {
    cout << word << " ";
  }
  cout << endl;
  return 0;
}