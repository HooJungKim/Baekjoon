#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		bool ans = true;
		int alp_a[26] = { 0 };
		int alp_b[26] = { 0 };

		for (char c : a) {
			alp_a[c - 'a']++;
		}
		for (char c : b) {
			alp_b[c - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (alp_a[i] != alp_b[i]) {
				cout << "Impossible\n";
				ans = false;
				break;
			}
		}
		if (ans == true) cout << "Possible\n";
	}
}