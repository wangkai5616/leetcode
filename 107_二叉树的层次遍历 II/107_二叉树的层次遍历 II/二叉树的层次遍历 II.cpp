#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����
����:
����������: [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
�������α��������
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
	//��next���б���current���е����Һ��ӽڵ㣬Ȼ�����������н���
	//�ظ�ִ���������
	queue<TreeNode*>current, next;
	vector<int> level;//ÿһ���Ԫ��
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
	//��102����˴˲��裬��תһ��
	reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}