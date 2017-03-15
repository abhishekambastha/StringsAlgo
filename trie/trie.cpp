#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
using std::cout;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;

  //root
  int num_nodes = 0;
  edges root;
  t.push_back(root);



  for(string pattern: patterns){
    int current_node = 0;
    for(int i=0; i<pattern.size(); ++i){
      edges &e = t[current_node];
      char c = pattern[i];
      if(e.find(c) != e.end()){
        current_node = e[c];
      }else{
        e[c] = t.size(); // t.size() is same as num_nodes;
        current_node = t.size();
        edges new_edge;
        t.push_back(new_edge);
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
