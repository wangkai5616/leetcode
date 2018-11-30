#include<iostream>
#include<vector>
using namespace std;
/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:
输入: 3
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
vector<TreeNode*> generateTreesCore(int start, int end);
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> result;
	if (n == 0)
		return result;
	else
		return generateTreesCore(1, n);
}
vector<TreeNode*> generateTreesCore(int start, int end)
{
	vector<TreeNode*> subTree;
	if (start > end)
	{
		subTree.push_back(nullptr);
		return subTree;
	}
	for (int k = start; k <= end; ++k)
	{
		vector<TreeNode*> leftTree = generateTreesCore(start, k - 1);
		vector<TreeNode*> rightTree = generateTreesCore(k + 1, end);
		for (auto i : leftTree)
		{
			for (auto j : rightTree)
			{
				TreeNode *node = new TreeNode(k);
				node->left = i;
				node->right = j;
				//存放的是当前这颗树的根结点
				subTree.push_back(node);
			}
		}
	}
	return subTree;
}
int main(void)
{
	system("pasue");
	return 0;
}