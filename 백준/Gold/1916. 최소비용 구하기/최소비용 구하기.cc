#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1001];
int dist[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	int st, end;
	cin >> st >> end;

	priority_queue< pair<int, int>,	vector<pair<int, int>>,	greater<pair<int, int>> > pq;

	fill(dist, dist + n + 1, INF);
	dist[st] = 0;

	pq.push({ 0, st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int u, v, w, cmp_w;
		u = cur.second;
		w = cur.first;

		if (dist[u] != w)
			continue;

		for (auto nxt : adj[u]){
			v = nxt.second;
			cmp_w = w + nxt.first;

			if (dist[v] <= cmp_w)
				continue;

			dist[v] = cmp_w;
			pq.push({ dist[v], v });
		}
	}
	cout << dist[end];
	return 0;
}