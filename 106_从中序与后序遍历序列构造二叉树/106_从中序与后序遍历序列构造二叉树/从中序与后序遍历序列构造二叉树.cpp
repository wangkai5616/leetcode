#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//根据一棵树的中序遍历与后序遍历构造二叉树。
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
	int in_left, int in_right, int post_left, int post_right)
{
	if (in_left > in_right || post_left > post_right)
		return nullptr;
	int rootValue = postorder[post_right];
	TreeNode *root = new TreeNode(rootValue);
	//在中序遍历中找到当前根结点
	int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootValue));
	//算出左右子树的节点个数
	int left_num = index - in_left;
	int right_num = in_right - index;
	//递归计算左右子树
	root->left = buildTree(inorder, postorder, in_left, index - 1, post_left, post_left + left_num - 1);
	root->right = buildTree(inorder, postorder, index + 1, in_right, post_left + left_num, post_right - 1);
	return root;
}
int main(void)
{
	system("pause");
	return 0;
}