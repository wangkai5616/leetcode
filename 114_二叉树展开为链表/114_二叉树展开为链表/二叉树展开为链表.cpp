#include<iostream>
#include<vector>
using namespace std;
/*
����һ����������ԭ�ؽ���չ��Ϊ����
���磬����������
1
/ \
2   5
/ \   \
3   4   6
����չ��Ϊ��
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

	//�����ϲ������������γɵ�������뵽root��root->right֮��
	TreeNode *node = root->left;
	//Ѱ������������һ���ڵ�
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