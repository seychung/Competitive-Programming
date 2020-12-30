#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;
vector<int> a;
int n;
vector<bool> b(n+1); // we dont use b[0]
int c = 0;
int solve() {
    bool check = true;
    if(a.size() == n) {
        for(int i = 0; i < n-1; i++) {
            if(abs(a[i] - a[i+1]) == 1){
                check = false;
                break;
            }
        }
        if(check) {
            c++;
            return 1;
        }
    }
    else{
        for(int i = 1; i <= n; i++) { // i = 1 to use 1 as a number element value (synching)
            if (b[i]) continue;
            b[i] = true;
            a.push_back(i);
            solve();
            b[i] = false;
            a.pop_back();
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    cin >> n;
    solve();
    cout << c;
}