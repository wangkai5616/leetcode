#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int dfs(TreeNode *root, int sum);
//时间复杂度 O(n)，空间复杂度 O(logn)
int sumNumbers(TreeNode* root)
{
	return dfs(root, 0);
}
int dfs(TreeNode *root, int sum)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return sum * 10 + root->val;
	return dfs(root->left, sum * 10 + root->val) +
		dfs(root->right, sum * 10 + root->val);
}
int main(void)
{
	system("pasue");
	return 0;
}