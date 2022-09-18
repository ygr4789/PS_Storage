// BOJ 2252

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> order;

void dfs(int here) {
	visit[here] = true;
	for(const int &there : adj[here])
		if(!visit[there]) dfs(there);
	order.push_back(here);
}

vector<int> topologicalSort() {
	int N = adj.size();
	visit.resize(N, false);
	for(int i=0; i<N; i++)
		if(!visit[i]) dfs(i);
	reverse(order.begin(), order.end());
	return order;
}

int main() {
	int N;
	cin >> N;
	adj.resize(N);
	
	int M;
	cin >> M;
	for(int i=0; i<M; i++) {
		int A, B;
		cin >> A >> B;
		adj[--A].push_back(--B);
	}
	
	for(const int &x : topologicalSort())
		cout << (x + 1) << ' ';
}