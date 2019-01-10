#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����Լ�������û���ظ���Ԫ�ء�
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
	int rootValue = preorder[pre_left];//ǰ������еĵ�һ���ڵ���ǵ�ǰ���ĸ����
	TreeNode *root = new TreeNode(rootValue);
	//������������ҵ���ǰ�����
	int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), rootValue));
	//������������������Ľڵ����
	int left_num = index - in_left;
	int right_num = in_right - index;
	//�ݹ鹹����������
	root->left = buildTree(preorder, inorder, pre_left + 1, pre_left + left_num, in_left, index - 1);
	root->right = buildTree(preorder, inorder, pre_left + left_num + 1, pre_right, index + 1, in_right);
	return root;
}
int main(void)
{
	system("pause");
	return 0;
}