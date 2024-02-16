#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector <int> R(n+1);
	vector <int> G(n+1);
	vector <int> B(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> R[i];
		cin >> G[i];
		cin >> B[i];
	}
	int arr[1001][3];
	arr[1][0] = R[1];
	arr[1][1] = G[1];
	arr[1][2] = B[1];
	for (int i = 2; i <= n; i++) {
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + R[i];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + G[i];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + B[i];
	}
	cout << *min_element(arr[n], arr[n] + 3);
}