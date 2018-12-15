#include<iostream>
#include<stack>
using namespace std;
/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
//��������������������ǵ�����
bool isValidBST(TreeNode* root)
{
	int minValue = INT_MIN;
	if (root != nullptr)
	{
		stack<TreeNode*> st;
		while (!st.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				if (root->val == INT_MIN)
					root->val = INT_MIN + 1;
				st.push(root);
				root = root->left;
			}
			else
			{
				root = st.top();
				if (root->val <= minValue)
					return false;
				minValue = root->val;
				st.pop();
				root = root->right;
			}
		}
	}
	return true;
}
int main(void)
{
	system("pause");
	return 0;
}