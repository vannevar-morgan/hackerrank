#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


/*
 *  This uses a number property, n % 6 == 1 or 5 for all primes except 2 and 3.
 *  
 *  It calculates the primes up to radical(n), where n is the greatest number to determine primality.
 *  
 *  The primes are defined as the set of numbers >= 2, beginning with 2, 
 *  which are not divisible by any previous prime.
 *  
 *  Additionally when checking primes, we only need to check against 
 *  primes <= radical(n), where n is a candidate prime.
 *  
 *  I am aware Sieve of Erathones is more efficient.
 */
void check_primes(const vector<int>& nums);
//bool is_prime(int n);
bool is_prime(set<int> primes, int n);
void generate_primes(set<int>& primes, int max_val);
/*
bool is_prime(int n, set<int>& primes);
void get_primes(set<int>& primes, int n);
int next_prime(set<int>& primes, int n);
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;
    vector<int> nums;
    while(cin >> n){
        nums.push_back(n);
    }
    
    check_primes(nums);
    
    return 0;
}

void check_primes(const vector<int>& nums){
    //
    // Check whether the numbers in nums are prime.
    // Print "Prime" if the number is a prime.
    // Print "Not prime" if the number is not prime.
    //
    static set<int> primes = {2, 3};
    int max_val = pow((double) *max_element(nums.begin(), nums.end()), 0.5);
    //cout << "max_val: " << max_val << endl;
    generate_primes(primes, max_val);
    /*
    for(auto& i : primes){
        cout << i << endl;
    }
    */
    
    for(auto& i : nums){
        if(is_prime(primes, i)){
            cout << "Prime" << endl;
        }else{
            cout << "Not prime" << endl;
        }
    }
}

bool is_prime(set<int> primes, int n){
    if(n < 2){
        return false;
    }else if(n == 2){
        return true;
    }else if(n == 3){
        return true;
    }else{
        if(n % 6 != 1 && n % 6 != 5){
            return false;
        }        
        if(primes.count(n)){
            return true;
        }else{
            int check_val = pow((double)n, 0.5);
            for(auto& p : primes){
                if(n % p == 0){
                    return false;
                }
                if(p > check_val){
                    return true;
                }
            }
            return true;
        }
    }
}

/*
bool is_prime(int n){
    //
    // Check whether n is prime.
    //
    static set<int> primes = {2, 3};
    
    if(n < 2){
        return false;
    }else if(n == 2){
        return true;
    }else if(n == 3){
        return true;
    }else{
        if(n % 6 != 1 && n % 6 != 5){
            return false;
        }        
        if(primes.count(n)){
            return true;
        }else{
            // check against all primes
            //return is_prime(n, primes);
            return true;
        }
    }
}
*/

void generate_primes(set<int>& primes, int max_val){
    // insert all prime numbers into primes, that exist to max_val
    int num = 5;
    int check_val = 0;
    while(num <= max_val){
        check_val = pow((double)num, 0.5);
        if(num % 6 == 5){
            for(const auto& p : primes){
                if(num % p == 0){
                    break;
                }
                if(p > check_val){
                    primes.insert(num);
                    break;
                }          
            }
            num += 2;
        }else{
            for(const auto& p : primes){
                if(num % p == 0){
                    break;
                }
                if(p > check_val){
                    primes.insert(num);
                    break;
                }          
            }
            num += 4;
        }
    }
}

/*
bool is_prime(int n, set<int>& primes){
    // fetch the next 100 primes if radical(n) > greatest prime
    while(((int) pow(n, 0.5) + 1) > *(primes.end() - 1)){
        get_primes(primes, 100);
    }
    // check if n is prime
}


void get_primes(set<int>& primes, int n){
    // fill the set with the next n primes
    for(int i = 0; i < n; ++i){
        primes.insert(next_prime(primes, *(primes.end() - 1)));
    }
}


int next_prime(set<int>& primes, int n){
    if(n == 3){
        return 5;
    }
    if(n % 6 == 5){
        // check 2 away
        return is_prime(n, primes) ? n : next_primeis_prime();
    }else{
        // check 4 away
    }
}

*/
