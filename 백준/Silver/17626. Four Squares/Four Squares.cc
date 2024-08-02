#include<iostream>
#include<algorithm>
using namespace std;

int dp[50001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fill(dp, dp + n + 1, 5);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			int num = i - (j * j);
			dp[i] = min(dp[i], dp[num] + 1);
		}
	}

	cout << dp[n];
	return 0;
}