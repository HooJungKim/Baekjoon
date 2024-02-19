#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	int answer = v[0];
	for (int i = 1; i < v.size(); i++) {
		answer = max(answer, v[i] * (i + 1));
	}	
	cout << answer;
}