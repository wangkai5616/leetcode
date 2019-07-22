#include<iostream>
#include<unordered_map>
using namespace std;
// ±º‰∏¥‘”∂»O(n^2)
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	int result = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
			++m[A[i] + B[j]];
	}
	for (int i = 0; i < C.size(); ++i)
	{
		for (int j = 0; j < D.size(); ++j)
		{
			int target = -1 * (C[i] + D[j]);
			result += m[target];
		}
	}
	return result;
}