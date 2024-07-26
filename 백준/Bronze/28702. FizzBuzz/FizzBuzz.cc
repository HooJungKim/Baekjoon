#include<iostream>
#include<string>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s[3];

	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}

	int ans = 0;

	for (int i = 0; i < 3; i++) {
		if (s[i] != "Fizz" && s[i] != "Buzz" && s[i] != "FizzBuzz") {
			ans = stoi(s[i]) + (3 - i);
			break;
		}
	}

	if (ans % 3 == 0 && ans % 5 != 0)
		cout << "Fizz";
	else if (ans % 3 != 0 && ans % 5 == 0)
		cout << "Buzz";
	else if (ans % 3 == 0 && ans % 5 == 0)
		cout << "FizzBuzz";
	else cout << ans;
	
	return 0;
}