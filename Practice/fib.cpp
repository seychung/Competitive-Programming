#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;
int fib(int n, vector<int> &mem) {
    if(mem[n] > 0) {
        return mem[n];
    }
    if(n < 3) return 1;
    else {
        mem[n] = fib(n-1, mem) + fib(n-2, mem);
        return mem[n];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int x = 29;
    vector<int> mem (x, 0);
    cout << fib(x, mem);
    


}
/*
  vector<int> &mem for passing as address
  fib(x, mem) => mem can be variable or &varable, stil treating as address
*/