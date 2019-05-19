#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

/*
思路：由于序列里的元素是无序的，又要求 O(n)，首先要想到用哈希表。用一个哈希表 
unordered_map<int, bool> used 记录每个元素是否使用，对每个元素，
以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长
*/

// 时间复杂度 O(n)，空间复杂度 O(n)
int longestConsecutive(vector<int>& nums)
{
	unordered_map<int, bool> map;
	for (auto i : nums)
		map.insert(pair<int,bool>(i, false));
	int result = 0;
	for (auto i : nums)
	{
		//已经计算过i了，开始下一次
		if (map[i] == true)
			continue;
		int length = 1;
		map[i] = true;
		//检查i前面是否有相邻元素存在
		for (int j = i + 1; ; ++j)
		{
			if (map.find(j) != map.end())
			{
				map[j] = true;
				++length;
			}
			else
				break;
		}
		//检查i后面是否有相邻元素存在
		for (int j = i - 1; ; --j)
		{
			if (map.find(j) != map.end())
			{
				map[j] = true;
				++length;
			}
			else
				break;
		}
		result = max(result, length);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}