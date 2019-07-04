#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
˼·����ʵ�������������Ȼ��ÿһ���������Ϻ����������֮�ͣ���ô�ⲻ���ǵݹ�
�������ȼ�������ģ��ټ��������
Ҳ���ǰ���������ԭ����еݹ�
*/
void dfs(TreeNode *node, int &sum)
{
	if (node == nullptr)
		return;
	dfs(node->right, sum);
	node->val += sum;
	sum = node->val;
	dfs(node->left, sum);
}
TreeNode* convertBST(TreeNode* root) 
{
	int sum = 0;
	dfs(root, sum);
	return root;
}
