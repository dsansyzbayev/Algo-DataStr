#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
  char value;
  Node *ch[26];
  bool isfirst;
  bool issecond;
  bool isend;
  Node(char value) {
    this->value = value;
    this->isfirst = false;
    this->issecond = false;
    isend = false;
    for (int i = 0; i < 26; i++)
      this->ch[i]=NULL;
  }
};

bool isProb = false;

class Trie {
  public:
  Node *root;
  Trie() {
    root = new Node(' ');
  }


  void insert(string s, int order) {
    Node *cur = root;
    for (int i = 0; i < s.size(); i++) {
      if (cur->ch[s[i]-'a'] != NULL)
        cur = cur->ch[s[i]-'a'];
      else {
        Node *node = new Node(s[i]);
        cur->ch[s[i]-'a'] = node;
        cur = node;
      }
      if (order == 1){
        cur->isfirst = true;
      }
      else if (order == 2)
        cur->issecond = true;
        isProb = true;
      if (i == s.size()-1)
        cur->isend = true;
    }
  }

  void search(Node *node) {
    if (node == NULL)
      return;
    if (node->isfirst && node->issecond)
        isProb = true;

    for (int i = 0; i < 26; i++) {
      search(node->ch[i]);
    }
  }

};

int main() {
  Trie *trie = new Trie();
  int nCity;
  cin >> nCity;
  for(int i = 0; i < nCity; i++){
    int num;
    cin >> num;
    for(int j = 0; j < num; j++){
      string pNum;
      cin >> pNum;
      for(int k = 0; k < pNum.size(); k++){
        string t = pNum.substr(i);
        trie->insert(t,1);
        trie->insert(t,2);
      }
    }
    trie->search(trie->root);
    if(isProb == true){
      cout << "YES";
  } else cout << "NO";
  }
  return 0;
}