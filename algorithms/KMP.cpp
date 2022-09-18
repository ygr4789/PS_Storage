// BOJ 1786

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> getPartialMatch(const string &N) {
	int m = N.size();
	vector<int> ret(m, 0);
	
	int matched = 0;
	for(int i=1; i<m; i++) {
		while(matched > 0 && N[i] != N[matched])
			matched = ret[matched-1];
		if(N[i] == N[matched]) ret[i] = ++matched;
	}
	
	return ret;
}

vector<int> kmpSearch(const string &H, const string &N) {
	int n = H.size();
	int m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	
	int matched = 0;
	for(int i=0; i<n; i++) {
		while(matched > 0 && H[i] != N[matched])
			matched = pi[matched-1];
		if(H[i] == N[matched]) {
			if(++matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched-1];
			}
		}
	}
	
	return ret;
}

int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> ans = kmpSearch(T, P);
	
	cout << ans.size() << '\n';
	for(const int &x : ans) {
		cout << (x + 1) << ' ';
	}
}