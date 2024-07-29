#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[5000001];
int b[5000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n_a, n_b;

	cin >> n_a >> n_b;

	for (int i = 0; i < n_a; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n_b; i++) {
		cin >> b[i];
	}

	vector<int> ans;
	
	sort(a, a + n_a);
	sort(b, b + n_b);

	for (int i = 0; i < n_a; i++) {
		if (binary_search(b, b + n_b, a[i])) {
			continue;
		}
		else {
			ans.push_back(a[i]);
		}
	}

	if (ans.size() == 0)
		cout << 0;
	else {
		cout << ans.size() << '\n';
		for (int num : ans)
			cout << num << " ";
	}

	return 0;
}