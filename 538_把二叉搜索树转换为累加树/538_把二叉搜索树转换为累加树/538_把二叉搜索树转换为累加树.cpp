#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
思路：其实就是中序遍历，然后每一个数都加上后面的所有数之和，那么这不就是递归
吗，所以先计算右面的，再计算左面的
也就是按照右中左原则进行递归
*/
void dfs(TreeNode *node, int &sum)
{
	if (node == nullptr)
		return;
	dfs(node->right, sum);
	node->val += sum;
	sum = node->val;
	dfs(node->left, sum);
}
TreeNode* convertBST(TreeNode* root) 
{
	int sum = 0;
	dfs(root, sum);
	return root;
}
