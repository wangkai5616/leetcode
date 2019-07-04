#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int dfs(TreeNode *root, int &maxLength)
{
	if (root == nullptr)
		return 0;
	int leftLength = dfs(root->left, maxLength) + 1;
	int rightLength = dfs(root->right, maxLength) + 1;
	maxLength = max(maxLength, leftLength + rightLength);
	return leftLength > rightLength ? leftLength : rightLength;
}
int diameterOfBinaryTree(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	int maxLength = 0;
	dfs(root, maxLength);
	return maxLength;
}