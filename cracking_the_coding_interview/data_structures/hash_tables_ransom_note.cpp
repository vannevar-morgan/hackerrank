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

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    //
    // Return true if all strings in ransom are present (with >= the same multiplicity) in magazine.
    //
    if(ransom.size() > magazine.size()){
        return false;
    }
    // sort magazine before processing (map lookups will be more efficient)
    sort(magazine.begin(), magazine.end());
    // count instances of words in magazine
    map<string, int> word_map;
    for(const string& s : magazine){
        word_map[s]++;
    }
    // check if the words in ransom exist in >= the same multiplicity in magazine
    for(const string& s : ransom){
        if(word_map[s]-- == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
