#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> restoreIpAddresses(string s)
{
	vector<string> result;
	string ip;//存放中间结果
	dfs(s, 0, 0, ip, result);
	return result;
}
/*
s是原始数据，start是指从s的哪里开始，step是指ip地址是由4部分
组成
*/
void dfs(string s, int start, int step, string ip, vector<string> &result)
{
	if (start == s.size() && step == 4)
	{
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}
	//剩下的太长了
	if (s.size() - start > (4 - step) * 3)
		return;
	//剩下的太短了
	if (s.size() - start < (4 - step))
		return;
	int num = 0;
	for (int i = start; i < start + 3; ++i)
	{
		num = num * 10 + (s[i] - '0');
		if (num <= 255)
		{
			ip += s[i];
			dfs(s, i + 1, step + 1, ip + '.', result);
		}
		//比如：010010,可以是0.10.0.10，但不能是01.0.0.10
		if (num == 0)
			break;
	}
}
int main(void)
{
	system("pause");
	return 0;
}