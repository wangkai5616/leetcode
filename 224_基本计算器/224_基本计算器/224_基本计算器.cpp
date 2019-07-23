#include<iostream>
#include<stack>
using namespace std;
int calculate(string s) 
{
	int res = 0, num = 0, sign = 1, n = s.size();
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (c >= '0' && c <= '9') {
			num = 10 * num + (c - '0');
		}
		else if (c == '(') {
			int j = i, cnt = 0;
			for (; i < n; ++i) {
				if (s[i] == '(') ++cnt;
				if (s[i] == ')') --cnt;
				if (cnt == 0) break;
			}
			num = calculate(s.substr(j + 1, i - j - 1));
		}
		if (c == '+' || c == '-' || i == n - 1) {
			res += sign * num;
			num = 0;
			sign = (c == '+') ? 1 : -1;
		}
	}
	return res;
}
int main(void)
{
	string s = "1+2-3+5";
	cout << calculate(s) << endl;
	system("pause");
	return 0;
}