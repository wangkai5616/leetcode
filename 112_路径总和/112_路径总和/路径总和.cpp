#include<iostream>
#include<vector>
using namespace std;
/*
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ
�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool hasPathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return false;
	//������Ҷ�ӽڵ�
	if (root->left == nullptr && root->right == nullptr)
		return root->val == sum;
	return hasPathSum(root->left, sum - root->val) 
		|| hasPathSum(root->right, sum - root->val);
}
int main(void)
{
	system("pause");
	return 0;
}