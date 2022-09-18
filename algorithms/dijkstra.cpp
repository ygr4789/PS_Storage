#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> edge;
//(weight, index)
int n;

vector<int> dijkstra(int source)
{
	priority_queue<pii, vector<pii>, greater<>> pq;
	//(dist, index)
	vector<int> dist(n, -1);
	
	pq.push(make_pair(0, source));
	
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		if(dist[u]==-1) dist[u] = d;
		else continue;
		
		for(const auto &e : edge[u])
		{
			int v = e.second;
			int w = e.first;
			
			if(dist[v]==-1) pq.push(make_pair(d+w, v));
		}
	}
	
	return dist;
}

int main()
{
	int N, M, source;
	
	cin >> N >> M;
	cin >> source;
	n = N+1;
	edge = vector<vector<pii>>(n, vector<pii>());
	
	for(int i=0; i<M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		edge[u].push_back(make_pair(w, v));
		//edge[v].push_back(make_pair(w, u));
	}
	
	vector<int> d = dijkstra(source);
	for(int i=1; i<n; i++)
	if(d[i]==-1) cout << "INF" << '\n';
	else cout << d[i] << '\n';
}