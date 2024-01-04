#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, ans = 0;

	cin >> N >> M;
	deque <int> d;
	for (int i = 0; i < N; i++) {
		d.push_back(i + 1);
	}

	while (M--) {
		int x;
		cin >> x;
		int index = find(d.begin(), d.end(), x) - d.begin();

		if (index < d.size() - index) {
			while (d.front() != x) {
				int a = d.front();
				d.pop_front();
				d.push_back(a);
				ans++;
			}
		}
		else {
			while (d.front() != x) {
				int a = d.back();
				d.pop_back();
				d.push_front(a);
				ans++;
			}
		}
		d.pop_front();
	}
	cout << ans;
}