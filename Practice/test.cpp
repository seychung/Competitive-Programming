#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <numeric>


typedef long long ll;
const unsigned int uinfinity = std::numeric_limits<unsigned int>::max();
const int infinity = std::numeric_limits<int>::max();
using namespace std;

int solve(vector<int>r) {
    int sum = 0;
    for(auto x : r) sum+=x;
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int i = 12;
    int x = 5;
    cout << i % x;




}