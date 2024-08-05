#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string s, set;
		int num;

		cin >> s >> num >> set;

		deque<int> d;
		string s_temp = "";
		for (char c : set) {
			if (c == ',' || c == ']') {
				if (s_temp == "")
					continue;
				d.push_back(stoi(s_temp));
				s_temp = "";
			}
				
			if (c != '[' && c != ']' && c != ',')
				s_temp += c;
		}	

		bool isReverse = false;
		bool isError = false;
		for (char c : s) {
			if (c == 'R') {
				if (isReverse)
					isReverse = false;
				else
					isReverse = true;
			}
			else {
				if (d.empty()) {
					isError = true;
					cout << "error\n";
					break;
				}
				else if (!isReverse) 
					d.pop_front();
				else
					d.pop_back();
			}
		}
		if (!isError) {
			cout << "[";
			if (!isReverse) {
				for (int i = 0; i < d.size(); i++) {
					cout << d[i];
					if (i != d.size() - 1)
						cout << ",";
				}
			}
			else {
				for (int i = d.size() - 1; i >= 0; i--) {
					cout << d[i];
					if (i != 0)
						cout << ",";
				}
			}
			cout << "]\n";
		}		
	}

	return 0;
}