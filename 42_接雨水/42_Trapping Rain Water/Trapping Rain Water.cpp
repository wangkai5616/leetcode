#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//时间复杂度O(n)，空间复杂度O(n)
int trap1(vector<int>& height)
{
	int size = height.size();
	int *max_left = new int[size];
	int *max_right = new int[size];

	//记录每个元素左边的最大值和右边的最大值
	for (int i = 1; i < size; ++i)
	{
		max_left[i] = max(max_left[i - 1], height[i - 1]);
		max_right[size - 1 - i] = max(max_right[size - i], height[size - i]);
	}
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		int heigh = min(max_left[i], max_right[i]);
		//每个柱子能否蓄水就是比较左部分和右部分最大值中的最小值和这个柱子的值
		if (heigh > height[i])
			sum += heigh - height[i];
	}
	delete[]max_left;
	delete[]max_right;
	return sum;
}
//时间复杂度O(n)，空间复杂度O(1)
int trap2(vector<int>& height)
{
	//最高的柱子，将数组分成两半
	int max = 0;
	for (int i = 0; i < height.size() - 1; ++i)
		if (height[i]>height[max])
			max = i;
	int water = 0;
	//左半部分
	for (int i = 0, peak = 0; i < max; ++i)
	{
		//某个点只有左边出现大于它的值的点，才能蓄水
		if (height[i] > peak)
			peak = height[i];
		else
			water += peak - height[i]; 
	}
	//右半部分
	for (int i = height.size() - 1, peak = 0; i > max; --i)
	{
		//某个点只有右边出现大于它的值的点，才能蓄水
		if (height[i] > peak)
			peak = height[i];
		else
			water += peak - height[i];
	}
	return water;
}
int main(void)
{
	vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int result = trap1(v);
	cout << result << endl;
	system("pause");
	return 0;
}