#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>& s) 
{
	int left = 0, right = s.size() - 1;
	while (left < right) {
		swap(s[left++], s[right--]);
	}
	return;
}