#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
int trap1(vector<int>& height)
{
	int size = height.size();
	int *max_left = new int[size];
	int *max_right = new int[size];

	//��¼ÿ��Ԫ����ߵ����ֵ���ұߵ����ֵ
	for (int i = 1; i < size; ++i)
	{
		max_left[i] = max(max_left[i - 1], height[i - 1]);
		max_right[size - 1 - i] = max(max_right[size - i], height[size - i]);
	}
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		int heigh = min(max_left[i], max_right[i]);
		//ÿ�������ܷ���ˮ���ǱȽ��󲿷ֺ��Ҳ������ֵ�е���Сֵ��������ӵ�ֵ
		if (heigh > height[i])
			sum += heigh - height[i];
	}
	delete[]max_left;
	delete[]max_right;
	return sum;
}
//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
int trap2(vector<int>& height)
{
	//��ߵ����ӣ�������ֳ�����
	int max = 0;
	for (int i = 0; i < height.size() - 1; ++i)
		if (height[i]>height[max])
			max = i;
	int water = 0;
	//��벿��
	for (int i = 0, peak = 0; i < max; ++i)
	{
		//ĳ����ֻ����߳��ִ�������ֵ�ĵ㣬������ˮ
		if (height[i] > peak)
			peak = height[i];
		else
			water += peak - height[i]; 
	}
	//�Ұ벿��
	for (int i = height.size() - 1, peak = 0; i > max; --i)
	{
		//ĳ����ֻ���ұ߳��ִ�������ֵ�ĵ㣬������ˮ
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