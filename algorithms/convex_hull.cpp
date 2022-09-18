#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
typedef long long lint;
typedef pair<lint, lint> plint;

int CCW(const plint &p1, const plint &p2, const plint &p3) {
    lint sine = (p2.first - p1.first) * (p3.second - p2.second) - (p3.first - p2.first) * (p2.second - p1.second);
    if(sine == 0) return 0;
    else return (sine > 0 ? 1 : -1);
}

lint dist(const plint &p1, const plint &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

vector<plint> convex_hull(vector<plint> v) {
    sort(v.begin(), v.end());
    plint p0 = v[0];

    sort(v.begin() + 1, v.end(), [p0](plint p1, plint p2) -> bool {
        int ccw = CCW(p0, p1, p2);
        if(ccw == 1) return true;
        else if(ccw == -1) return false;
        else return dist(p0, p1) < dist(p0, p2);
    });
    v.push_back(p0);
	
    vector<plint> ret;
    ret.push_back(p0);
    for(int i=1; i<v.size(); i++) {
        while(ret.size() > 1) {
            int n = ret.size();
            if(CCW(ret[n-2], ret[n-1], v[i]) != 1) ret.pop_back();
            else break;
        }
        ret.push_back(v[i]);
    }
    ret.pop_back();
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<plint> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    cout << convex_hull(v).size();
}

int main() {
    solve();
}