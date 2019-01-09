#include<iostream>
using namespace std;
/*
����һ����������������Ƿ��Ǿ���ԳƵġ�
���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

1
/ \
2   2
/ \ / \
3  4 4  3
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSymmetricCore(TreeNode* rootA, TreeNode* rootB);
bool isSymmetric(TreeNode* root)
{
	return isSymmetricCore(root,root);
}
bool isSymmetricCore(TreeNode* rootA, TreeNode* rootB)
{
	if (rootA == nullptr && rootB == nullptr)
		return true;
	if (rootA == nullptr || rootB == nullptr)
		return false;
	if (rootA->val != rootB->val)
		return false;
	return isSymmetricCore(rootA->left, rootB->right)
		&& isSymmetricCore(rootA->right, rootB->left);
}

int main(void)
{
	system("pause");
	return 0;
}