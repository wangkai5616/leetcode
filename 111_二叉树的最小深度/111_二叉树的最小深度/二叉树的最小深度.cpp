#include<iostream>
#include<algorithm>
using namespace std;
/*
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ��:
���������� [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
����������С���  2.
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
	//����Ƿ����ֵܽڵ㣬����еĻ�����Ϊ���ֵ����Ϊ����Ҷ���
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