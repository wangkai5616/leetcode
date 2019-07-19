#include<iostream>
#include<stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};
class BSTInterator
{
public:
	BSTInterator(TreeNode *root)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
	}
	bool hasNext()
	{
		return !s.empty();
	}
	int next()
	{
		TreeNode *node = s.top();
		s.pop();
		int res = node->val;
		if (node->right)
		{
			node = node->right;
			while (node)
			{
				s.push(node);
				node = node->left;
			}
		}
	}
private:
	stack<TreeNode *> s;
};