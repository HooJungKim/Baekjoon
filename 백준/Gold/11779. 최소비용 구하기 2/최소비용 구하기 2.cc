#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[1002];
int dist_table[1002];
int pre[1001];
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, st, en;
	cin >> n >> m;
	fill(dist_table, dist_table + n + 1, INF);

	while (m--) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
	}

	cin >> st >> en;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist_table[st] = 0;
	pq.push({dist_table[st], st});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dist_table[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second]) {
			if (nxt.first + dist_table[cur.second] >= dist_table[nxt.second])
				continue;
			dist_table[nxt.second] = nxt.first + dist_table[cur.second];
			pq.push({ dist_table[nxt.second] , nxt.second });
			pre[nxt.second] = cur.second;
		}
	}

	vector<int> ans;
	int cur = en;
	while (cur != st) {
		ans.push_back(cur);
		cur = pre[cur];
	}
	ans.push_back(cur);
	reverse(ans.begin(), ans.end());
	cout << dist_table[en] << '\n' << ans.size() << '\n';
	for (int x : ans) cout << x << ' ';
}