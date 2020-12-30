#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;

vector<int> a;

int solve(int x) {
  if ( x < 0) return infinity;
  if ( x == 0) return 0;
  int best = infinity;
  for (auto c : a) {
      best = min(best, solve(x-c)+1);
  }
  return best;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int n, x;
    int r;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        int z;
        cin >> z;
        a.push_back(z);
    }
    r = solve(x);
    cout << r << endl;
}
/*
  \
*/