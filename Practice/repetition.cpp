#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;

/**
 *  Tabulation is used to faster the time complexitcy 
 *  If there are at least 2 chars, accumulate the char count its same char next char
 *  Basically, the number of repetition is not stored at the first but it is stored at the last char
 *  When we count from left to right, we know the total count after seeing the last one.
 *  Therefore we can carry over the count up to the last char.
 * 
 * */
int solve(string s,  int len) {
    int best = -infinity;
    int cur = 0;
    if(len < 1) return -1;
    if(len < 2) return 1;
    vector<int> arr (len, 1);
    for(int i = 0; i < len-1; i++) {
        if(s[i] == s[i+1]) arr[i+1] += arr[i];
        best = max(best, arr[i+1]);
    }
    return best;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    string s;
    cin >> s;
    cout << solve(s, s.length());

}
/*
V1:Takes too long
string x;
int solve(char c, string q) {
    int i = 0;
    for(auto z : q){
        if (z == c) {
            i++;
        }
        else {
            break;
        }
    }
    return i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    cin >> x;
    int best = -infinity;
    for(int i = 0; i < x.size(); i++) {
        best = max(best, solve(x[i], x.substr(i,x.size())));
    }
    
    cout << best << endl;

}
*/
/*
V2: skip to next gene but if no repeating genes, it iterators too long still at worst case
    at best 1, at worst n^2
string x;
int solve(char c, string q) {
    int i = 0;
    for(auto z : q){
        if (z == c) {
            i++;
        }
        else {
            break;
        }
    }
    //cout << i << "" << q << endl;
    return i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    cin >> x;
    int best = -infinity;
    int next = 0;
    for(int i = 0; i < x.size(); i++) {
        if(next > 1) i += next-1;
        next = solve(x[i], x.substr(i,x.size()));
        best = max(best,next);
    }
    
    cout << best << endl;

}
*/