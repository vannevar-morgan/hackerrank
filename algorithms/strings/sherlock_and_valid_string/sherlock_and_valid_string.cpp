#include <iostream>
#include <map>
#include <string>
using namespace std;

string is_valid(const map<char, int> char_map);
map<int, int> get_value_counts(const map<char, int>& char_map);

int main() {
    string s;
    cin >> s;
    // count characters in s
    map<char, int> char_map;
    for(const auto& c : s){
        char_map[c]++;
    }
    // print the validity of the string
    cout << is_valid(char_map) << endl;
    
    return 0;
}


string is_valid(const map<char, int> char_map){
    //
    // Print "YES" if every character in char_map has the same multiplicity,
    // or can be made to have the same multiplicity by removing 1 character.
    //
    // Otherwise, print "NO"
    //
    map<int, int> values = get_value_counts(char_map);
    if(values.empty()){
        //cout << "values empty" << endl;
        return "NO";
    }else if(values.size() == 1){
        //cout << "size == 1" << endl;
        return "YES";
    }else if(values.size() > 2){
        //cout << "size > 2" << endl;
        return "NO";
    }else{
        // there are two values, "YES" if either is 1. "YES" if the absolute difference is 1.  "NO" otherwise.
        if(values.count(1) && values[1] == 1){
            //cout << "1 char count is 1" << endl;
            return "YES";
        }else if((*values.begin()).second == 1 || (*(++values.begin())).second == 1){
            //cout << "abs 1" << endl;
            return "YES";
        }else{
            //cout << "not valid" << endl;
            //cout << "char_count 1: " << (*values.begin()).first << "\tmultiplicity: " << (*values.begin()).second << endl;
            //cout << "char_count 2: " << (*(++values.begin())).first << "\tmultiplicity: " << (*(++values.begin())).second << endl;
            return "NO";
        }
    }
}

map<int, int> get_value_counts(const map<char, int>& char_map){
    //
    // Return a map<int, int> representing the counts of distinct values in char_map.
    //
    map<int, int> values;
    for(const auto& pair_i : char_map){
        values[pair_i.second]++;
    }
    return values;
}
