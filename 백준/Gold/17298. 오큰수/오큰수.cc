#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int ans[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> v;
	stack <int> s;
	
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = v.size() - 1; i >= 0; i--) {	
		while (!s.empty() && v[i] >= s.top())  {
			s.pop();
		}

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(v[i]);
	}	
	for (int i = 0; i < v.size(); i++) cout << ans[i] << " ";
}