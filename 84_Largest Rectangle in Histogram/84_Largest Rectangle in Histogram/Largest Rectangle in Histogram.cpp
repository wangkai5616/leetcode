#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
//单调栈，时间复杂度O(n)
int largestRectangleArea(vector<int>& heights)
{
	int result = 0;
	stack<int> st;
	/*
	巧妙的地方，故意多加一位0，保证栈中的元素都会被计算，
	这样就不用再去判断栈中是否还有没出来的元素了
	*/
	heights.push_back(0);
	for (int i = 0; i < heights.size(); ++i)
	{
		while (!st.empty() && heights[st.top()] >= heights[i])
		{
			int cur = st.top(); st.pop();
			//注意：单调栈中的最后一个元素的宽度为整个heights的长度
			result = max(result, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
		}
		//当前节点肯定会被加入单调栈中，之前的元素如果比当前节点的值
		//要大，进行弹出结算
		st.push(i);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}