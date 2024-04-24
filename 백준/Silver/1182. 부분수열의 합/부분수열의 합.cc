#include <iostream>
using namespace std;
int n, s, cnt;
int arr[21];
void BackTracking(int x, int sum) {
	if (x == n) {
		if (sum == s)
			cnt++;
		return;
	}
	BackTracking(x + 1, sum);
	BackTracking(x + 1, sum + arr[x]);	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	BackTracking(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt;
}