#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
给定二叉树: [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
返回其层次遍历结果：
[[3],[9,20],[15,7]]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr)
		return result;
	//用next队列保存current队列的左右孩子节点，然后将这两个队列交换
	//重复执行这个步骤
	queue<TreeNode*>current, next;
	vector<int> level;//每一层的元素
	current.push(root);
	while (!current.empty())
	{
		while (!current.empty())
		{
			TreeNode *node = current.front();
			current.pop();
			level.push_back(node->val);
			if (node->left != nullptr)
				next.push(node->left);
			if (node->right != nullptr)
				next.push(node->right);
		}
		result.push_back(level);
		level.clear();
		swap(next, current);
	}
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}