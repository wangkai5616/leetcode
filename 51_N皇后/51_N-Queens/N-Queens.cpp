#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
*/
//思路：深度优先搜索
void dfs(vector<int> &C, vector<vector<string>> &result, int row, int n,
	vector<int> columns, vector<int> &main_diag, vector<int> &anti_diag);
vector<vector<string>> solveNQueens(int n)
{
	vector<int> columns(n, 0);//表示已经放置的皇后占据了哪些列
	//看不懂主对角线和副对角线的话就看小笔记本后面有说明
	vector<int> main_diag(2 * n, 0);//表示已经放置的皇后占据了哪些主对角线
	vector<int> anti_diag(2 * n, 0);//表示已经放置的皇后占据了哪些副对角线
	vector<vector<string>> result;
	vector<int> C(n, 0);//表示第i行皇后所在的列编号
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
			solution.push_back(s);//加的是一行
		}
		result.push_back(solution);//加的是整个二维数组
		return;
	}

	//上面的row控制了行，这里的i控制列，对于某一行，一列一列的进行尝试
	for (int i = 0; i < n; ++i)
	{
		//这一列，以及该元素的主对角线、副对角线上不能有元素存在
		bool ok = columns[i] == 0 && main_diag[row + i] == 0 &&
			anti_diag[row - i + n] == 0;
		//不合法，尝试下一列
		if (!ok)
			continue;
		//目前合法，进行下一行的寻找
		C[row] = i;
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 1;
		dfs(C, result, row + 1, n, columns, main_diag, anti_diag);
		//撤销动作,不论上一列成功与否，进行下一列的判断
		C[row] = 0;
		columns[i] = main_diag[row + i] = anti_diag[row - i + n] = 0;
	}
}
int main(void)
{
	system("pause");
	return 0;
}