#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> m;
	priority_queue<pair<int, int>> q;
	vector<int> result;
	for (auto a : nums) ++m[a];
	for (auto b : m)
		q.push({ b.second,b.first });
	for (int i = 0; i < k; ++i)
	{
		result.push_back(q.top().second);
		q.pop();
	}
	return result;
}