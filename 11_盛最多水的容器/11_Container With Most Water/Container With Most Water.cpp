#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/
int maxArea(vector<int>& height)
{
	int left = 0, right = height.size() - 1;
	int maxArea = 0;
	while (left < right)
	{
		maxArea = max(maxArea, min(height[left], height[right])
			*(right - left));
		if (height[left] < height[right])
			left++;
		else
			right--;
	}
	return maxArea;
}

int main(void)
{
	vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	int result = maxArea(v);
	cout << result << endl;
	system("pause");
	return 0;
}