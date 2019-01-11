#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
����һ�����������������ĺ��������
��ʹ�õݹ��㷨
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//˼·����ǰ�����ƣ��ȹ���ɸ����󣬷���ջ�У�Ȼ�������������
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> result;
	if (root == nullptr)
		return result;
	stack<TreeNode*> s;
	stack<int> reverse;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *node = s.top();
		reverse.push(node->val);
		s.pop();
		if (node->left != nullptr)
			s.push(node->left);
		if (node->right != nullptr)
			s.push(node->right);
	}
	while (!reverse.empty())
	{
		result.push_back(reverse.top());
		reverse.pop();
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}