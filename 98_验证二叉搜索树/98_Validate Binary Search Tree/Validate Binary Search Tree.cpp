#include<iostream>
#include<stack>
using namespace std;
/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
//��������������������ǵ�����
bool isValidBST(TreeNode *root) 
{
	return isValidBST(root, LONG_MIN, LONG_MAX);
}
bool isValidBST(TreeNode *root, long mn, long mx) 
{
	if (!root) return true;
	if (root->val <= mn || root->val >= mx) return false;
	return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
}
int main(void)
{
	system("pause");
	return 0;
}