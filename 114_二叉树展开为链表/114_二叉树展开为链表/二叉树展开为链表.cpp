#include<iostream>
#include<vector>
using namespace std;
/*
给定一个二叉树，原地将它展开为链表。
例如，给定二叉树
1
/ \
2   5
/ \   \
3   4   6
将其展开为：
1
\
2
\
3
\
4
\
5
\
6
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void flatten(TreeNode* root)
{
	if (root == nullptr)
		return;
	flatten(root->left);
	flatten(root->right);
	if (root->left == nullptr)
		return;

	//三方合并，将左子树形成的链表插入到root和root->right之间
	TreeNode *node = root->left;
	//寻找左链表的最后一个节点
	while (node->right)
		node = node->right;
	node->right = root->right;
	root->right = root->left;
	root->left = nullptr;
}
int main(void)
{
	system("pause");
	return 0;
}