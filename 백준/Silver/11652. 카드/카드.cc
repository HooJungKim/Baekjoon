#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long max_num = 0;
	int cnt = 0;
	int max_cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		if (i == 0 || v[i] == v[i - 1]) cnt++;
		else{
			if (cnt > max_cnt) {
				max_num = v[i - 1];
				max_cnt = cnt;				
			}
			cnt = 1;
		}
	}
	if (cnt > max_cnt) {
		max_num = v[v.size() - 1];
		max_cnt = cnt;
	}
	cout << max_num;
}