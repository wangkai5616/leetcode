#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string largestNumber(vector<int>& nums)
{
	if (nums.size() == 0)
		return "";
	vector<string> vs;
	for (auto num : nums)
		vs.push_back(to_string(num));
	sort(vs.begin(), vs.end(), [](string a, string b) {return a + b > b + a; });
	string result;
	for (auto s : vs)
		result += s;
	return result[0] == '0' ? "0" : result;
}
int main(void)
{
	vector<int> v = { 1,2,3};
	cout << largestNumber(v) << endl;
	system("pause");
	return 0;
}