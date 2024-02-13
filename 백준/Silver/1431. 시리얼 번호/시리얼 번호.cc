#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		int num_a = 0, num_b = 0;
		for (char c : a) {
			if (c >= '0' && c <= '9')num_a += c - '0';
		}
		for (char c : b) {
			if (c >= '0' && c <= '9')num_b += c - '0';
		}
		if (num_a == num_b) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] != b[i]) return a[i] < b[i];
			}
		}
		return num_a < num_b;
	}
	return a.size() < b.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for (string s : v) cout << s << '\n';
}