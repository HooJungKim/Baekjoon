#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
vector<pair<int, int>> adj[10001];
bool check [10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	priority_queue< tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>> > pq;

	int cntE = 0;
	int answer = 0;

	check[1] = true;
	for (auto edge : adj[1]) {
		pq.push({ edge.first, 1, edge.second });
	}
	while (cntE < v - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (check[b]) continue;

		answer += cost;
		check[b] = true;
		cntE++;

		for (auto edge : adj[b])
			pq.push({ edge.first, b, edge.second });
	}
	cout << answer;
}