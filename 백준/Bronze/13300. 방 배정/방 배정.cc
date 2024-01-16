#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[12] = { 0 };
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int s, g;
		cin >> s >> g;
		
		if (s == 1) arr[g - 1]++;
		else arr[g + 5]++;
	}
	for (int i = 0; i < 12; i++) {
		ans += arr[i] / k + (arr[i] % k ? 1 : 0);
	}
	cout << ans;
}