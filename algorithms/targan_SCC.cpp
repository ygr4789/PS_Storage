// BOJ 2150

#include<iostream>
#include<vector>

using namespace std;
typedef long long lint;

class seg_tree {
	vector<lint> tree;
	int size;
	
	lint init(int left, int right, const vector<lint> &v, int i) {
		if(left == right) return tree[i] = v[left];
		int mid = (left + right) / 2;
		return tree[i] = init(left, mid, v, i*2+1) + init(mid+1, right, v, i*2+2);
	}
	lint modify(int left, int right, int target, lint n, int i) {
		if(target > right || target < left) return 0;
		
		lint ret;
		int mid = (left + right) / 2;
		
		if(left == right) ret = n - tree[i];
		else ret = modify(left, mid, target, n, i*2+1) + modify(mid+1, right, target, n, i*2+2);
		tree[i] += ret;
		return ret;
	}
	lint query(int left, int right, int L, int R, int i) {
		if(L > right || R < left) return 0;
		if(L <= left && R >= right) return tree[i];
		int mid = (left + right) / 2;
		return query(left, mid, L, R, i*2+1) + query(mid+1, right, L, R, i*2+2);
	}
	
	public:
	seg_tree(const vector<lint> &v) : size(v.size()) {
		tree.resize(size*4);
		init(0, size-1, v, 0);
	}
	void modify(int target, lint n) {
		modify(0, size-1, target, n, 0);
	}
	lint query(int L, int R) {
		return query(0, size-1, L, R, 0);
	}
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<lint> arr(N);
	for(int i=0; i<N; i++) cin >> arr[i];
	seg_tree st(arr);
	
	for(int i=0; i<M+K; i++) {
		int a;
		lint b, c;
		cin >> a >> b >> c;
		
		if(a == 1) st.modify(b-1, c);
		if(a == 2) cout << st.query(b-1, c-1) << '\n';
	}
}