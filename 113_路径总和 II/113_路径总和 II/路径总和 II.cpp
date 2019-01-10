#include<iostream>
#include<vector>
using namespace std;
/*
����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> result;
	vector<int> current;
	pathSumCore(root, sum, current, result);
	return result;
}
void pathSumCore(TreeNode* root, int gap, vector<int> &current,
	vector<vector<int>> &result)
{
	if (root == nullptr)
		return;
	
	if (root->left == nullptr && root->right == nullptr && root->val == gap)
	{
		current.push_back(root->val);
		result.push_back(current);
		current.pop_back();
		return;
	}
	current.push_back(root->val);
	pathSumCore(root->left, gap - root->val, current, result);
	pathSumCore(root->right, gap - root->val, current, result);
	current.pop_back();
}
int main(void)
{
	system("pause");
	return 0;
}