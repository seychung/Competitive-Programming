#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

const int infinity = std::numeric_limits<int>::max();

typedef long long ll;

using namespace std;



void solve(ll max, vector<pair<ll,ll>> xy, vector<vector<ll>> mem) {
    //generate spiral
    int layer = 1; //gird layer
    ll cy = 0, cx = 0; //coordinates
    for(int i = 1; i <= max*max; i++) {
        //cout << "cy:" << cy << "\tcx: " << cx << "\tlayer:" << layer << "\t";
        //cout << "layer:" << layer << endl;
        mem[cx][cy] = i; 
        if(layer % 2 != 0) { //even upper
            //cout << "even" << endl;
            if(cy < layer-1) {
                cy++;
            }
            else if(cx > 0) {
                cx--;
            }
        }
        else{ //odd lower
            //cout << "odd" << endl;
            if(cx < layer-1) {
                cx++;
            }
            else if(cy > 0) {
                cy--;
            }  
        }
        if(i == layer*layer){ //layer update
            //cout << "layer up" << endl;
            layer++;
            if(layer % 2 != 0) { //initial coordinate setting based on layer update
                cy = 0;
                cx = layer-1;
            }
            else{
                cy = layer-1;
                cx = 0;
            }
        }

    }  
    ll x, y;
    for(int i = 0; i < xy.size(); i++) { //get answers
        y = xy[i].first - 1;
        x = xy[i].second - 1;
        cout << mem[y][x] << endl;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //optimize code
    int n;
    ll x, y;
    ll best = -infinity;
    ll cur;

    vector<pair<ll,ll>> xy;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> y >> x;
        cur = max(y,x);
        best = max(best, cur);
        xy.push_back(make_pair(y,x));
    }
    //cout << best << endl;
    vector<vector<ll>> mem (best, vector<ll> (best, 0));
    solve(best, xy, mem);
}
/*
  \
*/