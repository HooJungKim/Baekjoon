#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n;
int arr[10005];
bool func(long long x) {
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i] / x;
	}
	return sum >= n;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	long long st = 1;
	long long end = 0x7fffffff;
	while (st < end) {
		long long mid = (st + end + 1) / 2;
		if (func(mid))
			st = mid;
		else
			end = mid - 1;
	}
	cout << st;
}
