#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
例如:
给定二叉树: [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
返回其层次遍历结果：
[[15,7],[9,20],[3]]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == nullptr)
		return result;
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
	reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	map<char, int> m;
	char c = 'k';
	m.insert(make_pair(c, 2));
	system("pause");
	return 0;
}