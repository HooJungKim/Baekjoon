#include <iostream>
using namespace std;
int n, cnt;
bool isused1[40];
bool isused2[40];
bool isused3[40];
void BackTracking(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused1[i] && !isused2[i + cur] && !isused3[i - cur + n - 1]) {
			isused1[i] = true;
			isused2[i+cur] = true;
			isused3[i - cur + n - 1] = true;
			BackTracking(cur + 1);
			isused1[i] = false;
			isused2[i + cur] = false;
			isused3[i - cur + n - 1] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	BackTracking(0);
	cout << cnt;
}