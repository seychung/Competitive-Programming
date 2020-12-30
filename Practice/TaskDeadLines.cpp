#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code

    ll t, d, f, time = 0; //time and rw has to be 'll' because rw is the answer and time is the cumulating inputs which can exceed 16 bit int
    ll rw = 0;
    cin >> t;
    vector<pair<ll,ll>> a; // is pair vector the best choice?
    for(int i = 1; i <= t; ++i) {
        cin >> d >> f;
        a.push_back(make_pair(d,f));
    }
    sort(a.begin(), a.end()); //best way to sort pair vector???
    for(int i = 0; i < a.size(); i++) {
        time += a[i].first;
        rw += a[i].second - time;
    }
    cout << rw << endl;

}
/*
    task deadline with duration, deadline for max reward does not need deadline optimization; just duration sort.
*/