#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
给定一个二叉树，返回它的后序遍历。
不使用递归算法
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//思路：和前序类似，先构造成根右左，放入栈中，然后输出到数组中
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