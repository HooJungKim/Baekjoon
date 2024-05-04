#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long arr[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	arr[1] = arr[2] = arr[3] = 1;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 3];
		}
		cout << arr[n] << '\n';
	}
}