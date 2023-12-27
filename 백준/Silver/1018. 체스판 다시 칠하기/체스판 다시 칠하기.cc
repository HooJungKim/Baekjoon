#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char BW[8][8] = { {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
			      {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'} };

char WB[8][8] = { {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'},
				  {'W','B','W','B','W','B','W','B'},
				  {'B','W','B','W','B','W','B','W'} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> v(N, vector<char>(M));
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++) {
			v[i][j]=s[j];
		}
	}

	
	int ans = 0;

	for (int a = 0; a <= N-8; a++) {
		for (int b = 0; b <= M-8; b++) {
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (v[i+a][j+b] != BW[i][j]) cnt1++;
					if (v[i+a][j+b] != WB[i][j]) cnt2++;
				}
			}
			if (ans > min(cnt1, cnt2)|| (a == 0 && b == 0)) ans = min(cnt1, cnt2);
		}
	}

	cout << ans;
}