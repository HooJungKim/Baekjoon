#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<int> u;

	cin >> n;
	int num;
	for(int i = 0; i < n; i++) {
		cin >> num;
		u.push_back(num);
	}
	sort(u.begin(), u.end());
	vector<int> sec;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sec.push_back(u[i] + u[j]);
		}
	}
	sort(sec.begin(), sec.end());
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(sec.begin(), sec.end(), u[i] - u[j])) {
				cout << u[i];
				return 0;
			}
		}
	}
}
