#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	int arr[301][3];

	arr[1][1] = v[1];
	arr[1][2] = 0;
	arr[2][1] = v[2];
	arr[2][2] = v[1] + v[2];

	for (int i = 3; i <= n; i++) {
		arr[i][1] = max(arr[i - 2][1], arr[i - 2][2]) + v[i];
		arr[i][2] = arr[i - 1][1] + v[i];
	}
	cout << max(arr[n][1], arr[n][2]);
}