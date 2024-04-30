#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[20001];
int dist[20001];
const int INF = 0x3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int V, E, K;
	cin >> V >> E >> K;
	fill(dist, dist + V + 1, INF);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[K] = 0;
	pq.push({ dist[K], K });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.first != dist[cur.second])
			continue;
		for (auto nxt : adj[cur.second]) {
			if (dist[cur.second] + nxt.first >= dist[nxt.second])
				continue;
			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}