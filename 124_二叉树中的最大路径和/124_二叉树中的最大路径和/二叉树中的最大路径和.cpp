#include<iostream>
#include<algorithm>
using namespace std;
/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，
达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
输入: [-10,9,20,null,null,15,7]
-10
/ \
9  20
/  \
15   7
输出: 42
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxPathSum(TreeNode* root)
{
	int value = INT_MIN;
	int *max_sum = &value;
	dfs(root, max_sum);
	return *max_sum;
}
//dfs的返回值是给父亲用的，所以不可能出现左中右这种，
//只能是左中或者中右
int dfs(TreeNode* root, int *max_sum)
{
	if (root == nullptr)
		return 0;
	int l = dfs(root->left, max_sum);
	int r = dfs(root->right, max_sum);
	int sum = root->val;
	if (l > 0)
		sum += l;
	if (r > 0)
		sum += r;
	//记录最大值
	*max_sum = max(*max_sum, sum);
	//给父亲节点返回时，必须包含此节点，否则不就连不起来了
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}
int main(void)
{
	system("pause");
	return 0;
}