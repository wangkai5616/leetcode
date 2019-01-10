#include<iostream>
#include<algorithm>
using namespace std;
/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。
示例:
给定二叉树 [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
返回它的最小深度  2.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minDepth(TreeNode* root)
{
	return minDepthCore(root, false);
}
int minDepthCore(TreeNode* root, bool hasbrother)
{
	//检查是否有兄弟节点，如果有的话，设为最大值，因为不是叶结点
	if (root == nullptr)
		return hasbrother ? INT_MAX : 0;
	return 1 + min(minDepthCore(root->left, root->right != nullptr),
		minDepthCore(root->right, root->left != nullptr));
}
int main(void)
{
	system("pause");
	return 0;
}