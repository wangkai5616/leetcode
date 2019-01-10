#include<iostream>
#include<vector>
using namespace std;
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> result;
	vector<int> current;
	pathSumCore(root, sum, current, result);
	return result;
}
void pathSumCore(TreeNode* root, int gap, vector<int> &current,
	vector<vector<int>> &result)
{
	if (root == nullptr)
		return;
	
	if (root->left == nullptr && root->right == nullptr && root->val == gap)
	{
		current.push_back(root->val);
		result.push_back(current);
		current.pop_back();
		return;
	}
	current.push_back(root->val);
	pathSumCore(root->left, gap - root->val, current, result);
	pathSumCore(root->right, gap - root->val, current, result);
	current.pop_back();
}
int main(void)
{
	system("pause");
	return 0;
}