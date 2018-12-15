#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
/*
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	if (p == nullptr && q != nullptr || p != nullptr && q == nullptr)
		return false;
	if (p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	return false;
}
int main(void)
{
	system("pause");
	return 0;
}