#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class disjoint_set {
	int n;
	vector<int> parent, height;		
	public:
	disjoint_set(int _n): n(_n) {
		parent = vector<int>(n);
		height = vector<int>(n, 1);
		for(int i=0; i<n; i++) parent[i] = i;
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if(height[u] > height[v]) swap(u, v);
		parent[u] = v;
		if(height[u] == height[v]) height[v]++;
	}
	int find(int v) {
		if(parent[v] == v) return v;
		else return parent[v] = find(parent[v]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	disjoint_set ds = disjoint_set(n+1);
	for(int i=0; i<m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if(op) cout << ( ds.find(a) == ds.find(b) ? "YES" : "NO" ) << '\n';
		else ds.merge(a, b);
	}
}