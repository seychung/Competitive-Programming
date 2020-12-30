#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <set>
const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;

int sum(int n) {
    if(n == 1) return 1;
    return n + sum(n-1);

}

void solve(int n) {

    if(n % 2 == 0) {
        set<int> s;
        set<int> r;
        for(int i = 1, j = n; i <= n/2; i++, j--) {
            if(i % 2 != 0) {
                s.insert(i);
                s.insert(j);
            }
            else{
                r.insert(i);
                r.insert(j);
            }

        }
        cout << s.size() << endl;
        for(auto x: s) cout << x << " ";
        cout << "\n";
        cout << r.size() << endl;
        for(auto x: r) cout << x << " ";
        cout << "\n"; 
    }
    else{
        set<int> s;
        set<int> r;
        for(int i = 1, j = n-1; i <= (n-1)/2; i++, j--) {
            if(i % 2 != 0) {
                s.insert(i);
                s.insert(j);
            }
            else{
                r.insert(i);
                r.insert(j);
            }

        }
        r.insert(n);
        cout << s.size() << endl;
        for(auto x: s) cout << x << " ";
        cout << "\n";
        cout << r.size() << endl;
        for(auto x: r) cout << x << " ";
        cout << "\n"; 
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int n;
    cin >> n;
    if(sum(n) % 2 != 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        solve(n);
    }
  
}

//https://math.stackexchange.com/questions/3266470/divide-the-numbers-1-2-n-into-two-sets-of-equal-sum/3266612
