// BOJ 2522

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> inDegree;

vector<int> topologicalSort() {
	int N = adj.size();
	visit = vector<bool>(N, false);
	vector<int> ret;
	
	queue<int> q;
	for(int i=0; i<N; i++)
		if(inDegree[i] == 0) q.push(i);
		
	while(!q.empty()) {
		int here = q.front();
		q.pop();
		ret.push_back(here);
		
		for(const int &there : adj[here])
			if(--inDegree[there] == 0) q.push(there);
	}
	
	return ret;
}

int main() {
	int N;
	cin >> N;
	adj.resize(N);
	inDegree.resize(N, 0);
	
	int M;
	cin >> M;
	for(int i=0; i<M; i++) {
		int A, B;
		cin >> A >> B;
		adj[--A].push_back(--B);
		inDegree[B]++;
	}
	
	for(const int &x : topologicalSort())
		cout << (x + 1) << ' ';
}