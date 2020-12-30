#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code

    ll n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) n = n/2;
        else n = n*3+1;
        
 
    }
    cout << 1;

}
/*
  \
*/