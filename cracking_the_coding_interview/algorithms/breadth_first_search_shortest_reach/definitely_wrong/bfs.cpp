#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

typedef pair<int, int> meta;
typedef pair<int, int> edge;
typedef map<edge, int> graph;
typedef pair<graph, meta> query;

void process_graph(query& q);
void make_network(graph& node_map, bool back_propagate = true);

template<typename TK, typename TV>
vector<TK> extract_keys(map<TK, TV> const& input_map) {
  vector<TK> retval;
  for (auto const& element : input_map) {
    retval.push_back(element.first);
  }
  return retval;
}


int main() {
  int q; // # of queries
  cin >> q;
    
  vector<query> queries;
  for(int qi = 0; qi < q; ++qi){
    int n; // # of nodes
    int e; // # of edges
    cin >> n;
    cin >> e;
    // read in the edges for a graph
    graph node_map;
    int n1;
    int n2;
    for(int i = 0; i < e; ++i){
      cin >> n1;
      cin >> n2;
      node_map[edge(n1, n2)] = 1;
      node_map[edge(n2, n1)] = 1;
    }
    int s; // starting node
    cin >> s;
    queries.push_back(query(node_map, meta(s, n)));
  }
    
  for(auto& nm : queries){
    process_graph(nm);
    cout << endl;
  }
    
  return 0;
}

void process_graph(query& q){
  graph node_map = q.first;
  int s = q.second.first; // starting node
  int n = q.second.second; // number of nodes in graph
  int scale_factor = 6; // scaling factor for unit distance
  make_network(node_map);
  /*
    for(const auto& e : node_map){
    cout << "edge: " << e.first.first << ", " << e.first.second << "\tdist: " << e.second << endl;
    }
  */
  /*
    for(int i = 1; i <= n; ++i){
    if(i == s){
    continue;
    }
    if(!node_map.count(edge(i, s)) && !node_map.count(edge(s, i))){
    // then no direct path exists
    }
    }
  */
  for(int i = 1; i <= n; ++i){
    if(i == s){
      continue;
    }
    if(node_map.count(edge(s, i))){
      cout << scale_factor * node_map[edge(s, i)] << " ";
    }else{
      cout << "-1 ";
    }
  }
}


void make_network(graph& node_map, bool back_propagate){
  //
  // make_network() adds edges for any nodes connected by proxy.
  // edges added to node_map will have distances equal to their distance by proxy.
  //
  vector<edge> edges = extract_keys(node_map);
  for(int i = 0; i < edges.size() - 1; ++i){
    for(int j = i + 1; j < edges.size(); ++j){
      if(edges[i].first == edges[j].first){
	// edge1 connects node1 w / node2, edge2 connects node1 w / node3
	// then node2 and node3 connect.
	if(!(edges[i].second == edges[j].second)){                
	  if(!node_map.count(edge(edges[i].second, edges[j].second))){
	    node_map[edge(edges[i].second, edges[j].second)] = node_map[edges[i]] + node_map[edges[j]];
	  }else{
	    // node exists so we need to check the dist value and compare dists
	    int dist = node_map[edges[i]] + node_map[edges[j]];
	    if(dist < node_map[edge(edges[i].second, edges[j].second)]){
	      node_map[edge(edges[i].second, edges[j].second)] = dist;
	    }
	  }
	  //cout << "added edge, check 1, edge: " << edges[i].second << ", " << edges[j].second << endl;
	}
      }
      if(edges[i].first == edges[j].second){
	// edge1 connects node1 w / node2, edge2 connects node3 w / node1
	// then node2 and node3 connect.
	if(!(edges[i].second == edges[j].first)){
	  if(!node_map.count(edge(edges[i].second, edges[j].first))){
	    node_map[edge(edges[i].second, edges[j].first)] = node_map[edges[i]] + node_map[edges[j]];
	  }else{
	    // node exists so we need to check the dist value and compare dists
	    int dist = node_map[edges[i]] + node_map[edges[j]];
	    if(dist < node_map[edge(edges[i].second, edges[j].first)]){
	      node_map[edge(edges[i].second, edges[j].first)] = dist;
	    }                    
	  }
	  //cout << "added edge, check 2, edge: " << edges[i].second << ", " << edges[j].first << endl;
	}
      }
      if(edges[i].second == edges[j].first){
	// edge1 connects node2 w / node1, edge2 connects node1 w / node3
	// then node2 and node3 connect.
	if(!(edges[i].first == edges[j].second)){
	  if(!node_map.count(edge(edges[i].first, edges[j].second))){
	    node_map[edge(edges[i].first, edges[j].second)] = node_map[edges[i]] + node_map[edges[j]];
	  }else{
	    // node exists so we need to check the dist value and compare dists
	    int dist = node_map[edges[i]] + node_map[edges[j]];
	    if(dist < node_map[edge(edges[i].first, edges[j].second)]){
	      node_map[edge(edges[i].first, edges[j].second)] = dist;
	    }                    
	  }
	  //cout << "added edge, check 3, edge: " << edges[i].first << ", " << edges[j].second << endl;
	}
      }
      if(edges[i].second == edges[j].second){
	// edge1 connects node2 w / node1, edge2 connects node3 w / node1
	// then node2 and node3 connect.
	if(!(edges[i].first == edges[j].first)){
	  if(!node_map.count(edge(edges[i].first, edges[j].first))){
	    node_map[edge(edges[i].first, edges[j].first)] = node_map[edges[i]] + node_map[edges[j]];
	  }else{
	    // node exists so we need to check the dist value and compare dists
	    int dist = node_map[edges[i]] + node_map[edges[j]];
	    if(dist < node_map[edge(edges[i].first, edges[j].first)]){
	      node_map[edge(edges[i].first, edges[j].first)] = dist;
	    }                    
	  }
	  //cout << "added edge, check 4, edge: " << edges[i].first << ", " << edges[j].first << endl;             
	}
      }            
            
    }
  }
  if(back_propagate){
    make_network(node_map, false);
  }
}
