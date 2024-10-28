#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1002];


int Dijkstra(int st, int end) {

	int dist[1001];
	fill(dist, dist + N + 1, INF);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ 0, st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] < cur.first)
			continue;

		for (auto nxt : adj[cur.second]) {
			 
			if (dist[nxt.second] > cur.first + nxt.first) {
				dist[nxt.second] = cur.first + nxt.first;
				pq.push({ dist[nxt.second], nxt.second });
			}
		}
	}

	return dist[end];
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;

	int s, e, t;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> t;
		adj[s].push_back({ t, e });
	}

	int answer = 0;

	for (int i = 1; i <= N; i++) {		
		answer = max(answer, Dijkstra(i, X) +  Dijkstra(X, i));
	}

	cout << answer;
}