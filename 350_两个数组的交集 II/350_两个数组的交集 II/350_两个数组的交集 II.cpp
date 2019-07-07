#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> record;
	vector<int> result;
	for (int i = 0; i < nums1.size(); ++i)
	{	
		auto iter = record.find(nums1[i]);
		if(iter!=record.end())
			++record[nums1[i]];
		else
			record[nums1[i]] = 1;
	}
	for (int i = 0; i < nums2.size(); ++i)
	{
		auto iter = record.find(nums2[i]);
		if (iter != record.end() && iter->second>0)
		{
			result.push_back(nums2[i]);
			--record[nums2[i]];
		}
	}
	return result;
}
int main(void)
{
	vector<int> nums1 = { 1,2,3 };
	vector<int> nums2 = { 2,4 ,1};
	vector<int> result = intersect(nums1, nums2);
	for (auto a : result)
		cout << a << "	";
	cout << endl;
	system("pause");
	return 0;
}