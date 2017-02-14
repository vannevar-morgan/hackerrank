#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
  //
  // Return the total number of deletions needed to make string a and b identical.
  //
    map<char, int> a_map;
    map<char, int> b_map;
    
    for(const char c : a){
        a_map[c]++;
    }
    for(const char c : b){
        b_map[c]++;
    }
    static const string lookup("abcdefghijklmnopqrstuvwxyz");
    
    int sum = 0;
    for(const char c : lookup){
        sum += abs(a_map[c] - b_map[c]);
    }
    return sum;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
