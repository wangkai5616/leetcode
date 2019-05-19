#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
����: [100, 4, 200, 1, 3, 2]
���: 4
����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
*/

/*
˼·�������������Ԫ��������ģ���Ҫ�� O(n)������Ҫ�뵽�ù�ϣ����һ����ϣ�� 
unordered_map<int, bool> used ��¼ÿ��Ԫ���Ƿ�ʹ�ã���ÿ��Ԫ�أ�
�Ը�Ԫ��Ϊ���ģ����������ţ�ֱ��������Ϊֹ����¼����ĳ�
*/

// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
int longestConsecutive(vector<int>& nums)
{
	unordered_map<int, bool> map;
	for (auto i : nums)
		map.insert(pair<int,bool>(i, false));
	int result = 0;
	for (auto i : nums)
	{
		//�Ѿ������i�ˣ���ʼ��һ��
		if (map[i] == true)
			continue;
		int length = 1;
		map[i] = true;
		//���iǰ���Ƿ�������Ԫ�ش���
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
		//���i�����Ƿ�������Ԫ�ش���
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