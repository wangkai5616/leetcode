#include<iostream>
#include<algorithm>
using namespace std;
/*
����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ����
���������� [3,9,20,null,null,15,7]��
3
/ \
9  20
/  \
15   7
�������������� 3 ��
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return (l > r) ? l + 1 : r + 1;
}

int main(void)
{
	system("pause");
	return 0;
}