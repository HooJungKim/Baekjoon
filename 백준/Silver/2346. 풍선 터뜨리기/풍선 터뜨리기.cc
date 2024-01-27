#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin >> n;
	deque<pair<int,int>> d;

	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;
		d.push_back({ i,order });
	}

	int cur_move = d.front().second;
	cout << d.front().first + 1 << " ";
	d.pop_front();

	while (!d.empty()) {
		if (cur_move < 0) {
			while (-cur_move != 0) {
				pair<int, int> p = d.back();
				d.push_front(p);
				d.pop_back();
				cur_move++;
			}
		}
		else {
			cur_move--;
			while (cur_move != 0) {
				pair<int, int> p = d.front();
				d.push_back(p);
				d.pop_front();
				cur_move--;
			}
		}
		cout << d.front().first + 1 << " ";
		cur_move = d.front().second;
		d.pop_front();
	}

}