#include <iostream>
#include <algorithm>
using namespace std;
int CountPeople(int floor, int num) {
	if (floor == 0) return num;
	else if (num == 1) return 1;
	else return CountPeople(floor, num - 1) + CountPeople(floor - 1, num);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T, k, n;

	cin >> T;

	while (T--) {
		cin >> k >> n;
		cout << CountPeople(k, n) << '\n';
	}

}