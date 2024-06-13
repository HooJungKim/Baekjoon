#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int wood[1000001];

bool PS(int num) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (wood[i] > num)
			sum += (wood[i] - num);
	}
	return sum >= m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> wood[i];
	}

	int st = 0;
	int end = 1000000000;
	

	while (st < end) {
		int mid = (st + end + 1) / 2;
		if (PS(mid)) {
			st = mid;
		}
		else {
			end = mid - 1;
		}
	}

	cout << st;	
	return 0;
}