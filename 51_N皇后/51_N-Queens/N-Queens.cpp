#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
*/
//˼·�������������
void dfs(vector<int> &C, vector<vector<string>> &result, int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag);
vector<vector<string>> solveNQueens(int n)
{
	vector<int> columns(n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ��
	//���������Խ��ߺ͸��Խ��ߵĻ��Ϳ�С�ʼǱ�������˵��
	vector<int> main_diag(2 * n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ���Խ���
	vector<int> anti_diag(2 * n, 0);//��ʾ�Ѿ����õĻʺ�ռ������Щ���Խ���
	vector<vector<string>> result;
	vector<int> C(n, 0);//��ʾ��i�лʺ����ڵ��б��
	dfs(C, result, 0, n, columns, main_diag, anti_diag);
	return result;
}
void dfs(vector<int> &C, vector<vector<string>> &result, int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag)
{
	if (row == n)
	{
		vector<string> solution;
		for (int i = 0; i < n; ++i)
		{
			string s(n, '.');
			for (int j = 0; j < n; ++j)
				if (j == C[i])
					s[j] = 'Q';
			solution.push_back(s);//�ӵ���һ��
		}
		result.push_back(solution);//�ӵ���������ά����
		return;
	}

	//�����row�������У������i�����У�����ĳһ�У�һ��һ�еĽ��г���
	for (int i = 0; i < n; ++i)
	{
		//��һ�У��Լ���Ԫ�ص����Խ��ߡ����Խ����ϲ�����Ԫ�ش���
		bool ok = columns[i] == 0 && main_diag[row + i] == 0 &&
			anti_diag[row - i + n] == 0;
		//���Ϸ���������һ��
		if (!ok)
			continue;
		//Ŀǰ�Ϸ���������һ�е�Ѱ��
		C[row] = i;
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 1;
		dfs(C, result, row + 1, n, columns, main_diag, anti_diag);
		//��������,������һ�гɹ���񣬽�����һ�е��ж�
		C[row] = 0;
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 0;
	}
}
int main(void)
{
	system("pause");
	return 0;
}