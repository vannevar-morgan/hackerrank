#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> edge;
typedef vector<edge> graph;

int count_removable_edges(graph edges, int n);
set<int> get_children(const int i, const graph& edges);
bool can_remove(const int i, const graph& edges);
void remove_edge(graph& edges, const int node_1, const int node_2);
void get_descendants(const int i, const graph& edges, set<int>& desc);

int main() {
  int n;
  int m;
  cin >> n;
  cin >> m;
  int n1, n2;
  graph edges;
  for(int i = 0; i < m; ++i){
    cin >> n1;
    cin >> n2;
    edges.push_back(pair<int, int>(n1, n2));
  }
  
  cout << count_removable_edges(edges, n) << endl;
  return 0;
}

int count_removable_edges(graph edges, int n){
  //
  // Return the number of removable edges in the tree represented by edges,
  // such that tree edges becomes a forest of trees with even number of nodes.
  //
  int count = 0;
  set<int> children;
  for(int i = 1; i < n; ++i){
    children = get_children(i, edges);
    //cout << "node " << i << " has " << children.size() << " children." << endl;
    for(const auto& child : children){
      if(can_remove(child, edges)){
	// delete the edge from node i, to child.
	//cout << "i: " << i << "\tchild: " << child << endl;
	remove_edge(edges, i, child);
	++count;
      }
    }
  }
  return count;
}

set<int> get_children(const int i, const graph& edges){
  //
  // Return the immediate children of a node as a set.
  //
  set<int> ret;
  for(const auto& e : edges){
    if(e.first == i){
      if(e.second > i){
	ret.insert(e.second);
      }
    }else if(e.second == i){
      if(e.first > i){
	ret.insert(e.first);
      }
    }
  }
  return ret;
}

void get_descendants(const int i, const graph& edges, set<int>& desc){
  //
  // Get all descendants of node i, insert them into set, desc.
  //
  set<int> temp = get_children(i, edges);
  for(const auto& c : temp){
    get_descendants(c, edges, desc);
    desc.insert(c);
  }
}

bool can_remove(const int i, const graph& edges){
  //
  // Return true if the subtree (starting at root node, i) has even number of nodes.
  // Return false otherwise.
  //
  set<int> children;
  get_descendants(i, edges, children);
  //cout << "can_remove(), node i: " << i << "\thas this many descendants: " << children.size() << endl;
  if(!children.empty() && children.size() % 2 != 0){
    // this node, + children nodes are an even number of nodes.
    return true;
  }
  return false;
}

void remove_edge(graph& edges, const int node_1, const int node_2){
  //
  // Removes an edge from edges.
  // 
  // The edge removed is either edge(node_1, node_2)
  //                         or edge(node_2, node_1)
  // (only 1 exists in edges)
  //
  auto iter = find(edges.begin(), edges.end(), edge(node_1, node_2));
  if(iter != edges.end()){
    edges.erase(iter);
  }
  iter = find(edges.begin(), edges.end(), edge(node_2, node_1));
  if(iter != edges.end()){
    edges.erase(iter);
  }
}
