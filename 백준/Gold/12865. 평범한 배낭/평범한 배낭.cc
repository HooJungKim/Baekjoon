#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][1000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,max_weight;
	cin >> n >> max_weight;
	
	vector<pair<int, int>> weight_val(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> weight_val[i].first >> weight_val[i].second;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= max_weight; j++) {
			if (weight_val[i].first <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight_val[i].first] + weight_val[i].second);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][max_weight];
}