#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	for(int i = 0; i < N; i++) 
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	int min_n = 0x7fffffff;
	int end = 0;

	for (int st = 0; st < N; st++) {
		while (end < N && v[end] - v[st] < M)
			end++;
		if (end == N) break;
		min_n = min(min_n, v[end] - v[st]);
	}

	cout << min_n;
	return 0;
}