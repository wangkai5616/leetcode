#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
����һ����������������ڵ�ֵ�ľ���β�α�����
�����ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻����У���
���磺
���������� [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
���ؾ���β�α������£�
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
	//��k=1ʱ����������ջ����k=-1ʱ������������ջ
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