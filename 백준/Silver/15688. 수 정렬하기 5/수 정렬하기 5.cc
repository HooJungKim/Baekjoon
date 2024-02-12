#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x;
	cin >>x;
	
	vector <int> v(x);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << '\n';
	}	
}