#include<iostream>
#include<vector>
using namespace std;
/*
����ÿ������nums[i]��������Ӧ��nums[nums[i] - 1]�����������Ǿ͸�
ֵΪ���෴��������Ѿ��Ǹ����ˣ��Ͳ����ˣ���ô�������ֻҪ�����µ���
����Ӧ��λ�ü�����res�м��ɡ�
*/
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		int idx = abs(nums[i]) - 1;
		nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
	}
	cout << endl;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0) {
			res.push_back(i + 1);
		}
	}
	return res;
}
int main(void)
{
	vector<int> v = { 4,3,2,7,8,2,3,1 };
	vector<int> result=findDisappearedNumbers(v);
	for (auto a : result)
		cout << a << "	";
	cout << endl;
	system("pause");
	return 0;
}