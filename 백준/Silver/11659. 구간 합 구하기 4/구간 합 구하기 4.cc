#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> v(n+1);
	vector<int> sum(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	sum[0] = 0;
	sum[1] = v[1];
	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] <<'\n';
	}

}