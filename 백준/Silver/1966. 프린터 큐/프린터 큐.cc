#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	while (n--)
	{
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			q.push({ i, num });
			pq.push(num);
		}
		int order = 1;
		while (!q.empty()) {
			if (pq.top() == q.front().second) {
				if (q.front().first == M) {
					cout << order<<'\n';
					break;
				}
				pq.pop();
				q.pop();
				order++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
}
