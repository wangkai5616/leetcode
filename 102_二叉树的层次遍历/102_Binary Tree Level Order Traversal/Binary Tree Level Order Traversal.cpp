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
	queue<TreeNode*> q;
	vector<int> level;//每一层的元素
	q.push(root);
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			TreeNode *node = q.front();
			q.pop();
			level.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		result.push_back(level);
		level.clear();
	}
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}