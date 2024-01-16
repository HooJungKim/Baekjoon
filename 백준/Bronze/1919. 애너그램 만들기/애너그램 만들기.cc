#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;

	int alp_a[26] = { 0 };
	int alp_b[26] = { 0 };
	int ans = 0;

	for (char c : a) {
		alp_a[c - 'a']++;
	}

	for (char c : b) {
		alp_b[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alp_a[i] != alp_b[i]) ans += abs(alp_a[i] - alp_b[i]);
	}

	cout << ans;
}