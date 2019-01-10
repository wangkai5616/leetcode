#include<iostream>
using namespace std;
/*
给定完美二叉树，

1
/  \
2    3
/ \  / \
4  5  6  7
调用你的函数后，该完美二叉树变为：

1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root)
{
	connectCore(root, nullptr);
}
void connectCore(TreeLinkNode *root, TreeLinkNode *brother)
{
	if (root == nullptr)
		return;
	else
		root->next = brother;
	//解决root的左孩子的next指针
	connectCore(root->left, root->right);
	//解决root的右孩子的next指针
	if (brother)
		connectCore(root->right, brother->left);
	else
		connectCore(root->right, nullptr);
}
int main(void)
{
	system("pause");
	return 0;
}