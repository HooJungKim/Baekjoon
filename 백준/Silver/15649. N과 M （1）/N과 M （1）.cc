#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isVisited[10];
void BackTracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (isVisited[i] == false) {
			arr[cnt] = i;
			isVisited[i] = true;
			BackTracking(cnt + 1);
			isVisited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;	
	BackTracking(0);
}