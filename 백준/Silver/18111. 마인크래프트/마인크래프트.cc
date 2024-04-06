#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501][501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, b;
	int sum = 0, max_height = 0;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
			if (arr[i][j] > max_height)
				max_height = arr[i][j];
		}
	}
	vector <int>v(max_height+1);
	int possible_height = max_height;
	for (int k = 0; k <= max_height; k++) {
		int second = 0;
		if (k * n * m > sum + b) {
			possible_height = k - 1;
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > k)
					second += (arr[i][j] - k) * 2;
				else if (arr[i][j] < k)
					second += (k - arr[i][j]);
			}
		}
		v[k] = second;
 	}
	int min_sec = *min_element(v.begin(), v.begin()+possible_height+1);
	for (int i = possible_height; i >= 0; i--) {
		if (v[i] == min_sec) {
			cout << v[i] <<" " << i;
			return 0;
		}
	}
}
