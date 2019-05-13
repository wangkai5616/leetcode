#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/
//����ջ��ʱ�临�Ӷ�O(n)
int largestRectangleArea(vector<int>& heights)
{
	int result = 0;
	stack<int> st;
	/*
	����ĵط���������һλ0����֤ջ�е�Ԫ�ض��ᱻ���㣬
	�����Ͳ�����ȥ�ж�ջ���Ƿ���û������Ԫ����
	*/
	heights.push_back(0);
	for (int i = 0; i < heights.size(); ++i)
	{
		while (!st.empty() && heights[st.top()] >= heights[i])
		{
			int cur = st.top(); st.pop();
			//ע�⣺����ջ�е����һ��Ԫ�صĿ��Ϊ����heights�ĳ���
			result = max(result, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
		}
		//��ǰ�ڵ�϶��ᱻ���뵥��ջ�У�֮ǰ��Ԫ������ȵ�ǰ�ڵ��ֵ
		//Ҫ�󣬽��е�������
		st.push(i);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}