#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> dfs(TreeNode *root)
{
	if (!root)
		return vector<int>(2, 0);
	vector<int> left = dfs(root->left);
	vector<int> right = dfs(root->right);
	vector<int> result(2, 0);
	result[0] = max(left[0], left[1]) + max(right[0], right[1]);
	result[1] = max(left[0], right[0]) + root->val;
	return result;
}
int robCore(TreeNode* root, int &maxValue)
{
	vector<int> result = dfs(root);
	return max(result[0], result[1]);
}
int rob(TreeNode *root)
{
	if (root == nullptr)
		return 0;
}