#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == 'I') {			
			if (((2 * N) + i) >= M) {		
				break;
			}				

			for (int j = 0; j < (2 * N) + 1; j++) {
				if (j % 2 == 0) {
					if (s[i + j] != 'I')
						break;
				}
				else {
					if (s[i + j] != 'O')
						break;
				}
				if (j == (2 * N))
					ans++;
			}
		}
	}
	
	cout << ans;
}