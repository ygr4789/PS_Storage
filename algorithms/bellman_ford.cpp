// BOJ 11657

#include<iostream>
#include<vector>
#include<utility>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
const long long INF = 1e18;

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<vector<pil>> adj(N);
	vector<ll> dist(N, INF);
	// (index, weight)
	
	for(int i=0; i<M; i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		adj[u-1].push_back(make_pair(v-1, w));
	}
	
	bool minusCycle = false;
	dist[0] = 0;
	
	for(int i=0; i<N; i++)
	for(int u=0; u<N; u++)
	if(dist[u]!=INF)
	for(const auto &e : adj[u])
	{
		int v = e.first;
		ll w = e.second;
		if(dist[v] > dist[u] + w)
		{
			if(i==N-1) minusCycle = true;
			dist[v] = dist[u] + w;
		}
	}
	
	if(minusCycle) cout << -1;
	else for(int i=1; i<N; i++) cout << (dist[i]==INF ? -1:dist[i]) << '\n';
}