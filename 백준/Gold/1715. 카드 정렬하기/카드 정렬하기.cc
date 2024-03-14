#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}
	int sum = 0;
	while (pq.size()>1) {
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum += (a + b);
		pq.push(a + b);		
	}
	cout << sum;	
}