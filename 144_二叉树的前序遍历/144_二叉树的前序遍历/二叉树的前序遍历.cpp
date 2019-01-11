#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
����һ������������������ ǰ�� ������
��ʹ�õݹ��㷨
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	if (root == nullptr)
		return result;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *node = s.top();
		result.push_back(node->val);
		s.pop();
		if (node->right != nullptr)
			s.push(node->right);
		if (node->left != nullptr)
			s.push(node->left);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}