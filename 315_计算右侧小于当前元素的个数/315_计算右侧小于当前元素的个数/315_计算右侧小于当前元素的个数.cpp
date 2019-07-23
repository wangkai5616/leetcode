#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int val, smaller;
	Node *left, *right;
	Node(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
};
int insert(Node *&root, int val)
{
	if (root == nullptr)
	{
		root = new Node(val, 0);
		return 0;
	}
	else if (val < root->val)
	{
		root->smaller++;
		return insert(root->left, val);
	}
	else
		return insert(root->right, val) + root->smaller 
		+ (root->val < val ? 1 : 0);
}
vector<int> countSmaller(vector<int>& nums)
{
	vector<int> res(nums.size());
	Node *root = nullptr;
	for (int i = nums.size() - 1; i >= 0; --i)
		res[i] = insert(root, nums[i]);
	return res;
}
int main(void)
{
	vector<int> nums = { 5,2,6,1 };
	vector<int> result = countSmaller(nums);
	for (auto a : result)
		cout << a << "	";
	cout << endl;
	system("pause");
	return 0;
}