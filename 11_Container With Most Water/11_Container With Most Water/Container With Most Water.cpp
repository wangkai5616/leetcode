#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
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