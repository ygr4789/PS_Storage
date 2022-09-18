// BOJ 11404

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	for(int i=0; i<n; i++) dist[i][i] = 0;
	
	for(int i=0; i<m; i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		dist[u-1][v-1] = min(dist[u-1][v-1], w);
	}
	
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		}
	}
	
	for(const auto &v : dist)
	{
		for(const auto &d : v) cout << (d==INF ? 0:d) << " ";
		cout << '\n';
	}
}