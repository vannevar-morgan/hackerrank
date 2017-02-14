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

bool is_balanced(string expression) {
    //
    // Return true if expression represents a balanced set of brackets, false otherwise.
    //
    
    // First check trivial cases where the bracket expression is obviously unbalanced.
    if(expression.size() == 0){
        return true;
    }
    if(expression.size() % 2 != 0){
        return false;
    }
    map<char, char> char_map; // map of closing brackets to opening brackets
    char_map['}'] = '{';
    char_map[']'] = '[';
    char_map[')'] = '(';
    if(expression[0] == '}' ||
       expression[0] == ']' ||
       expression[0] == ')'){
        return false;
    }
    // At this point we know the first character must be an opening bracket.
    stack<char> brack_stack;
    for(const char& c : expression){
        if(c == '{' || c =='[' || c == '('){
            brack_stack.push(c);
        }else{
            if(brack_stack.empty()){
                return false;
            }
            if(brack_stack.top() != char_map[c]){
                return false;
            }else{
                brack_stack.pop();
            }
        }
    }
    if(!brack_stack.empty()){
       return false; 
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
