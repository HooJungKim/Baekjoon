#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int path[101][101];
const int INF = 0x3f3f3f3f;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(arr[i], arr[i] + n + 1, INF);
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c) {
			arr[a][b] = c;
			path[a][b] = b;
		}			
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
					path[j][k] = path[j][i];
				}					
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF)
				cout << "0 ";
			else
				cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (path[i][j] == 0) {
				cout << "0\n";
				continue;
			}
			vector <int> v;
			int st = i;
			while (st != j) {
				v.push_back(st);
				st = path[st][j];
			}
			v.push_back(j);
			cout << v.size() << " ";
			for (int num : v) cout << num << ' ';
			cout << "\n";
		}
	}
}