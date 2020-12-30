#include<iostream>
#include<vector>
#include<set>

using namespace std;

int validcheck(string s, int x, int y) {
	for (int i = 0; i < s.length(); i++) { //calculating all step taken; i-th char at direction tells +/- x/y
		if (s[i] == 'S') {
			y += 1 << i;
		}
		if (s[i] == 'N') {
			y -= 1 << i;
		}
		if (s[i] == 'W') {
			x += 1 << i;
		}
		if (s[i] == 'E') {
			x -= 1 << i;
		}
	}
	if (x == 0 && y == 0) return 2; //are we at target
    //s.length tells how many steps taken so far
    //all taken bits indicated by s.length must be 0 
	if (x % (1 << s.length()) != 0)return 0; //are we unable on x direction like 2(10) 
	if (y % (1 << s.length()) != 0)return 0; //are we unable on y direction 
	return 1;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int x, y;
		cin >> x >> y;

		set<string> steps[40];

		steps[0].insert("");
		string ans="";
		vector<string> letters = { "N","E","W","S" };
		int found = 0;
		for (int i = 0; i < 39; i++) {

			for (auto j : steps[i]) {
				for (auto l : letters) {
					int v = validcheck(j + l, x, y);
					if (v == 2) { //found
						found = 1;
						ans = j + l;
						break;
					}
					if (v == 1) { //valid, next step
						steps[i + 1].insert(j + l);

					}
				}
			}
			if (found) break;
		}
		if (!found) ans = "IMPOSSIBLE";
		cout << "Case #" << tc << ": " << ans<<endl;

	}
}

/**
 *  Attemp1: abs(x) + abs(y) is steps needed to be taken, 0 step in between can not happen. Therefore searching '0' bit
 *      -Fail: (2,3) -1 step makes (2,4) to make 2, 4 jumps
 *  
 * typedef long long ll;
const ll infinity = std::numeric_limits<ll>::max();
bool found = false;
using namespace std;

//+x East, -x West; +y North; -y South of (x,y)
int trip(ll stepNum, vector<char> map, pair<ll,ll> curLoc, const pair<ll,ll> targetLoc) {
    ll move = infinity & (1 << stepNum);
    stepNum++;
    
    if(curLoc == targetLoc && found == false) {
        found = true;
        for(auto s: map) cout << s;
        cout << "\n";
        return 1;
    }
    else if(stepNum < 5){
        
        ll x = curLoc.first;
        ll y = curLoc.second;
        //easting +x
        cout << "moving " << move << " from " << curLoc.first << "," << curLoc.second << "\t";
        cout << "East" << "\n";
        map.push_back('E');
        pair<ll,ll> E = make_pair(x + move, y);
        trip(stepNum, map, E, targetLoc);
        //westing -x
        cout << "moving " << move << " from: " << curLoc.first << "," << curLoc.second << "\t";
        cout << "West" << "\n";
        map.push_back('W');
        pair<ll,ll> W = make_pair(x - move, y);
        trip(stepNum, map, W, targetLoc);
        //northing +y
        cout << "moving " << move << " from: " << curLoc.first << "," << curLoc.second << "\t";
        cout << "North" << "\n";
        map.push_back('N');
        pair<ll,ll> N = make_pair(x, y + move);
        trip(stepNum, map, N, targetLoc);
        //southing -y
        cout << "moving " << move << " from: " << curLoc.first << "," << curLoc.second << "\t";
        cout << "South" << "\n";
        map.push_back('S');
        pair<ll,ll> S = make_pair(x, y - move);
        trip(stepNum, map, S, targetLoc);
    }
    else{
        return -1; //impossible
    }

}
void solve() {
    ll x, y;
    cin >> x >> y;
    //steping
    ll stepNum = 0;
    vector<char> map;
    if(trip(stepNum, map, make_pair(0,0), make_pair(x,y)) == -1) {
        cout << "IMPOSSIBLE";        
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":\n";
        solve();
    }
  
}

 * */