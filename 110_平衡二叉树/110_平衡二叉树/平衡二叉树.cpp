#include<iostream>
#include<algorithm>
using namespace std;
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isBalanced(TreeNode* root)
{
	int depth = 0;
	return isBalancedCore(root, &depth);
}
bool isBalancedCore(TreeNode* root, int *depth)
{
	if (root == nullptr)
	{
		*depth = 0;
		return true;
	}
	int left_depth = 0, right_depth = 0;
	if (isBalancedCore(root->left, &left_depth) &&
		isBalancedCore(root->right, &right_depth))
	{
		int distance = abs(left_depth-right_depth);
		if (distance <= 1)
		{
			*depth = max(left_depth, right_depth) + 1;
			return true;
		}
	}
	return false;
}

int main(void)
{
	system("pause");
	return 0;
}