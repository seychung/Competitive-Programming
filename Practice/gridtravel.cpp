#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;


int solve(int m , int n, vector<vector<int>> &a) {
    if(m == 0 || n == 0) return 0;
    if(m == 1 && n == 1) return 1;
    if(a[m-1][n-1] > 0) return a[m-1][n-1];
    a[m-1][n-1] = solve(m-1,n, a) + solve(m,n-1, a);
    return a[m-1][n-1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int m = 18, n = 18;
    vector<vector<int>> a(m, vector<int> (n,0));
    cout << "ANSWER: " << solve(m, n, a);
}
/*
  \s
*/