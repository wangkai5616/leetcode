#include<iostream>
#include<vector>
using namespace std;
/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶
子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
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
	//必须是叶子节点
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