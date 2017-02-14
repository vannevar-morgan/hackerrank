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
#include <cassert>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    //
    // Perform k number of left_rotations on the vector<int> a.
    //
    assert(n > 0);
    assert(k > 0);
    unsigned int left_rots = k % n;
    //cout << "k: " << k << "\tn: " << n << "\tleft_rots: " << left_rots << endl;
    vector<int> temp_vec(n);
    copy(a.begin() + left_rots, a.end(), temp_vec.begin());
    copy(a.begin(), a.begin() + left_rots, temp_vec.begin() + n - left_rots);
    return temp_vec;    
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
