// BOJ 2042

#include<iostream>
#include<vector>

using namespace std;
typedef long long lint;

class fenwick_tree {
	vector<lint> tree;
	
	lint query(int i) {
		lint ret = 0;
		while(i != 0) {
			ret += tree[i];
			i &= (i-1);
		}
		return ret;
	}
	
	public:
	fenwick_tree(const vector<lint> &v) {
		int N = v.size();
		tree.resize(N, 0);
		vector<lint> prefix = v;
		for(int i=1; i<N; i++)
			prefix[i] += prefix[i-1];
		for(int i=1; i<N; i++)
			tree[i] = prefix[i] - prefix[i & (i-1)];
	}
	lint query(int left, int right) {
		return query(right) - query(left - 1);
	}
	void modify(int i, lint newValue) {
		lint diff = newValue - query(i, i);
		while(i < tree.size()) {
			tree[i] += diff;
			i += (i & -i);
		}
	}
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<lint> arr(N+1, 0);
	for(int i=1; i<=N; i++) cin >> arr[i];
	fenwick_tree ft(arr);
	
	for(int i=0; i<M+K; i++) {
		int a;
		lint b, c;
		cin >> a >> b >> c;
		
		if(a == 1) ft.modify(b, c);
		if(a == 2) cout << ft.query(b, c) << '\n';
	}
}