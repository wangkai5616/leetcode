#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//����һ���������������������� ������
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//�ݹ��
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	inorderTraversalCore(root, result);
	return result;
}
void inorderTraversalCore(TreeNode* root, vector<int> &v)
{
	if (root == nullptr)
		return;
	inorderTraversalCore(root->left, v);
	v.push_back(root->val);
	inorderTraversalCore(root->right, v);
}
//�ǵݹ��
vector<int> inorderTraversal2(TreeNode* root)
{
	vector<int> result;
	if (root != nullptr)
	{
		stack<TreeNode*>st;
		while (!st.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				st.push(root);
				root = root->left;
			}
			else
			{
				root = st.top();
				result.push_back(root->val);
				st.pop();
				root = root->right;
			}
		}
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;                                              
}