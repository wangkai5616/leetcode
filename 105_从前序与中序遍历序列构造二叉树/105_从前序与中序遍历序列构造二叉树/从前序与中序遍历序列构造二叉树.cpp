#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
你可以假设树中没有重复的元素。
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
	int pre_left, int pre_right, int in_left, int in_right)
{
	if (pre_left > pre_right || in_left > in_right)
		return nullptr;
	int rootValue = preorder[pre_left];//前序遍历中的第一个节点就是当前树的根结点
	TreeNode *root = new TreeNode(rootValue);
	//在中序遍历中找到当前根结点
	int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootValue));
	//算出左子树和右子树的节点个数
	int left_num = index - in_left;
	int right_num = in_right - index;
	//递归构建左右子树
	root->left = buildTree(preorder, inorder, pre_left + 1, pre_left + left_num, in_left, index - 1);
	root->right = buildTree(preorder, inorder, pre_left + left_num + 1, pre_right, index + 1, in_right);
	return root;
}
int main(void)
{
	system("pause");
	return 0;
}