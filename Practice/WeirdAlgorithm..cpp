#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;
vector<int> a;

int solve(int n) {
    a.push_back(n);
    if(n & 2 == 0) solve(n/2);
    if(n & 2 != 0) solve(n*3+1);
    if(n == 1) return 1;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        solve(n);
    }
    for(auto x : a) cout << x << " ";
}
/*
  \
*/