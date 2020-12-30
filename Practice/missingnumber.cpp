#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;

    ///M1: check 1 -> n-1 to see if it is in array; n-1 * O(searh function) search calls.
    ///
vector<int> a;
void solve(int x) {
    if (binary_search(a.begin(), a.end(), x)) solve(x-1);
    else cout << x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int n;
    cin >> n;
   // vector<int> a;
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    solve(n);

}
/*
  \
*/