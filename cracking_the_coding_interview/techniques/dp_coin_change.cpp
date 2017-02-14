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
#include <utility>

using namespace std;

/*
long long make_change(vector<int> coins, int money) {
    def count( n, m ):
    if n < 0 or m <= 0: #m < 0 for zero indexed programming languages
        return 0
    if n == 0: # needs be checked after n & m, as if n = 0 and m < 0 then it would return 1, which should not be the case.
        return 1
 
    return count( n, m - 1 ) + count( n - S[m], m )    
}
*/

long long make_change(vector<int> coins, int money, map<pair<vector<int>, int>, long long>& memo_table) {
    long long count = 0;
    if(memo_table.count(pair<vector<int>, int>(coins, money)) == 1){
        return memo_table[pair<vector<int>, int>(coins, money)];
    }
    if(money < 0 || coins.size() < 0){
        memo_table[pair<vector<int>, int>(coins, money)] = 0;
        return 0;
    }
    if(money == 0){
        memo_table[pair<vector<int>, int>(coins, money)] = 1;
        return 1;
    }
    vector<int> temp(coins.begin(), coins.end());
    if(coins.size() > 0){
        temp.pop_back();
        count += make_change(temp, money, memo_table);
        count += make_change(coins, money - coins.back(), memo_table);
    }
    memo_table[pair<vector<int>, int>(coins, money)] = count;
    return count;
}


long long make_change(vector<int> coins, int money) {
    map<pair<vector<int>, int>, long long> memo_table;
    return make_change(coins, money, memo_table);
}


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
