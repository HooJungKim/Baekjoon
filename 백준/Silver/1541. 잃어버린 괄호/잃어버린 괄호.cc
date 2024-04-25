#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	vector<int> nums;
	string num;
	int temp = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			temp += stoi(num);
			num = "";
			continue;
		}
		if (s[i] == '-') {
			temp += stoi(num);
			nums.push_back(temp);
			temp = 0;
			num = "";
			continue;
		}
		num += s[i];
		if (i == s.size() - 1) {
			temp += stoi(num);
			nums.push_back(temp);
		}
	}

	int answer = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		answer -= nums[i];
	}
	cout << answer;
}