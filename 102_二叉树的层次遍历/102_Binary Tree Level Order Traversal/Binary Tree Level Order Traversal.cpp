#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
����������: [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
�������α��������
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
	//��next���б���current���е����Һ��ӽڵ㣬Ȼ�����������н���
	//�ظ�ִ���������
	queue<TreeNode*> q;
	vector<int> level;//ÿһ���Ԫ��
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