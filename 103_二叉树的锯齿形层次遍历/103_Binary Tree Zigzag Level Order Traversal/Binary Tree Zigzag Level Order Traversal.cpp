#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
返回锯齿形层次遍历如下：
[[3],[20,9],[15,7]]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr)
		return result;
	stack<TreeNode*> current, next;
	vector<int> level;
	current.push(root);
	//当k=1时，从左到右入栈，当k=-1时，从右向左入栈
	int k = 1;
	while (!current.empty())
	{
		while (!current.empty())
		{
			TreeNode *node = current.top();
			level.push_back(node->val);
			current.pop();
			if (k == 1)
			{
				if (node->left != nullptr)
					next.push(node->left);
				if (node->right != nullptr)
					next.push(node->right);
			}
			else
			{
				if (node->right != nullptr)
					next.push(node->right);
				if (node->left != nullptr)
					next.push(node->left);
			}
		}
		result.push_back(level);
		level.clear();
		swap(current, next);
		k = -k;
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}