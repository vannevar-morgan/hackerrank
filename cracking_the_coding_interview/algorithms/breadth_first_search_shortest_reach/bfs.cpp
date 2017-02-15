#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Graph {
  int total_nodes;
  map<int, set<int> > adj_list;
  map<int, int> distances;
  int scale_factor = 6;
    
public:
  Graph(int n) : total_nodes(n) {
    for(int i = 0; i < n; ++i){
      adj_list[i] = set<int>();
    }
  }
  
  void add_edge(int u, int v) {
    // add an edge to the graph.
    adj_list[u].insert(v);
    adj_list[v].insert(u);
  }
    
  vector<int> shortest_reach(int start) {
    // calculate the shortest reach to all nodes, from the starting node.
    set<int> next;
    set<int> frontier;
    set<int> visited;
    next.insert(start);
    distances[start];
    while(!next.empty()){
      for(const auto& n : next){
	if(!visited.count(n)){
	  for(const auto& i : adj_list[n]){
	    frontier.insert(i);
	    if(!distances.count(i)){
	      distances[i] = distances[n] + 1;
	    }
	  }
	  visited.insert(n);
	}
      }
      next = frontier;
      frontier.clear();
    }
    vector<int> dists;
    for(int i = 0; i < total_nodes; ++i){
      if(distances[i] == 0){
	dists.push_back(-1);
      }else{
	dists.push_back(scale_factor * distances[i]);
      }
    }
    return dists;
  }
    
};

int main() {
  int queries;
  cin >> queries;
        
  for (int t = 0; t < queries; t++) {
      
    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6: 
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
	cout << distances[i] << " ";
      }
    }
    cout << endl;
  }
    
  return 0;
}
