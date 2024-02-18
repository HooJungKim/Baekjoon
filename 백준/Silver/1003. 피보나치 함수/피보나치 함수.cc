#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector <pair<int, int >> v(41);
	v[0] = make_pair(1, 0);
	v[1] = make_pair(0, 1);
	for (int i = 2; i <= 40; i++) {
		v[i] = make_pair(v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second);
	}
	while (n--) {
		int num;
		cin >> num;
		cout << v[num].first << ' ' << v[num].second << '\n';
	}
}