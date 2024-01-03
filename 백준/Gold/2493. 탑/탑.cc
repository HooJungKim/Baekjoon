#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> s;
	s.push({ 100000001,0 });

	for (int i = 1; i <= n; i++) {
		pair <int, int> p;
		cin >> p.first;
		p.second = i;
		while (s.top().first < p.first) {
			s.pop();
		}
		cout << s.top().second << " ";
		s.push(p);
	}
	
}