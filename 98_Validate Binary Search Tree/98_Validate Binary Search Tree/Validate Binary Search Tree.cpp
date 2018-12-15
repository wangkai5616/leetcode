#include<iostream>
#include<stack>
using namespace std;
/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
//二叉搜索树的中序遍历是递增的
bool isValidBST(TreeNode* root)
{
	int minValue = INT_MIN;
	if (root != nullptr)
	{
		stack<TreeNode*> st;
		while (!st.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				if (root->val == INT_MIN)
					root->val = INT_MIN + 1;
				st.push(root);
				root = root->left;
			}
			else
			{
				root = st.top();
				if (root->val <= minValue)
					return false;
				minValue = root->val;
				st.pop();
				root = root->right;
			}
		}
	}
	return true;
}
int main(void)
{
	system("pause");
	return 0;
}