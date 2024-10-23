#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

vector<int> elements;
int set[8];
bool visit[8];

void func(int num, int x) {

	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << set[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = x; i < elements.size(); i++) {

		set[num] = elements[i];
		func(num + 1, i);
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		elements.push_back(x);
	}

	sort(elements.begin(), elements.end());
	elements.erase(unique(elements.begin(), elements.end()), elements.end());
	func(0, 0);
	
	return 0;
}