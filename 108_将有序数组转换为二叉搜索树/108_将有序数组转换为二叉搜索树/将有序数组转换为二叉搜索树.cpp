#include<iostream>
#include<vector>
using namespace std;
/*
��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
ʾ��:
������������: [-10,-3,0,5,9],
һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������
0
/ \
-3   9
/   /
-10  5
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return sortedArrayToBSTCore(nums.begin(), nums.end());
}
//���ַ�
TreeNode* sortedArrayToBSTCore(vector<int>::iterator it1,
	vector<int>::iterator it2)
{
	int length = distance(it1, it2);
	if (length <= 0)
		return nullptr;
	auto mid = it1 + length / 2;
	TreeNode *root = new TreeNode(*mid);
	root->left = sortedArrayToBSTCore(it1, mid);
	root->right = sortedArrayToBSTCore(mid + 1, it2);
	return root;
}
int main(void)
{
	system("pause");
	return 0;
}