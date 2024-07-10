#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int state;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		int val;

		if (s == "add") {
			cin >> val;
			state |= (1 << (val-1));
		}
		else if (s == "remove") {
			cin >> val;
			state &= (~(1 << (val - 1)));
		}
		else if (s == "check") {
			cin >> val;
			cout << (state >> (val -1) & 1) << '\n';
		}
		else if (s == "toggle") {
			cin >> val;
			state ^= (1 << (val - 1));
		}
		else if (s == "all") {
			state = 0xfffff;
		}
		else {
			state = 0;
		}
	}

	return 0;
}