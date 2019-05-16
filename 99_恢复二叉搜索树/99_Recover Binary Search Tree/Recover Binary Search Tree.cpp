#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
�����������е������ڵ㱻����ؽ�����
���ڲ��ı���ṹ������£��ָ��������
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
O(n) �ռ�Ľⷨ�ǣ���һ��ָ�����飬������������ڵ�ָ�����δ�
�ŵ������Ȼ��Ѱ�����������λ�ã��ȴ�ǰ�����ҵ�һ�������λ�ã�
Ȼ��Ӻ���ǰ�ҵڶ��������λ�ã�����������ָ���ֵ��
*/
void recoverTree(TreeNode* root)
{
	int min = INT_MIN;
	vector<TreeNode*> v;
	if (root != NULL)
	{
		stack<TreeNode*> s1;
		while (s1.empty() == 0 || root != NULL)
		{
			if (root != NULL)
			{
				s1.push(root);
				root = root->left;
			}
			else
			{
				root = s1.top();
				v.push_back(root);				
				s1.pop();
				root = root->right;
			}
		}
	}
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	for (int i = 0; i < v.size(); ++i)
	{
		if (i + 1 != v.size() && v[i]->val >= v[i + 1]->val)
		{
			first = v[i];
			break;
		}
	}
	for (int i = v.size() - 1; i >= 0; --i)
	{
		if (i - 1 >= 0 && v[i]->val <= v[i - 1]->val)
		{
			second = v[i];
			break;
		}
	}
	swap(first->val, second->val);
}
int main(void)
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(2);
	node1->left = node2;
	node1->right = node3;
	recoverTree(node1);
}